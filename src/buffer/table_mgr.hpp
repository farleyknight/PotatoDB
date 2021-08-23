#pragma once

#include "disk/file_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "page/table_heap.hpp"
#include "page/table_header_page.hpp"

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

  void allocate_header_and_first_page(file_id_t file_id,
                                      Txn& txn);

  void assert_header_and_first_page_exist(file_id_t file_id,
                                          Txn& txn);

  TableSchema read_table_schema(table_oid_t table_oid);

  // TODO: I'm thinking this class is where we can make
  // TableCursor objects?
  void load_table(const string& table_name,
                  table_oid_t table_oid,
                  Txn& txn)
  {
    table_names_.insert(make_pair(table_oid, table_name));

    file_id_t file_id = file_mgr_.load_table_file(table_name);
    assert_header_and_first_page_exist(table_oid, txn);
    file_ids_.insert(make_pair(table_oid, file_id));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.insert(make_pair(table_oid, move(heap)));
  }

  // TODO: This needs to be passed the TableSchema so it
  // can be written as the first block of the .tbl file.
  void create_table(const table_name_t& table_name,
                    table_oid_t table_oid,
                    Txn& txn)
  {
    file_id_t file_id = file_mgr_.create_table_file(table_name);
    allocate_header_and_first_page(file_id, txn);
    file_ids_.insert(make_pair(table_oid, file_id));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

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
  map<table_oid_t, file_id_t> file_ids_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;
};
