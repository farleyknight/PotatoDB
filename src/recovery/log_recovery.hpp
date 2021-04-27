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
  LogRecovery(Ref<DiskMgr> disk_mgr,
              Ref<BuffMgr> buff_mgr)
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

  static Ptr<LogRecovery> make(Ref<DiskMgr> disk_mgr,
                               Ref<BuffMgr> buff_mgr)
  {
    return make_unique<LogRecovery>(disk_mgr, buff_mgr);
  }

  void redo();
  void undo();

  bool deserialize_log_record(const char *data, LogRecord *log_record);

private:
  Ref<DiskMgr> disk_mgr_;
  Ref<BuffMgr> buff_mgr_;

  /** Maintain active txns and its corresponding latest lsn. */
  MutMap<txn_id_t, lsn_t> active_txn_;
  /** Mapping the log sequence number to log file offset for undos. */
  MutMap<lsn_t, int> lsn_mapping_;

  int offset_ = 0;
  // TODO: Remove this raw pointer to memory bullshit.
  char *log_buffer_;
};
