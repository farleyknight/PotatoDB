#include "recovery/log_mgr.hpp"

LogMgr::LogMgr(DiskMgr& disk_mgr)
  : disk_mgr_(disk_mgr)
{}

// Performs a synchronous flush
//
// It blocks the thread it's been run on, and waits until the flush has been completed before resuming.
void LogMgr::sync_flush(bool force) {
  unique_lock<mutex> flush_latch(latch_);

  if (force) {
    flush_requested_ = false;
    // Wake up the flush thread
    flush_cv_.notify_one();
    // Block until flush completes
    append_cv_.wait(flush_latch, [&]() {
      return !flush_requested_;
    });
  } else {
    // When force == false, we are performing a group commit
    // But instead of forcing flush,
    // we wait for LOG_TIMEOUT or other operations to implicitly
    // trigger the flush operations
    append_cv_.wait(flush_latch);
  }
}

void LogMgr::run_flush_thread() {
  // NOTE: If we're being called, that means we want logging to
  // be enabled. This updates the flag if necessary
  if (!is_logging_enabled_) {
    is_logging_enabled_ = true;
  }

  // NOTE: If we're already run
  if (running_flush_thread_) {
    return;
  }
  running_flush_thread_ = true;

  flush_future_ = std::async([&]() {
    while (is_logging_enabled_) {
      // Acquire latch around all internal data structures
      unique_lock<mutex> flush_latch(latch_);
      // Wait for a request to flush is made..
      //
      // BUT..
      // If the wait is longer than LOG_TIMEOUT = 1 second
      // then we flush anyways
      flush_cv_.wait_for(flush_latch, log_timeout_, [&]() {
        return flush_requested_.load();
      });

      assert(flush_buffer_length_ == 0);
      if (log_buffer_.size() > 0) {
        std::swap(log_buffer_length_, flush_buffer_length_);
        log_buffer_.swap(flush_buffer_);

        logger->debug("Flushing to WAL");

        // TODO: Change `disk_mgr_` to a different object
        disk_mgr_.write_log(flush_buffer_);
        flush_buffer_length_ = 0;
      }
      flush_requested_ = false;
      append_cv_.notify_all();
    }
  });
}

void LogMgr::stop_flush_thread() {
  // Force a flush
  sync_flush(true);
  // Logging no longer enbled
  is_logging_enabled_ = false;
  // Join the flush thread
  if (flush_future_.valid()) {
    flush_future_.get();
  }
  // No longer running thread
  running_flush_thread_ = false;
  // Assert both log & flush buffers are empty
  assert(log_buffer_length_ == 0);
  assert(flush_buffer_length_ == 0);
}

void LogMgr::write_header(const LogRecord& log_record) {
  // Start with size
  logger->debug("LogMgr::write_header size = "
                + std::to_string(log_record.size()));
  log_buffer_.write_int32(log_buffer_length_, log_record.size());
  log_buffer_length_ += sizeof(int32_t);

  // Add LSN
  logger->debug("LogMgr::write_header LSN = "
                + std::to_string(log_record.lsn()));
  log_buffer_.write_lsn(log_buffer_length_, log_record.lsn());
  log_buffer_length_ += sizeof(lsn_t);

  // Add TXN id
  logger->debug("LogMgr::write_header TXN = "
                + std::to_string(log_record.txn_id()));
  log_buffer_.write_txn_id(log_buffer_length_, log_record.txn_id());
  log_buffer_length_ += sizeof(txn_id_t);

  // Add prev LSN
  logger->debug("LogMgr::write_header prev LSN = "
                + std::to_string(log_record.prev_lsn()));
  log_buffer_.write_lsn(log_buffer_length_, log_record.prev_lsn());
  log_buffer_length_ += sizeof(lsn_t);

  // Add record type
  auto log_record_type = static_cast<int32_t>(log_record.record_type());
  logger->debug("LogMgr::write_header log_record_type = "
                + std::to_string(log_record_type));
  log_buffer_.write_int32(log_buffer_length_, log_record_type);
  log_buffer_length_ += sizeof(int32_t);
}

void LogMgr::write_insert_record(const LogRecord& log_record) {
  // Write the RID
  log_buffer_.write_rid(log_buffer_length_, log_record.insert_rid());
  log_buffer_length_ += sizeof(RID);

  // Write the inserted Tuple
  log_buffer_.write_tuple(log_buffer_length_, log_record.insert_tuple());
  log_buffer_length_ += log_record.insert_tuple().size();
}

void LogMgr::write_delete_record(const LogRecord& log_record) {
  // Write the RID
  log_buffer_.write_rid(log_buffer_length_, log_record.delete_rid());
  log_buffer_length_ += sizeof(RID);

  // Write the deleted Tuple
  log_buffer_.write_tuple(log_buffer_length_, log_record.delete_tuple());
  log_buffer_length_ += log_record.delete_tuple().size();
}

void LogMgr::write_update_record(const LogRecord& log_record) {
  // Write the RID
  log_buffer_.write_rid(log_buffer_length_, log_record.update_rid());
  log_buffer_length_ += sizeof(RID);

  // Write the old tuple (before update)
  log_buffer_.write_tuple(log_buffer_length_, log_record.old_tuple());
  log_buffer_length_ += log_record.old_tuple().size();

  // Write the new tuple (after update)
  log_buffer_.write_tuple(log_buffer_length_, log_record.new_tuple());
  log_buffer_length_ += log_record.new_tuple().size();
}

void LogMgr::write_new_page_record(const LogRecord& log_record) {
  // Write prev page ID
  log_buffer_.write_page_id(log_buffer_length_, log_record.prev_page_id());
  log_buffer_length_ += sizeof(page_id_t);

  // Write new page ID
  log_buffer_.write_page_id(log_buffer_length_, log_record.page_id());
  log_buffer_length_ += sizeof(page_id_t);
}

lsn_t LogMgr::append(LogRecord& log_record) {
  unique_lock<mutex> append_latch(latch_);

  if (log_buffer_length_ + log_record.size() >= LOG_BUFFER_SIZE) {
    flush_requested_ = true;
    // NOTE: Wake up the flush thread
    flush_cv_.notify_one();
    // NOTE: Wait for the log buffer size to go down before
    // appending new records.
    append_cv_.wait(append_latch, [&] {
      return log_buffer_length_ + log_record.size() < LOG_BUFFER_SIZE;
    });
  }

  log_record.set_lsn(next_lsn_++);
  write_header(log_record);

  switch (log_record.record_type()) {
  case LogRecordType::INSERT:
    write_insert_record(log_record);
    break;
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE:
    write_delete_record(log_record);
    break;
  case LogRecordType::UPDATE:
    write_update_record(log_record);
    break;
  case LogRecordType::NEW_PAGE:
    write_new_page_record(log_record);
    break;
  default:
    // NO-OP
    break;
  }

  persisted_lsn_ = log_record.lsn();
  return persisted_lsn_;
}
