#pragma once

#include <algorithm>
#include <mutex>  // NOLINT
#include <unordered_map>

#include "buffer/buff_mgr.hpp"
#include "txns/lock_mgr.hpp"
#include "recovery/log_record.hpp"

class LogRecovery {
 public:
  LogRecovery(DiskMgr& disk_mgr,
              BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr),
      log_mgr_  (log_mgr),
      txn_      (txn)
  {
    log_buffer_.resize(LOG_BUFFER_SIZE);
  }

  // No copy
  LogRecovery(const LogRecovery&) = delete;
  // No copy assign
  LogRecovery& operator=(const LogRecovery&) = delete;
  ~LogRecovery() = default; // Default delete

  void redo();
  void undo();

  // TODO: Replace with references & buffer
  bool deserialize_log_record(const char *data, LogRecord *log_record);

private:
  DiskMgr& disk_mgr_;
  BuffMgr& buff_mgr_;
  LogMgr& log_mgr_;
  Txn& txn_; // TODO: This must be passed into the constructor

  map<txn_id_t, lsn_t> active_txn_;
  map<lsn_t, int> lsn_mapping_;

  UNUSED int offset_ = 0;

  Buffer log_buffer_;
};
