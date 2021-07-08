#pragma once

#include "disk/disk_mgr.hpp"
#include "disk/file_mgr.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/table_heap.hpp"

class TableMgr {
public:
  TableMgr(DiskMgr& disk_mgr,
           LockMgr& lock_mgr,
           LogMgr& log_mgr,
           BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr)
  {}

  // TODO: I'm thinking this class is where we can make TableCursor objects?

  void load_table(const string table_name,
                  table_oid_t table_oid)
  {
    // TODO: During load_table_file
    file_id_t file_id = disk_mgr_.load_table_file(table_name);
    auto page_id      = disk_mgr_.first_page(file_id);
    page_ids_.insert(make_pair(table_oid, page_id));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       page_id,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.insert(make_pair(table_oid, move(heap)));
  }

  void create_table(const string table_name,
                    table_oid_t table_oid,
                    Txn& txn)
  {
    file_id_t file_id = disk_mgr_.create_table_file(table_name);
    auto page_id      = disk_mgr_.allocate_page(file_id);
    page_ids_.insert(make_pair(table_oid, page_id));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       page_id,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    // NOTE: We should only be allocating the first page when this is a brand new
    // table.
    //
    // Tables that already exist in the file system should use `load_table`, thus
    // preventing the allocation step from having to happen at all!
    heap->allocate_first_page(txn);

    table_heaps_.insert(make_pair(table_oid, move(heap)));
  }

  TableHeap& table_heap_for(table_oid_t table_oid) {
    assert(table_heaps_.count(table_oid) == 1);
    return *table_heaps_.at(table_oid);
  }

private:
  DiskMgr& disk_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  map<table_oid_t, PageId> page_ids_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;
};
