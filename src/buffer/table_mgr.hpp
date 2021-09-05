#pragma once

#include "disk/file_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "catalog/table_schema.hpp"

#include "page/table_heap.hpp"
#include "page/table_header_page.hpp"

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
  {
    std::cout << "Creating an instance of TableMgr" << std::endl;
  }

  void allocate_header_and_first_page(file_id_t file_id,
                                      Txn& txn);

  void assert_header_and_first_page_exist(file_id_t file_id,
                                          Txn& txn);

  TableSchema read_table_schema(file_id_t file_id);
  void write_table_schema(file_id_t file_id, TableSchema schema);

  void create_table(const table_name_t& table_name,
                    const TableSchema& schema,
                    table_oid_t table_oid,
                    Txn& txn);

  // TODO: I'm thinking this class is where we can make
  // TableCursor objects?
  void load_table_file(const string& table_name,
                       table_oid_t table_oid,
                       Txn& txn)
  {

    table_names_.insert(make_pair(table_oid, table_name));

    file_id_t file_id = file_mgr_.load_table_file(table_name);
    assert_header_and_first_page_exist(table_oid, txn);

    file_ids_.insert(make_pair(table_oid, file_id));
    table_oids_.insert(make_pair(file_id, table_oid));

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.insert(make_pair(table_oid, move(heap)));

    // TODO: Load TableSchema here
  }

  TableHeap& table_heap_for(table_oid_t table_oid) {
    assert(table_heaps_.contains(table_oid));
    return *table_heaps_[table_oid];
  }

  table_oid_t table_oid_for(file_id_t file_id) {
    assert(table_oids_.contains(file_id));
    return table_oids_[file_id];
  }

  file_id_t file_id_for(table_oid_t table_oid) {
    assert(file_ids_.contains(table_oid));
    return file_ids_[table_oid];
  }

private:

  void load_table(file_id_t file_id, table_oid_t table_oid,
                  const table_name_t file_name)
  {
    file_ids_[table_oid]    = file_id;
    table_oids_[file_id]    = table_oid;
    table_names_[table_oid] = table_name;

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.emplace(table_oid, move(heap));
  }



  FileMgr& file_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  map<table_oid_t, table_name_t> table_names_;
  map<table_oid_t, file_id_t> file_ids_;
  // NOTE: Should be reverse mapping of prev line
  map<file_id_t, table_oid_t> table_oids_;

  map<table_oid_t, ptr<TableHeap>> table_heaps_;
};
