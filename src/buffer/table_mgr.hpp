#pragma once

#include "disk/disk_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/column_mgr.hpp"

#include "exprs/create_table_expr.hpp"

#include "page/table_heap.hpp"
#include "page/table_header_page.hpp"

// TODO: I created TableMgr because I wanted to have a place to do ALTER TABLE commands,
// and the like.
//
// I would like TableMgr to only be owned by SystemCatalog, however that is not the case
// at the moment. Once that happens, we can then begin working on file locks, which are
// a pre-requisite to changing the schema.
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
  {
    std::cout << "Creating an instance of TableMgr" << std::endl;
  }

  void
  allocate_header_and_first_page(file_id_t file_id,
                                 Txn& txn);

  void
  assert_header_and_first_page_exist(file_id_t file_id,
                                     Txn& txn);

  TableSchema
  read_table_schema(file_id_t file_id) const;

  table_name_t
  read_table_name(file_id_t file_id) const;

  table_oid_t
  read_table_oid(file_id_t file_id) const;

  void
  write_table_schema(file_id_t file_id,
                     const TableSchema& schema)
  {
    table_headers_.at(file_id).write_schema(schema);
  }

  void
  create_table_file(const table_name_t& table_name,
                    const TableSchema& schema,
                    table_oid_t table_oid,
                    Txn& txn)
  {
    file_id_t file_id = disk_mgr_.create_table_file(table_name);
    allocate_header_and_first_page(file_id, txn);

    load_table(table_oid, table_name, schema);

    write_table_schema(file_id, schema);
  }

  TableHeap&
  table_heap_for(table_oid_t table_oid) const {
    assert(table_heaps_.contains(table_oid));
    return *table_heaps_.at(table_oid);
  }

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    assert(table_oids_.contains(table_name));
    return table_oids_.at(table_name);
  }

  table_name_t
  table_name_for(table_oid_t table_oid) const {
    assert(table_names_.contains(table_oid));
    return table_names_.at(table_oid);
  }

  table_oid_t
  create_table_schema(const CreateTableExpr& expr)
  {
    auto table_name = expr.table().name();
    assert(!table_oids_.contains(table_name));
    auto table_oid = next_table_oid_++;
    assert(!table_schemas_.contains(table_oid));
    auto schema = make_schema_from(table_oid, expr);

    load_table_schema(table_oid, schema);
    return table_oid;
  }

  TableSchema
  make_schema_from(table_oid_t table_oid,
                   const CreateTableExpr& expr)
  {
    auto table_name  = expr.table().name();
    auto column_list = expr.column_defs();

    auto columns = column_mgr_.make_columns(table_oid, table_name, column_list);
    return TableSchema(columns, table_name, table_oid);
  }

  void
  open_table_header(const table_name_t& table_name) {
    auto file_id   = disk_mgr_.open_table_file(table_name);
    auto table_oid = disk_mgr_.table_oid_for(file_id);
    auto page_id   = disk_mgr_.table_header_page(file_id);
    auto page_ptr  = buff_mgr_.fetch_page(page_id);
    assert(page_ptr);
    load_table_header(table_oid, page_ptr);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name)
  {
    return column_mgr_.table_has_column_named(table_name, column_name);
  }

  TableColumn
  column_for(column_oid_t column_oid) {
    return column_mgr_.column_for(column_oid);
  }

  const TableSchema&
  table_schema_for(table_oid_t table_oid) const {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid);
  }

  TableSchema&
  table_schema_for(table_oid_t table_oid) {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid);
  }

  TableColumn
  make_column_from(table_oid_t table_oid,
                   column_oid_t column_oid,
                   const ColumnDefExpr& expr) const
  {
    return column_mgr_.make_column_from(table_oid, column_oid, expr);
  }

  column_oid_t
  make_column_oid(const table_name_t& table_name,
                  const column_name_t& column_name)
  {
    return column_mgr_.make_column_oid(table_name, column_name);
  }

  column_oid_t
  column_oid_for(table_oid_t table_oid,
                 const column_name_t& column_name)
  {
    auto table_name = table_name_for(table_oid);
    return column_mgr_.column_oid_for(table_name, column_name);
  }

  column_oid_t
  column_oid_for(const table_name_t& table_name,
                 const column_name_t& column_name)
  {
    return column_mgr_.column_oid_for(table_name, column_name);
  }

  bool
  has_table_named(const table_name_t& table_name) const {
    return table_oids_.contains(table_name);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const {
    return column_mgr_.table_has_column_named(table_name, column_name);
  }

  void
  open_all_tables() {
    for (const auto file_id : disk_mgr_.table_file_ids()) {
      auto table_oid    = read_table_oid(file_id);
      auto table_name   = read_table_name(file_id);
      auto table_schema = read_table_schema(file_id);
      load_table(table_oid, table_name, table_schema);
    }
  }

private:

  void
  load_table_header(table_oid_t table_oid, Page* page_ptr) {
    table_headers_.emplace(table_oid, TableHeaderPage(page_ptr));
  }

  void
  load_table_name(table_oid_t table_oid, table_name_t table_name) {
    table_names_[table_oid] = table_name;
    table_oids_[table_name] = table_oid;
  }

  void
  load_table_schema(table_oid_t table_oid, const TableSchema& table_schema) {
    table_schemas_.emplace(table_oid, table_schema);
  }


  void
  load_table(table_oid_t table_oid,
             const table_name_t& table_name,
             const TableSchema& schema)
  {
    load_table_header(table_name);
    load_table_name(table_oid, table_name);
    load_table_schema(table_oid, schema);
    load_table_heap(table_oid);
  }

  void
  load_table_heap(table_oid_t table_oid) {
    auto file_id = disk_mgr_.file_id_for_table(table_oid);
    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.emplace(table_oid, move(heap));
  }

  DiskMgr& disk_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  ColumnMgr column_mgr_;

  map<table_oid_t, table_name_t> table_names_;
  map<table_name_t, table_oid_t> table_oids_;

  map<table_oid_t, TableHeaderPage> table_headers_;
  map<table_oid_t, TableSchema> table_schemas_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;

  atomic<table_oid_t> next_table_oid_ = FIRST_TABLE_OID;
};
