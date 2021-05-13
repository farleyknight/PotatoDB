
#include "recovery/log_mgr.hpp"

LogMgr::LogMgr(const DiskMgr& disk_mgr)
  : disk_mgr_(disk_mgr)
{
  // TODO: Use smart pointers here in some way
  log_buffer_ = new char[LOG_BUFFER_SIZE];
  flush_buffer_ = new char[LOG_BUFFER_SIZE];
}

bool LogMgr::logging_enabled() const {
  return true;
}

void LogMgr::run_flush_thread() {

}

void LogMgr::stop_flush_thread() {

}

lsn_t LogMgr::emplace(UNUSED Move<LogRecord> log_record) {
  return 0;
}
