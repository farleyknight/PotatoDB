// TODO: Probably want to move this file to under `catalog/`

#pragma once

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
                TableMgr& table_mgr,
                IndexMgr& index_mgr)
    // TODO: Maybe we can be constructing table_mgr and index_mgr in here?
    // I think that might be a better approach than having PotatoDB own table_mgr
    // and index_mgr.
    : file_mgr_  (file_mgr),
      table_mgr_ (table_mgr),
      index_mgr_ (index_mgr)
  {}

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    return table_mgr_.table_oid_for(table_name);
  }

  index_oid_t
  index_oid_for(const index_name_t& index_name) const {
    assert(index_oids_.count(index_name) > 0);
    return index_oids_.at(index_name);
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
    assert(index_schemas_.contains(index_oid));
    return index_schemas_.at(index_oid);
  }

  const IndexSchema&
  index_schema_for(index_oid_t index_oid) const {
    assert(index_schemas_.contains(index_oid));
    return index_schemas_.at(index_oid);
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
  load_index(index_oid_t index_oid,
             index_name_t index_name,
             const IndexSchema& schema);

  TableColumn
  make_column_from(table_oid_t table_oid,
                   column_oid_t column_oid,
                   const ColumnDefExpr& expr) const;

  column_oid_t
  make_column_oid(const table_name_t& table_name,
                  const column_name_t& column_name);

  TableSchema
  make_schema_from(table_oid_t table_oid,
                   const CreateTableExpr& expr);

  IndexSchema
  make_schema_from(index_oid_t index_oid,
                   const CreateIndexExpr& expr) const;

  table_oid_t
  create_table_schema(const CreateTableExpr& expr);
  index_oid_t
  create_index_schema(const CreateIndexExpr& expr);

  TableColumn
  table_column_for(column_oid_t column_oid) {
    return table_mgr_.column_for(column_oid);
  }

  PageId
  default_root_page_id(table_oid_t table_oid) const {
    auto file_id = table_mgr_.file_id_for(table_oid);
    return PageId(file_id, FileMgr::INDEX_CONTENT_BLOCK_NUM);
  }

  void build_system_catalog() {
    for (const auto file_id : file_mgr_.table_file_ids()) {
      auto table_oid    = table_mgr_.table_oid_for(file_id);
      auto table_name   = table_mgr_.table_name_for(table_oid);
      auto table_schema = table_mgr_.read_table_schema(file_id);
      table_mgr_.load_table(file_id, table_oid, table_name, table_schema);
    }

    for (const auto file_id : file_mgr_.index_file_ids()) {
      auto index_oid    = index_mgr_.index_oid_for(file_id);
      auto index_schema = index_mgr_.read_index_schema(file_id);
      index_mgr_.load_index(index_oid, index_schema);
    }
  }

private:

  // Indexes
  map<index_name_t, index_oid_t> index_oids_;
  map<index_oid_t, IndexSchema> index_schemas_;
  atomic<index_oid_t> next_index_oid_ = FIRST_INDEX_OID;

  FileMgr& file_mgr_;
  TableMgr& table_mgr_;
  UNUSED IndexMgr& index_mgr_;
};
