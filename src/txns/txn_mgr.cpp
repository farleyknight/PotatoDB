#include "txns/txn.hpp"
#include "txns/txn_mgr.hpp"

Txn& TxnMgr::begin() {
  return begin(IsolationLevel::REPEATABLE_READ);
}

Txn& TxnMgr::begin(IsolationLevel level =
                   IsolationLevel::REPEATABLE_READ)
{
  global_txn_latch_.rlock();

  // TODO: This shit is so ugly, it needs it's own method..!
  txn_id_t txn_id = curr_txn_id_++;
  // https://en.cppreference.com/w/cpp/utility/tuple/forward_as_tuple
  txn_table_.emplace(std::piecewise_construct,
                     std::forward_as_tuple(txn_id),
                     std::forward_as_tuple(txn_id, level));

  assert(txn_table_.contains(txn_id));
  return txn_table_.at(txn_id);
}

void TxnMgr::commit(Txn& txn) {
  // Perform all deletes before we commit.
  auto write_set = txn.write_set();
  while (!write_set.empty()) {
    auto &item = write_set.back();

    if (item.is_delete()) {
      logger->debug("[TxnMgr] APPLY DELETE " + item.rid().to_string());
      auto &table_heap = schema_mgr_.table_heap_for(item.table_oid());
      // Note that this also releases the lock when
      // holding the page latch.
      table_heap.apply_delete(item.rid(), txn);
    }
    write_set.pop_back();
  }
  write_set.clear();

  logger->debug("[TxnMgr] Checking if Logging is Enabled");
  if (log_mgr_.is_logging_enabled()) {
    logger->debug("[TxnMgr] Logging IS Enabled");
    // We make sure your log records are permanently stored on
    // disk file before release the locks.
    //
    // But instead of forcing a flush, we wait for
    // LOG_TIMEOUT or other operations to
    // implicitly trigger the flush operations.
    //
    // Write log and update transaction's prev_lsn here
    LogRecord log{txn.id(), txn.prev_lsn(), LogRecordType::COMMIT};
    txn.set_prev_lsn(log_mgr_.append(log));

    logger->debug("[TxnMgr] Waiting for a Synchronous Flush");
    log_mgr_.sync_flush(false);
    logger->debug("[TxnMgr] Log Flush Finished");
  } else {
    logger->debug("[TxnMgr] Logging IS NOT Enabled");
  }

  // Do the commit
  logger->debug("[TxnMgr] Do the actual commit");
  txn.commit();

  // Release all the locks.
  release_locks(txn);

  global_txn_latch_.runlock();
}

void TxnMgr::abort(Txn& txn) {
  txn.abort();
  // rollback before releasing lock
  auto write_set = txn.write_set();

  while (!write_set.empty()) {
    auto &item = write_set.back();
    auto &table_heap = schema_mgr_.table_heap_for(item.table_oid());

    switch (item.wtype()) {
    case WType::DELETE:
      table_heap.rollback_delete(item.rid(), txn);
      break;
    case WType::INSERT:
      table_heap.apply_delete(item.rid(), txn);
      break;
    case WType::UPDATE:
      table_heap.update_tuple(item.tuple(), item.rid(), txn);
      break;
    }
    write_set.pop_back();
  }
  write_set.clear();

  if (log_mgr_.is_logging_enabled()) {
    // write log and update transaction's prev_lsn here
    LogRecord log{txn.id(), txn.prev_lsn(), LogRecordType::ABORT};
    txn.set_prev_lsn(log_mgr_.append(log));
    log_mgr_.sync_flush(false);
  }

  set<RID> lock_set;
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

void TxnMgr::release_locks(Txn& txn) const {
  set<RID> lock_set;
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
