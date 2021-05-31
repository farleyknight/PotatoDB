#pragma once

#include <algorithm>
#include <condition_variable>  // NOLINT
#include <future>              // NOLINT
#include <mutex>               // NOLINT

#include "recovery/log_record.hpp"
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

  LogMgr(const DiskMgr& disk_mgr);

  ~LogMgr() {
    stop_flush_thread();
  }

  bool logging_enabled() const;

  void run_flush_thread();
  void stop_flush_thread();

  lsn_t emplace(Move<LogRecord> log_record);

  lsn_t next_lsn() {
    return next_lsn_;
  }

  lsn_t persistent_lsn() {
    return persistent_lsn_;
  }

  inline void set_persistent_lsn(lsn_t lsn) {
    persistent_lsn_ = lsn;
  }

private:
  Atomic<lsn_t> next_lsn_ {0};
  Atomic<lsn_t> persistent_lsn_ {INVALID_LSN};

  // TODO: Replace with Buffer class
  Buffer log_buffer_, flush_buffer_;

  std::mutex latch_;

  std::condition_variable flush_cv_;
  std::condition_variable append_cv_;

  std::future<void> flush_future_;

  Atomic<bool> running_flush_thread_ {false};
  Atomic<bool> enable_logging_       {false};
  Atomic<bool> flush_requested_      {false};

  UNUSED const DiskMgr& disk_mgr_;
};
