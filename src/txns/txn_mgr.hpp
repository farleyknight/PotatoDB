#pragma once

#include <atomic>
#include <utility>
#include <unordered_map>
#include <unordered_set>

#include "common/config.hpp"

#include "catalog/schema_mgr.hpp"

#include "page/table_heap.hpp"

#include "txns/lock_mgr.hpp"
#include "txns/txn.hpp"

class TxnMgr {
public:
  explicit TxnMgr(LockMgr& lock_mgr,
                  LogMgr& log_mgr,
                  SchemaMgr& schema_mgr)
    : lock_mgr_   (lock_mgr),
      log_mgr_    (log_mgr),
      schema_mgr_ (schema_mgr)
  {}

  // No copy
  TxnMgr(const TxnMgr&) = delete;
  // No copy assign
  TxnMgr& operator=(const TxnMgr&) = delete;
  ~TxnMgr() = default; // Default delete

  Txn& begin();
  Txn& begin(IsolationLevel level);
  void commit(Txn& txn);
  void abort(Txn& txn);

  const Txn& find(txn_id_t txn_id) {
    assert(txn_table_.find(txn_id) != txn_table_.end());
    return txn_table_.at(txn_id);
  }

  void block_all_txns() {
    global_txn_latch_.wlock();
  }

  void resume_txns() {
    global_txn_latch_.wunlock();
  }

private:
  void release_locks(Txn& txn) const;

  // Atomic, to ensure that no two Txns end up with the same ID
  atomic<txn_id_t> curr_txn_id_ = 0;
  LockMgr& lock_mgr_;
  UNUSED LogMgr& log_mgr_;
  SchemaMgr& schema_mgr_;

  map<txn_id_t, Txn> txn_table_;
  RWLatch global_txn_latch_;
};

