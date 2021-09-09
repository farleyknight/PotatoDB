#pragma once

#include <algorithm>
#include <condition_variable>  // NOLINT
#include <future>              // NOLINT
#include <mutex>               // NOLINT

#include "recovery/log_record.hpp"
#include "recovery/log_file_cursor.hpp"

#include "disk/disk_mgr.hpp"

// REFERENCES:
// * https://github.com/dentiny/GhostDB/blob/1a58b9e46841fb8a670555f59ddda2d7db1819ce/src/log_manager.cc
// * https://github.com/hqnddw/CMU-15445-database/blob/9502dcd019696af10e9781f890ab22d658e04bf7/src/logging/log_manager.cpp
// * https://github.com/cakebytheoceanLuo/CMU15-445/blob/82ade2aec6a77e8f8c175a066585d1785841f928/src/recovery/log_manager.cpp#L28
// * https://github.com/Handora/QCDB/blob/0c68bce7258e63398c34837f5c3b60e8b25915ff/src/logging/log_manager.cpp
// * https://github.com/codeMonkey339/db/blob/d9715b7795c2a9460ab669e4993886e7c491496c/src/logging/log_manager.cpp
// * https://github.com/codeMonkey339/db/blob/d9715b7795c2a9460ab669e4993886e7c491496c/src/logging/log_recovery.cpp

class LogMgr {
public:
  LogMgr(DiskMgr& disk_mgr)
    : disk_mgr_ (disk_mgr)
  {}

  ~LogMgr() {
    stop_flush_thread();
  }

  void run_flush_thread();
  void stop_flush_thread();
  void sync_flush(bool force);
  lsn_t append(LogRecord& log_record);
  void flush_log_buffer();

  lsn_t next_lsn() {
    return next_lsn_;
  }

  lsn_t persisted_lsn() {
    return persisted_lsn_;
  }

  void set_persisted_lsn(lsn_t lsn) {
    persisted_lsn_ = lsn;
  }

  void set_log_timeout(std::chrono::duration<uint64_t> timeout) {
    log_timeout_ = timeout;
  }

  bool is_logging_enabled() const {
    return is_logging_enabled_;
  }

  void disable_logging() {
    is_logging_enabled_ = false;
  }

private:
  atomic<lsn_t> next_lsn_ {0};
  // TODO: Rename this to "persisted_lsn"
  // The term "peristent" is a little confusing
  atomic<lsn_t> persisted_lsn_ {INVALID_LSN};

  Buffer flush_buffer_ {LOG_BUFFER_SIZE};
  LogFileCursor log_cursor_ {LOG_BUFFER_SIZE};

  buffer_offset_t flush_buffer_length_ = 0;

  mutex latch_;

  std::condition_variable flush_cv_;
  std::condition_variable append_cv_;

  std::future<void> flush_future_;

  atomic<bool> running_flush_thread_ {false},
               is_logging_enabled_   {false},
               flush_requested_      {false};

  DiskMgr& disk_mgr_;

  std::chrono::duration<uint64_t> log_timeout_ = std::chrono::seconds(1);
};
