#pragma once

#include "disk/disk_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/column_mgr.hpp"

#include "exprs/create_table_expr.hpp"

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

  void
  allocate_header_and_first_page(file_id_t file_id,
                                 Txn& txn);

  void
  assert_header_and_first_page_exist(file_id_t file_id,
                                     Txn& txn);

  table_oid_t
  read_table_oid(file_id_t file_id) const;

  table_name_t
  read_table_name(file_id_t file_id) const;

  TableSchema
  read_table_schema(file_id_t file_id) const;

  void
  write_table_oid(file_id_t file_id,
                  table_oid_t table_oid);

  void
  write_table_name(file_id_t file_id,
                   const table_name_t& table_name);

  void
  write_table_schema(file_id_t file_id,
                     const TableSchema& schema);

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

  TableColumn&
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
                 const column_name_t& column_name) const
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
  load_table_name(table_oid_t table_oid,
                  table_name_t table_name);

  void
  open_all_tables();

  vector<table_name_t>
  table_names() const;

private:
  void
  flush_header_page(file_id_t file_id);

  void
  write_table(file_id_t file_id,
              table_oid_t table_oid,
              const table_name_t& table_name,
              const TableSchema& schema);

  void
  load_table_schema(table_oid_t table_oid,
                    TableSchema&& table_schema)
  {
    table_schemas_.emplace(table_oid, move(table_schema));
  }

  void
  load_table_columns(const table_name_t& table_name,
                     const vector<TableColumn>& table_columns);

  void
  load_table(file_id_t file_id,
             table_oid_t table_oid,
             const table_name_t& table_name,
             TableSchema&& schema);

  void
  load_table_heap(file_id_t file_id,
                  table_oid_t table_oid);

  DiskMgr& disk_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  ColumnMgr column_mgr_;

  map<table_oid_t, table_name_t> table_names_;
  map<table_name_t, table_oid_t> table_oids_;

  map<table_oid_t, TableSchema&&> table_schemas_;
  map<table_oid_t, ptr<TableHeap>> table_heaps_;

  atomic<table_oid_t> next_table_oid_ = FIRST_TABLE_OID;
};
