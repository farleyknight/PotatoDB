#pragma once

#include <atomic>
#include <utility>
#include <unordered_map>
#include <unordered_set>

#include "common/config.hpp"

#include "buffer/table_mgr.hpp"

#include "page/table_heap.hpp"

#include "txns/lock_mgr.hpp"
#include "txns/txn.hpp"

class TxnMgr {
public:
  explicit TxnMgr(LockMgr& lock_mgr,
                  LogMgr& log_mgr,
                  TableMgr& table_mgr)
    : lock_mgr_  (lock_mgr),
      log_mgr_   (log_mgr),
      table_mgr_ (table_mgr)
  {}

  // No copy
  TxnMgr(CRef<TxnMgr>) = delete;
  // No copy assign
  TxnMgr& operator=(CRef<TxnMgr>) = delete;
  ~TxnMgr() = default; // Default delete

  Txn& begin();
  Txn& begin(IsolationLevel level);
  void commit(Txn& txn);
  void abort(Txn& txn);

  CRef<Txn> find(txn_id_t txn_id) {
    assert(table_.find(txn_id) != table_.end());
    return table_.at(txn_id);
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
  Atomic<txn_id_t> curr_txn_id_ = 0;
  LockMgr& lock_mgr_;
  UNUSED LogMgr& log_mgr_;
  TableMgr& table_mgr_;

  MutMap<txn_id_t, Txn> table_;
  RWLatch global_txn_latch_;
};

