#pragma once

#include <memory>

#include "common/config.hpp"


#include "exprs/create_table_expr.hpp"
#include "exprs/create_index_expr.hpp"
#include "exprs/column_list_expr.hpp"
#include "exprs/column_def_list_expr.hpp"

#include "txns/lock_mgr.hpp"

#include "index/base_index.hpp"

#include "server/statement_result.hpp"
#include "server/system_catalog.hpp"

class SchemaMgr {
public:
  SchemaMgr(DiskMgr& disk_mgr,
            LockMgr& lock_mgr,
            LogMgr&  log_mgr,
            BuffMgr& buff_mgr)
    : sys_catalog_ (disk_mgr, lock_mgr, log_mgr, buff_mgr)
  {}

  // No copy
  SchemaMgr(const SchemaMgr&) = delete;
  // No copy assign
  SchemaMgr& operator=(const SchemaMgr&) = delete;
  // Default deletedd
  ~SchemaMgr() = default;

  void
  build_system_catalog() {
    sys_catalog_.build_system_catalog();
  }

  bool
  has_table_named(const table_name_t& table_name) const {
    return sys_catalog_.has_table_named(table_name);
  }

  const table_name_t
  table_name_for(table_oid_t table_oid) const {
    return sys_catalog_.table_name_for(table_oid);
  }

  TableHeap&
  table_heap_for(table_oid_t table_oid) {
    return sys_catalog_.table_heap_for(table_oid);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const
  {
    return sys_catalog_.table_has_column_named(table_name, column_name);
  }

  column_oid_t
  column_oid_for(const table_name_t& table_name,
                 const column_name_t& column_name) const
  {
    return sys_catalog_.column_oid_for(table_name, column_name);
  }

  table_oid_t
  create_table(const CreateTableExpr& expr, Txn& txn) {
    return sys_catalog_.create_table(expr, txn);
  }

  index_oid_t
  create_index(const CreateIndexExpr& expr, UNUSED Txn& txn) {
    return sys_catalog_.create_index(expr);
  }

  // NOTE: TableSchema can change it's auto-increment value,
  // thus it cannot be return as a const ref.
  TableSchema&
  table_schema_for(table_oid_t table_oid) {
    return sys_catalog_.table_schema_for(table_oid);
  }

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    return sys_catalog_.table_oid_for(table_name);
  }

  TableColumn
  table_column_for(column_oid_t column_oid) {
    return sys_catalog_.table_column_for(column_oid);
  }

  vector<TableColumn>&
  table_columns_for(const table_name_t& table_name) {
    return sys_catalog_.table_columns_for(table_name);
  }

  const vector<TableColumn>&
  table_columns_for(const table_name_t& table_name) const {
    return sys_catalog_.table_columns_for(table_name);
  }

  IndexSchema&
  index_schema_for(index_oid_t index_oid) {
    return sys_catalog_.index_schema_for(index_oid);
  }

  const IndexSchema&
  index_schema_for(index_oid_t index_oid) const {
    return sys_catalog_.index_schema_for(index_oid);
  }

  IndexSchema&
  index_schema_for(const index_name_t& index_name) {
    return sys_catalog_.index_schema_for(index_name);
  }

  const IndexSchema&
  index_schema_for(const index_name_t& index_name) const {
    return sys_catalog_.index_schema_for(index_name);
  }

  vector<table_name_t>
  table_names() const {
    return sys_catalog_.table_names();
  }

  QuerySchema
  show_tables_schema() const;

  QuerySchema
  describe_table_schema() const;

  QuerySchema
  query_schema_for(const table_name_t& table_name,
                   const ColumnListExpr& column_list) const;

  QuerySchema
  query_schema_for(table_oid_t table_oid) const;

  QuerySchema
  query_schema_for(const table_name_t& table_name) const;

  QuerySchema
  query_schema_for(const vector<string>& table_names,
                   const ColumnListExpr& column_list) const;

  QueryColumn
  query_column_for(const table_name_t& table_name,
                   const column_name_t& column_name) const;

  QueryColumn
  query_column_for(const vector<table_name_t>& table_names,
                   const column_name_t& column_name) const;

  vector<QueryColumn>
  all_columns_for(const vector<table_name_t>& table_names) const;

  vector<QueryColumn>
  all_columns_for(const table_name_t& table_name) const;

  vector<QueryColumn>
  all_columns_for(table_oid_t table_oid) const;

  bool
  load_column_oid(column_oid_t oid, TableColumn&& column);

private:
  SystemCatalog sys_catalog_;
};
