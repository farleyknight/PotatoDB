#pragma once

#include <algorithm>
#include <condition_variable>  // NOLINT
#include <future>              // NOLINT
#include <mutex>               // NOLINT

#include "recovery/log_record.hpp"
#include "disk/disk_mgr.hpp"

class LogMgr {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  LogMgr(CRef<DiskMgr> disk_mgr);

  ~LogMgr() {
    // TODO: Replace these two with our Buffer class
    delete[] log_buffer_;
    delete[] flush_buffer_;
    log_buffer_ = nullptr;
    flush_buffer_ = nullptr;
  }

  /**********************************************
   * Instance methods
   **********************************************/

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

  inline char *log_buffer() {
    return log_buffer_;
  }

private:
  Atomic<lsn_t> next_lsn_ {0};
  Atomic<lsn_t> persistent_lsn_ {INVALID_LSN};

  char *log_buffer_;
  char *flush_buffer_;

  std::mutex latch_;

  UNUSED std::thread *flush_thread_;

  std::condition_variable cv_;

  UNUSED CRef<DiskMgr> disk_mgr_;
};
