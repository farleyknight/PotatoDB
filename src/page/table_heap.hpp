#pragma once

#include "buffer/buff_mgr.hpp"

#include "tuple/tuple.hpp"

class LockMgr;
class TableIterator;
class Txn;

class TableHeap {
public:
  TableHeap(table_oid_t table_oid,
            BuffMgr& buff_mgr,
            LockMgr& lock_mgr,
            LogMgr& log_mgr,
            PageId first_page_id);

  TableHeap(table_oid_t table_oid,
            BuffMgr& buff_mgr,
            LockMgr& lock_mgr,
            LogMgr& log_mgr,
            Txn& txn);

  ~TableHeap() = default;

  // No copy
  TableHeap(const TableHeap&) = delete;
  // No copy assign
  TableHeap& operator=(const TableHeap&) = delete;

  const PageId first_page_id() const {
    return first_page_id_;
  }

  bool insert_tuple(Tuple& tuple,
                    Txn& txn);
  bool mark_delete(const RID& rid,
                   Txn& txn);
  bool update_tuple(Tuple& tuple,
                    const RID& rid,
                    Txn& txn);
  bool apply_delete(RID& rid,
                    Txn& txn);
  void rollback_delete(const RID& rid, Txn& txn);

  Tuple find_tuple(const RID& rid, Txn& txn) const;

  TableIterator begin(Txn& txn);
  TableIterator end(Txn& txn);

  BuffMgr& buff_mgr() { return buff_mgr_; }

private:
  table_oid_t table_oid_;
  PageId first_page_id_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;
};
