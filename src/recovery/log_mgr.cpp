
#include "recovery/log_mgr.hpp"

LogMgr::LogMgr(const DiskMgr& disk_mgr)
  : disk_mgr_(disk_mgr),
{
  log_buffer_.resize(LOG_BUFFER_SIZE);
  flush_buffer_.resize(LOG_BUFFER_SIZE);
}

bool LogMgr::logging_enabled() const {
  return true;
}

void LogMgr::run_flush_thread() {
  // NOTE: If we're already runn
  if (running_flush_thread_) {
    return;
  }
  running_flush_thread_ = true;

  flush_future_ = std::async([&]() {
    while (enable_logging_) {
      std::unique_lock<std::mutex> flush_lock(latch_);
      flush_cv_.wait_for(flush_lock, LOG_TIMEOUT, [&]() {
        return request_flush_.load();
      });

      assert(flush_buffer_.size() == 0);
      if (log_buffer_.size() > 0) {
        log_buffer_.swap(flush_buffer_);

        std::cout << "Attempting flus to WAL" << std::endl;

        disk_manager_->WriteLog(flush_buffer_, flush_buffer_size_);
        flush_buffer_size_ = 0;
      }
      request_flush_ = false;
      append_cv_.notify_all();
    }
  });
}

void LogMgr::stop_flush_thread() {
  Flush();
  enable_logging_ = false;
  flush_future_.get();
  assert(log_buffer_size_ == 0);
  assert(flush_buffer_size_ == 0);
}

lsn_t LogMgr::emplace(UNUSED Move<LogRecord> log_record) {
  return 0;
}
