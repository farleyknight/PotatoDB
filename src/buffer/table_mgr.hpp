#pragma once

#include "disk/disk_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/column_mgr.hpp"

#include "exprs/create_table_expr.hpp"

#include "page/table_heap.hpp"
#include "page/table_header_page.hpp"

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
  write_schema(file_id_t file_id,
               const TableSchema& schema)
  {
    assert(table_headers_.contains(file_id));
    table_headers_.at(file_id).write_schema(schema);
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

  const vector<TableColumn>&
  table_columns_for(table_oid_t table_oid) const {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid).all();
  }

  vector<TableColumn>&
  table_columns_for(table_oid_t table_oid) {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid).all();
  }


  table_oid_t
  create_table(const CreateTableExpr& expr, Txn& txn);

  TableSchema
  make_schema_from(table_oid_t table_oid,
                   const CreateTableExpr& expr);

  void
  open_table_header(file_id_t file_id);

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
  open_all_tables();

  vector<table_name_t>
  table_names() const {
    vector<table_name_t> names;
    for (const auto & [table_oid, table_name] : table_names_) {
      names.push_back(table_name);
    }
    return names;
  }

private:

  void
  load_table_header(table_oid_t table_oid, Page* page_ptr) {
    table_headers_.emplace(table_oid,
                           TableHeaderPage(page_ptr));
  }

  void
  load_table_name(table_oid_t table_oid,
                  table_name_t table_name)
  {
    std::cout << "Adding table_oid " << table_oid << " with table_name " << table_name << std::endl;
    table_names_[table_oid] = table_name;
    table_oids_[table_name] = table_oid;
  }

  void
  load_table_schema(table_oid_t table_oid,
                    const TableSchema& table_schema)
  {
    table_schemas_.emplace(table_oid, table_schema);
  }

  void
  load_table(file_id_t file_id,
             table_oid_t table_oid,
             const table_name_t& table_name,
             const TableSchema& schema);

  void
  load_table_heap(file_id_t file_id,
                  table_oid_t table_oid);

  DiskMgr& disk_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  ColumnMgr column_mgr_;

  map<file_id_t, TableHeaderPage> table_headers_;

  map<table_oid_t, table_name_t> table_names_;
  map<table_name_t, table_oid_t> table_oids_;

  map<table_oid_t, TableSchema> table_schemas_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;

  atomic<table_oid_t> next_table_oid_ = FIRST_TABLE_OID;
};
