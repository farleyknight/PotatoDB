#pragma once

#include "disk/file_mgr.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/table_heap.hpp"
#include "catalog/table_schema.hpp"

class TableMgr {
public:
  TableMgr(FileMgr& file_mgr,
           LockMgr& lock_mgr,
           LogMgr& log_mgr,
           BuffMgr& buff_mgr)
    : file_mgr_ (file_mgr),
      lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr)
  {}

  TableSchema read_table_schema(table_oid_t table_oid) {
    assert(table_names_.count(table_oid) > 0);
    auto table_name = table_names_[table_oid];

    auto page_id      = file_mgr_.table_header(file_id);
    auto page         = buff_mgr_.fetch_page(page_id);
    auto table_header_page = TableHeaderPage(page);

    return table_header_page.read_schema();
  }

  // TODO: I'm thinking this class is where we can make TableCursor objects?
  void load_table(const string& table_name,
                  table_oid_t table_oid)
  {
    table_names_.insert(make_pair(table_oid, table_name));

    // TODO: During load_table_file
    file_id_t file_id = file_mgr_.load_table_file(table_name);
    file_ids_.insert(make_pair(table_oid, file_id));

    auto page_id      = file_mgr_.first_table_page(file_id);
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
    file_id_t file_id = file_mgr_.create_table_file(table_name);
    file_ids_.insert(make_pair(table_oid, file_id));

    auto page_id      = file_mgr_.first_table_page(file_id);
    page_ids_.insert(make_pair(table_oid, page_id));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       page_id,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    // NOTE: We should only be allocating the header page and the first page when
    // this is a brand new table.
    //
    // Tables that already exist in the file system should use `load_table`, thus
    // preventing the allocation step from having to happen at all!
    file_mgr_.allocate_header_and_first_page(file_id);
    table_heaps_.insert(make_pair(table_oid, move(heap)));
  }

  TableHeap& table_heap_for(table_oid_t table_oid) {
    assert(table_heaps_.count(table_oid) == 1);
    return *table_heaps_.at(table_oid);
  }

private:
  FileMgr& file_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  map<table_oid_t, const table_name_t> table_names_;
  map<table_oid_t, PageId> page_ids_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;
};
