#pragma once

#include <deque>
#include <list>
#include <thread>
#include <unordered_map>
#include <unordered_set>

#include "common/config.hpp"

#include "tuple/rid.hpp"
#include "tuple/tuple.hpp"

#include "page/page.hpp"

#include "txns/txn_abort_exception.hpp"
#include "txns/table_write_record.hpp"
#include "txns/txn_state.hpp"

enum class IsolationLevel {
  READ_UNCOMMITTED = 0,
  REPEATABLE_READ = 1,
  READ_COMMITTED = 2
};

class Txn {
public:

  explicit Txn(txn_id_t id,
               IsolationLevel level =
               IsolationLevel::REPEATABLE_READ)
    : id_        (id),
      level_     (level),
      thread_id_ (std::this_thread::get_id()) {}

  // No copy
  Txn(const Txn&) = delete;
  // No copy assign
  Txn& operator=(const Txn&) = delete;
  ~Txn() = default;

  // wait-die: When an older txn tries to lock a DB element that has
  // been locked by a younger txn, it waits.
  bool younger_than(txn_id_t other_txn_id) {
    // By our definition of txn IDs, we can say that T_1 is younger than
    // T_2 if timestamp(T_2) < timestamp(T_1)
    return other_txn_id < id_;
  }

  MutList<TableWriteRecord>& write_set() {
    return table_write_set_;
  }

  void append_table_write_record(const TableWriteRecord& write_record) {
    table_write_set_.push_back(write_record);
  }

  void add_deleted_page(PageId page_id) {
    deleted_page_set_.insert(page_id);
  }

  MutSet<RID>& shared_lock_set() {
    return shared_lock_set_;
  }

  MutSet<RID>& exclusive_lock_set() {
    return exclusive_lock_set_;
  }

  bool is_shared_locked(const RID& rid) const {
    return shared_lock_set_.find(rid) != shared_lock_set_.end();
  }

  /** @return true if rid is exclusively locked by this txn */
  bool is_exclusive_locked(const RID& rid) const {
    return exclusive_lock_set_.find(rid) != exclusive_lock_set_.end();
  }

  /**********************************************
  * Simple instance methods
  * such as getters/setters/predicates.
  **********************************************/

  void allow_restart()             { allow_restart_ = true; }

  txn_id_t id()              const { return id_; }
  IsolationLevel level()     const { return level_; }
  thread::id thread_id()     const { return thread_id_; }

  lsn_t  prev_lsn()          const { return prev_lsn_; }
  void set_prev_lsn(lsn_t lsn)     { prev_lsn_ = lsn; }


  TxnState state()           const { return state_; }
  void set_state(TxnState state)   { state_ = state; }
  void commit()                    { state_ = TxnState::COMMITTED; }
  void abort()                     { state_ = TxnState::ABORTED; }

  void abort_with_reason(AbortReason reason) {
    abort();
    abort_reason_ = reason;
  }

  void begin_growing()      { state_ = TxnState::GROWING; }
  void begin_shrinking()    { state_ = TxnState::SHRINKING; }
  bool is_growing()   const { return state_ == TxnState::GROWING; }
  bool is_shrinking() const { return state_ == TxnState::SHRINKING; }
  bool is_committed() const { return state_ == TxnState::COMMITTED; }
  bool is_aborted()   const { return state_ == TxnState::ABORTED; }
  bool is_finished()  const { return state_ == TxnState::COMMITTED ||
                                     state_ == TxnState::ABORTED; }
private:
  bool           allow_restart_ = false;
  TxnState       state_ = TxnState::GROWING;
  AbortReason    abort_reason_;

  txn_id_t       id_;
  IsolationLevel level_;
  lsn_t          prev_lsn_  = INVALID_LSN;
  thread::id     thread_id_;

  // NOTE: Every txn caries with it 5 collections:
  // 1) Written records
  // 2) Pages latched
  // 3) Delete pages
  // 4) Shared locks to RIDs
  // 5) eXclusive clocks to RIDs.
  //
  // These collections are inserted to and deleted from during
  // normal operation of the txn. However, these actions are
  // perform outside the ctx of the txn itself.

  MutList<TableWriteRecord> table_write_set_;

  // TODO: There were methods to allow these instance variables to be
  // accessed. I removed them for now but they should be replaced when
  // we do the work for concurrent indexes.
  MutDeque<RefWrap<Page>> page_set_;
  MutSet<PageId> deleted_page_set_;

  MutSet<RID> shared_lock_set_;
  MutSet<RID> exclusive_lock_set_;
};
