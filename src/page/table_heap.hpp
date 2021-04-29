#pragma once

#include "buffer/buff_mgr.hpp"

#include "tuple/tuple.hpp"

class LockMgr;
class TableIterator;
class Txn;

class TableHeap {
public:
  TableHeap(BuffMgr& buff_mgr,
            LockMgr& lock_mgr,
            LogMgr& log_mgr,
            PageId& first_page_id);

  TableHeap(BuffMgr& buff_mgr,
            LockMgr& lock_mgr,
            LogMgr& log_mgr,
            Txn& txn);

  ~TableHeap() = default;

  // No copy
  TableHeap(CRef<TableHeap>) = delete;
  // No copy assign
  TableHeap& operator=(CRef<TableHeap>) = delete;

  const PageId first_page_id() const {
    return first_page_id_;
  }

  RID insert_tuple(CRef<Tuple> tuple,
                   Txn& txn);
  bool mark_delete(CRef<RID> rid,
                   Txn& txn);
  bool update_tuple(Tuple& tuple,
                    CRef<RID> rid,
                    Txn& txn);
  bool apply_delete(RID& rid,
                    Txn& txn);
  void rollback_delete(CRef<RID> rid, Txn& txn);

  Option<Tuple> find_tuple(CRef<RID> rid, Txn& txn) const;

  TableIterator begin(Txn& txn);
  TableIterator end(Txn& txn);

  BuffMgr& buff_mgr() { return buff_mgr_; }

private:
  PageId first_page_id_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;
};
