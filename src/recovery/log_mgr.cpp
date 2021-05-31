
#include "recovery/log_mgr.hpp"

LogMgr::LogMgr(const DiskMgr& disk_mgr)
  : disk_mgr_(disk_mgr)
{
  log_buffer_.resize(LOG_BUFFER_SIZE);
  flush_buffer_.resize(LOG_BUFFER_SIZE);
}

// Performs a synchronous flush
//
// It blocks the thread it's been run on, and waits until the flush has been completed before resuming.
void LogMgr::sync_flush(bool force) {
  std::lock_guard<std::mutex> flush_latch(latch_);

  if (force) {
    flush_requested_ = false;
    // Wake up the flush thread
    flush_cv_.notify_one();
    // Block until flush completes
    append_cv_.wait(flush_latch, [&]() {
      return !request_flush_;
    });
  } else {
    // When force == false, we are performing a group commit
    // But instead of forcing flush,
    // you need to wait for LOG_TIMEOUT or other operations to implicitly
    // trigger the flush operations
    append_cv_.wait(flush_latch);
  }
}

bool LogMgr::logging_enabled() const {
  return logging_enabled_;
}

void LogMgr::run_flush_thread() {
  // NOTE: If we're already runn
  if (running_flush_thread_) {
    return;
  }
  running_flush_thread_ = true;

  flush_future_ = std::async([&]() {
    while (logging_enabled_) {
      // Acquire latch around all internal data structures
      std::lock_guard<std::mutex> flush_latch(latch_);
      // Wait for a request to flush is made..
      //
      // BUT..
      // If the wait is longer than LOG_TIMEOUT = 1 second
      // then we flush anyways
      flush_cv_.wait_for(flush_lock, LOG_TIMEOUT, [&]() {
        return flush_requested_.load();
      });

      assert(flush_buffer_.size() == 0);
      if (log_buffer_.size() > 0) {
        log_buffer_.swap(flush_buffer_);

        std::cout << "Attempting flush to WAL" << std::endl;

        disk_manager_->write_log(flush_buffer_);
        flush_buffer_.truncate();
      }
      flush_requested_ = false;
      append_cv_.notify_all();
    }
  });
}

void LogMgr::stop_flush_thread() {
  // Force a flush
  flush(true);
  // Logging no longer enbled
  logging_enabled_ = false;
  // Join the flush thread
  flush_future_.get();
  // No longer running thread
  running_flush_thread_ = false;
  // Assert both log & flush buffers are empty
  assert(log_buffer_.size() == 0);
  assert(flush_buffer_.size() == 0);
}

lsn_t LogManager::AppendLogRecord(LogRecord &log_record) {
  std::lock_guard<mutex> append_latch(latch_);
  if (logBufferOffset_ + log_record.GetSize() >= LOG_BUFFER_SIZE) {
    needFlush_ = true;
    flush_cv_.notify_one();  // let RunFlushThread wake up.
    appendCv_.wait(latch, [&] {
      return offset_ + log_record.size() < LOG_BUFFER_SIZE;
    });
  }
  log_record.lsn_ = next_lsn_++;

  // header = It is a public field and can be added in advance
  memcpy(log_buffer_ + logBufferOffset_, &log_record, LogRecord::HEADER_SIZE);
  int pos = logBufferOffset_ + LogRecord::HEADER_SIZE;

  // When inserting
  if (log_record.log_record_type_ == LogRecordType::INSERT) {
    memcpy(log_buffer_ + pos, &log_record.insert_rid_, sizeof(RID));
    pos += sizeof(RID);
    // we have provided serialize function for tuple class
    log_record.insert_tuple_.SerializeTo(log_buffer_ + pos);

    // When deleting
  } else if (log_record.log_record_type_ == LogRecordType::MARKDELETE ||
             log_record.log_record_type_ == LogRecordType::APPLYDELETE ||
             log_record.log_record_type_ == LogRecordType::ROLLBACKDELETE) {
    memcpy(log_buffer_ + pos, &log_record.delete_rid_, sizeof(RID));
    pos += sizeof(RID);
    log_record.delete_tuple_.SerializeTo(log_buffer_ + pos);

    // When updating
  } else if (log_record.log_record_type_ == LogRecordType::UPDATE) {
    memcpy(log_buffer_ + pos, &log_record.update_rid_, sizeof(RID));
    pos += sizeof(RID);
    log_record.old_tuple_.SerializeTo(log_buffer_ + pos);
    pos += log_record.old_tuple_.GetLength() + sizeof(int32_t);
    log_record.new_tuple_.SerializeTo(log_buffer_ + pos);
    // When opening a new page
  } else if (log_record.log_record_type_ == LogRecordType::NEWPAGE) {
    // prev_page_id
    memcpy(log_buffer_ + pos, &log_record.prev_page_id_, sizeof(page_id_t));
    pos += sizeof(page_id_t);
    memcpy(log_buffer_ + pos, &log_record.page_id_, sizeof(page_id_t));
  }
  logBufferOffset_ += log_record.GetSize();
  return lastLsn_ = log_record.lsn_;
}
