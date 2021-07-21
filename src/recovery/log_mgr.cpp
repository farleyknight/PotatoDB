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

void LogMgr::flush_log_buffer() {
  assert(flush_buffer_length_ == 0);
  if (log_cursor_.buffer_offset() > 0) {
    auto tmp = log_cursor_.buffer_offset();
    log_cursor_.set_buffer_offset(flush_buffer_length_);
    flush_buffer_length_ = tmp;

    log_cursor_.swap(flush_buffer_);

    logger->debug("[LogMgr] Flushing to WAL");

    // TODO: Change `disk_mgr_` to a different object
    disk_mgr_.write_log(flush_buffer_);
    flush_buffer_length_ = 0;
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

      flush_log_buffer();
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
  assert(log_cursor_.buffer_offset() == 0);
  assert(flush_buffer_length_ == 0);
}

lsn_t LogMgr::append(LogRecord& log_record) {
  unique_lock<mutex> append_latch(latch_);

  if (log_cursor_.buffer_offset() + log_record.size() >= LOG_BUFFER_SIZE) {
    flush_requested_ = true;
    // NOTE: Wake up the flush thread
    flush_cv_.notify_one();
    // NOTE: Wait for the log buffer size to go down before
    // appending new records.
    append_cv_.wait(append_latch, [&] {
      return log_cursor_.buffer_offset() + log_record.size() < LOG_BUFFER_SIZE;
    });
  }

  log_record.set_lsn(next_lsn_++);

  log_cursor_.append(log_record);

  persisted_lsn_ = log_record.lsn();
  return persisted_lsn_;
}
