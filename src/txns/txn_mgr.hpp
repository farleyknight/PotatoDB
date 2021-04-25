#pragma once

#include <atomic>
#include <utility>
#include <unordered_map>
#include <unordered_set>

#include "common/config.hpp"

#include "txns/lock_mgr.hpp"
#include "txns/txn.hpp"

#include "page/table_heap.hpp"

class TxnMgr {
public:
  /**********************************************
  * Constructors & destructor
  **********************************************/

  explicit TxnMgr(MRef<LockMgr> lock_mgr,
                  MRef<LogMgr> log_mgr)
    : lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr) {}

  // No copy
  TxnMgr(CRef<TxnMgr>) = delete;
  // No copy assign
  MRef<TxnMgr> operator=(CRef<TxnMgr>) = delete;
  ~TxnMgr() = default; // Default delete

  /**********************************************
  * Instance methods
  **********************************************/

  MRef<Txn> begin();
  MRef<Txn> begin(IsolationLevel level);
  void commit(MRef<Txn> txn);
  void abort(MRef<Txn> txn);

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
  void release_locks(MRef<Txn> txn) const;

  // Atomic, to ensure that no two Txns end up with the same ID
  Atomic<txn_id_t> curr_txn_id_ = 0;
  MRef<LockMgr> lock_mgr_;
  MRef<LogMgr> log_mgr_;

  MutMap<txn_id_t, Txn> table_;
  /** The global txn latch is used for checkpointing. */
  RWLatch global_txn_latch_;
};

