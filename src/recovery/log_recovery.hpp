#pragma once

#include <algorithm>
#include <mutex>  // NOLINT
#include <unordered_map>

#include "buffer/buff_mgr.hpp"
#include "txns/lock_mgr.hpp"
#include "recovery/log_record.hpp"

/**
 * Read log file from disk, redo and undo.
 */
class LogRecovery {
 public:
  LogRecovery(const DiskMgr& disk_mgr,
              const BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr)
  {
    // TODO: Remove this new bullshit
    log_buffer_ = new char[LOG_BUFFER_SIZE];
  }

  ~LogRecovery() {
    // TODO: Remove this delete bullshit
    delete[] log_buffer_;
    log_buffer_ = nullptr;
  }

  void redo();
  void undo();

  bool deserialize_log_record(const char *data, LogRecord *log_record);

private:
  UNUSED const DiskMgr& disk_mgr_;
  UNUSED const BuffMgr& buff_mgr_;

  MutMap<txn_id_t, lsn_t> active_txn_;
  MutMap<lsn_t, int> lsn_mapping_;

  UNUSED int offset_ = 0;
  // TODO: Remove this raw pointer to memory bullshit.
  char *log_buffer_;
};
