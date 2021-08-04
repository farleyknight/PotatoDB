#pragma once

#include "buffer/buff_mgr.hpp"

#include "tuple/tuple.hpp"
#include "page/slotted_table_page.hpp"

class LockMgr;
class TableIterator;
class Txn;

class TableHeap {
public:
  TableHeap(file_id_t file_id,
            table_oid_t table_oid,
            PageId first_page_id,
            BuffMgr& buff_mgr,
            LockMgr& lock_mgr,
            LogMgr& log_mgr);

  ~TableHeap() = default;

  // No copy
  TableHeap(const TableHeap&) = delete;
  // No copy assign
  TableHeap& operator=(const TableHeap&) = delete;

  const PageId first_page_id() const {
    return first_page_id_;
  }

  file_id_t file_id() const {
    return file_id_;
  }

  table_oid_t table_oid() const;
  bool insert_tuple(Tuple& tuple, Txn& txn);
  bool mark_delete(const RID& rid, Txn& txn);
  bool update_tuple(Tuple& tuple, const RID& rid, Txn& txn);
  bool apply_delete(const RID& rid, Txn& txn);
  bool rollback_delete(const RID& rid, Txn& txn);
  ptr<Tuple> find_tuple(const RID& rid, Txn& txn) const;

  TableIterator begin(Txn& txn);
  TableIterator end(Txn& txn);

  BuffMgr& buff_mgr() { return buff_mgr_; }

  SlottedTablePage first_page(Txn& txn);

private:
  file_id_t file_id_;
  table_oid_t table_oid_;
  PageId first_page_id_;
  BuffMgr& buff_mgr_;
  LogMgr& log_mgr_;
  LockMgr& lock_mgr_;
};
