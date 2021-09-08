#pragma once

// TODO: Probably want to move this file to under `catalog/`

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/index_schema.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/create_index_expr.hpp"
#include "exprs/column_def_expr.hpp"

#include "server/statement_result.hpp"

#include "buffer/table_mgr.hpp"
#include "buffer/index_mgr.hpp"

#include "txns/txn.hpp"

// TODO:
// Big refactor needed!
// We are doing too much SQL in here.
// We don't need to convert system internal stuff into SQL queries.
// We should just interface with the buffer pool pages directly.
// That would make this stuff faster.

// TODO: Maybe rename to SchemaMgr?
// I feel like that fits my general naming conventions.
// The TableMgr has TableHeaps
// The IndexMgr has BPlusTrees
// The TxnMgr has Txns
// The BuffMgr has Page/Buffer objects

class SystemCatalog {
public:
  SystemCatalog(FileMgr& file_mgr,
                LockMgr& lock_mgr,
                LogMgr& log_mgr,
                BuffMgr& buff_mgr)
    : table_mgr_ (file_mgr, lock_mgr, log_mgr, buff_mgr),
      index_mgr_ (file_mgr, lock_mgr, log_mgr, buff_mgr)
  {}

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    return table_mgr_.table_oid_for(table_name);
  }

  index_oid_t
  index_oid_for(const index_name_t& index_name) const {
    return index_mgr_.index_oid_for(index_name);
  }

  table_name_t
  table_name_for(table_oid_t table_oid) const {
    return table_mgr_.table_name_for(table_oid);
  }

  TableSchema&
  table_schema_for(const table_name_t table_name) {
    return table_schema_for(table_oid_for(table_name));
  }

  const TableSchema&
  table_schema_for(const table_name_t table_name) const {
    return table_schema_for(table_oid_for(table_name));
  }

  TableSchema&
  table_schema_for(table_oid_t table_oid) {
    return table_mgr_.table_schema_for(table_oid);
  }

  const TableSchema&
  table_schema_for(table_oid_t table_oid) const {
    return table_mgr_.table_schema_for(table_oid);
  }

  IndexSchema&
  index_schema_for(index_oid_t index_oid) {
    return index_mgr_.index_schema_for(index_oid);
  }

  const IndexSchema&
  index_schema_for(index_oid_t index_oid) const {
    return index_mgr_.index_schema_for(index_oid);
  }

  IndexSchema&
  index_schema_for(const index_name_t index_name) {
    return index_schema_for(index_oid_for(index_name));
  }

  const IndexSchema&
  index_schema_for(const index_name_t index_name) const {
    return index_schema_for(index_oid_for(index_name));
  }

  bool
  has_table_named(const table_name_t& table_name) const {
    return table_mgr_.has_table_named(table_name);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const {
    return table_mgr_.table_has_column_named(table_name, column_name);
  }

  void
  load_table(file_id_t file_id,
             table_oid_t table_oid,
             const table_name_t table_name,
             const TableSchema schema)
  {
    table_mgr_.load_table(file_id, table_oid, table_name, schema);
  }

  void
  load_index(file_id_t file_id,
             index_oid_t index_oid,
             const index_name_t& index_name,
             const IndexSchema& schema)
  {
    index_mgr_.load_index(file_id, index_oid, index_name, schema);
  }

  TableColumn
  make_column_from(table_oid_t table_oid,
                   column_oid_t column_oid,
                   const ColumnDefExpr& expr) const
  {
    return table_mgr_.make_column_from(table_oid, column_oid, expr);
  }

  column_oid_t
  make_column_oid(const table_name_t& table_name,
                  const column_name_t& column_name)
  {
    return table_mgr_.make_column_oid(table_name, column_name);
  }

  TableSchema
  make_schema_from(table_oid_t table_oid,
                   const CreateTableExpr& expr)
  {
    return table_mgr_.make_schema_from(table_oid, expr);
  }

  table_oid_t
  create_table_schema(const CreateTableExpr& expr) {
    return table_mgr_.create_table_schema(expr);
  }

  index_oid_t
  create_index_schema(file_id_t file_id,
                      const CreateIndexExpr& expr)
  {
    auto table_name   = expr.table().name();
    auto table_oid    = table_oid_for(table_name);

    auto column_names = expr.indexed_columns().list();
    vector<column_oid_t> column_oids;
    for (const auto& column_name : column_names) {
      auto column_oid = table_mgr_.column_oid_for(table_name, column_name);
      column_oids.push_back(column_oid);
    }

    return index_mgr_.create_index_schema(file_id, table_oid, column_oids, expr);
  }

  TableColumn
  table_column_for(column_oid_t column_oid) {
    return table_mgr_.column_for(column_oid);
  }

  void build_system_catalog() {
    table_mgr_.load_all_tables();
    index_mgr_.load_all_indexes();
  }

private:
  TableMgr table_mgr_;
  IndexMgr index_mgr_;
};
