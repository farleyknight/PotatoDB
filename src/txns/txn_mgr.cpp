#include "txns/txn.hpp"
#include "txns/txn_mgr.hpp"

MRef<Txn> TxnMgr::begin() {
  return begin(IsolationLevel::REPEATABLE_READ);
}

MRef<Txn> TxnMgr::begin(IsolationLevel level =
                        IsolationLevel::REPEATABLE_READ)
{
  global_txn_latch_.rlock();

  // TODO: This shit is so ugly, it needs it's own method..!
  txn_id_t txn_id = curr_txn_id_;
  // https://en.cppreference.com/w/cpp/utility/tuple/forward_as_tuple
  table_.emplace(std::piecewise_construct,
                 std::forward_as_tuple(txn_id),
                 std::forward_as_tuple(txn_id, level));

  curr_txn_id_ = txn_id + 1;

  return table_.at(txn_id);
}

void TxnMgr::commit(MRef<Txn> txn) {
  // Perform all deletes before we commit.
  auto write_set = txn.write_set();
  while (!write_set.empty()) {
    auto &item = write_set.back();
    auto table = item.table();
    if (item.is_delete()) {
      // Note that this also releases the lock when
      // holding the page latch.
      table.apply_delete(item.rid(), txn);
    }
    write_set.pop_back();
  }
  write_set.clear();

  // Do the commit
  txn.commit();

  // Release all the locks.
  release_locks(txn);

  global_txn_latch_.runlock();
}


void TxnMgr::abort(MRef<Txn> txn) {
  txn.abort();
  // rollback before releasing lock
  auto write_set = txn.write_set();

  while (!write_set.empty()) {
    auto &item = write_set.back();
    auto table = item.table();

    switch (item.wtype()) {
    case WType::DELETE:
      table.rollback_delete(item.rid(), txn);
      break;
    case WType::INSERT:
      table.apply_delete(item.rid(), txn);
      break;
    case WType::UPDATE:
      table.update_tuple(item.tuple(), item.rid(), txn);
      break;
    }
    write_set.pop_back();
  }
  write_set.clear();

  MSet<RID> lock_set;
  for (auto item : txn.shared_lock_set()) {
    lock_set.emplace(item);
  }
  for (auto item : txn.exclusive_lock_set()) {
    lock_set.emplace(item);
  }
  for (auto locked_rid : lock_set) {
    lock_mgr_.unlock(txn, locked_rid);
  }
}

void TxnMgr::release_locks(MRef<Txn> txn) const {
  MSet<RID> lock_set;
  for (auto item : txn.exclusive_lock_set()) {
    lock_set.emplace(item);
  }
  for (auto item : txn.shared_lock_set()) {
    lock_set.emplace(item);
  }
  for (auto locked_rid : lock_set) {
    lock_mgr_.unlock(txn, locked_rid);
  }
}
