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

  void create_table(const string table_name,
                    table_oid_t table_oid,
                    Txn& txn)
  {
    // TODO
    // 1) Create file via FileMgr/FileHandle
    // 2) Create TableHeap as first page
    // 3) Add TableHeap to vector of TableHeaps

    file_id_t file_id = disk_mgr_.create_table_file(table_name);
    auto page_id      = disk_mgr_.allocate_page(file_id);
    page_ids_.insert(make_pair(table_oid, page_id));

    //auto maybe_page   = buff_mgr_.fetch_page(page_id);
    //assert(maybe_page);
    auto heap = make_unique<TableHeap>(table_oid,
                                       page_id,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_,
                                       txn);

    table_heaps_.insert(make_pair(table_oid, move(heap)));
  }

  TableHeap& table_heap_for(table_oid_t table_oid) {
    return *table_heaps_.at(table_oid);
  }

private:
  DiskMgr& disk_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  MutMap<table_oid_t, PageId> page_ids_;
  MutMap<table_oid_t, ptr<TableHeap>> table_heaps_;
};
