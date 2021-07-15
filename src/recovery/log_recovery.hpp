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
              BuffMgr& buff_mgr,
              LogMgr& log_mgr,
              LockMgr& lock_mgr,
              Txn& txn)
    : disk_mgr_   (disk_mgr),
      buff_mgr_   (buff_mgr),
      log_mgr_    (log_mgr),
      lock_mgr_   (lock_mgr),
      txn_        (txn),
      log_cursor_ (LOG_BUFFER_SIZE)
  {}

  // No copy
  LogRecovery(const LogRecovery&) = delete;
  // No copy assign
  LogRecovery& operator=(const LogRecovery&) = delete;
  ~LogRecovery() = default; // Default delete

  void redo();
  void undo();

  void apply_next_log_record();
  bool deserialize_log_record(LogRecord& log);

private:
  DiskMgr& disk_mgr_;
  BuffMgr& buff_mgr_;
  LogMgr& log_mgr_;
  LockMgr& lock_mgr_;
  Txn& txn_;

  map<txn_id_t, lsn_t> active_txn_;
  map<lsn_t, int> lsn_mapping_;

  BufferCursor log_cursor_;
};
