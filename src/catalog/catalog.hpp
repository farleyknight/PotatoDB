#pragma once

#include <memory>

#include "common/config.hpp"

#include "buffer/table_mgr.hpp"
#include "buffer/index_mgr.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/table_meta.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/create_index_expr.hpp"
#include "exprs/column_list_expr.hpp"
#include "exprs/column_def_list_expr.hpp"

#include "txns/lock_mgr.hpp"

#include "index/base_index.hpp"

#include "server/statement_result.hpp"
#include "server/system_catalog.hpp"

// TODO:
// I'm thinking about renaming `Catalog` to `SchemaMgr` since it
// seems to be handling a lot of details related to the schema objects.
//
// If that does happen, then we would have to figure out what exactly
// `SystemCatalog` is responsible for.
//
class Catalog {
public:
  Catalog(FileMgr& file_mgr,
          LockMgr& lock_mgr,
          LogMgr& log_mgr,
          BuffMgr& buff_mgr)
    : table_mgr_   (file_mgr, lock_mgr, log_mgr, buff_mgr),
      index_mgr_   (file_mgr, lock_mgr, log_mgr, buff_mgr),
      sys_catalog_ (table_mgr_)
  {}

  // No copy
  Catalog(const Catalog&) = delete;
  // No copy assign
  Catalog& operator=(const Catalog&) = delete;
  // Default deletedd
  ~Catalog() = default;

  vector<TableColumn>
  table_columns_for(vector<column_oid_t> column_oids) {
    vector<TableColumn> columns;
    for (const auto oid : column_oids) {
      columns.push_back(table_column_for(oid));
    }
    return columns;
  }

  bool has_table_named(const table_name_t& table_name) const {
    return sys_catalog_.has_table_named(table_name);
  }

  const table_name_t table_name_for(table_oid_t table_oid) const {
    return sys_catalog_.table_name_for(table_oid);
  }

  bool table_has_column_named(const table_name_t& table_name,
                              const column_name_t& column_name) const {
    return sys_catalog_.table_has_column_named(table_name, column_name);
  }

  table_oid_t
  create_table(const CreateTableExpr& expr, UNUSED Txn& txn) {
    auto table_name   = expr.table().name();
    auto table_oid    = sys_catalog_.create_table(expr);
    auto table_schema = sys_catalog_.table_schema_for(table_oid);
    // TODO: The `table_mgr_` needs a reference to the new TableSchema
    // that was made in order to write it to the first block of the file.
    table_mgr_.create_table(table_name, table_schema, table_oid, txn);
    return table_oid;
  }

  void load_table(table_oid_t table_oid, const TableSchema& schema) {
    sys_catalog_.load_table(table_oid, schema);
  }

  void load_index(index_oid_t index_oid, const IndexSchema& schema) {
    sys_catalog_.load_index(index_oid, schema);
  }

  index_oid_t
  create_index(const CreateIndexExpr& expr, UNUSED Txn& txn) {
    auto index_name   = expr.table().name();
    auto index_oid    = sys_catalog_.create_index(expr);
    auto index_schema = sys_catalog_.index_schema_for(index_oid);

    index_mgr_.create_index(index_name, index_schema, index_oid);
    return index_oid;
  }

  // NOTE: TableSchema can change it's auto-increment value, thus it cannot be
  // return as a const ref.
  TableSchema&
  table_schema_for(table_oid_t table_oid) {
    return sys_catalog_.table_schema_for(table_oid);
  }

  const TableSchema&
  table_schema_for(table_oid_t table_oid) const {
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

private:
  // Table Heaps
  TableMgr table_mgr_;
  // B-Trees
  IndexMgr index_mgr_;
  // Table & Index Schemas
  SystemCatalog sys_catalog_;
};
