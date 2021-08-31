// TODO: Probably want to move this file to under `catalog/`

#pragma once

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/index_schema.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/create_index_expr.hpp"
#include "exprs/column_def_expr.hpp"

#include "server/statement_result.hpp"

#include "txns/txn.hpp"

// TODO:
// Big refactor needed!
// We are doing too much SQL in here.
// We don't need to convert system internal stuff into SQL queries.
// We should just interface with the buffer pool pages directly.
// That would make this stuff faster.

class SystemCatalog {
public:
  SystemCatalog() {}

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    assert(table_oids_.count(table_name) > 0);
    return table_oids_.at(table_name);
  }

  index_oid_t
  index_oid_for(const index_name_t& index_name) const {
    assert(index_oids_.count(index_name) > 0);
    return index_oids_.at(index_name);
  }

  table_name_t
  table_name_for(table_oid_t table_oid) const {
    assert(table_names_.count(table_oid) > 0);
    return table_names_.at(table_oid);
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
    assert(table_schemas_.count(table_oid) > 0);
    return table_schemas_.at(table_oid);
  }

  const TableSchema&
  table_schema_for(table_oid_t table_oid) const {
    assert(table_schemas_.count(table_oid) > 0);
    return table_schemas_.at(table_oid);
  }

  IndexSchema&
  index_schema_for(index_oid_t index_oid) {
    assert(index_schemas_.count(index_oid) > 0);
    return index_schemas_.at(index_oid);
  }

  const IndexSchema&
  index_schema_for(index_oid_t index_oid) const {
    assert(index_schemas_.count(index_oid) > 0);
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
  has_table_named(const table_name_t& table_name) const;

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const;

  table_oid_t create_table(const CreateTableExpr& expr);
  index_oid_t create_index(const CreateIndexExpr& expr);

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

private:
  // Columns
  map<column_name_t, column_oid_t> column_oids_;
  // TODO: Maybe we should store TableColumns in a `map`?
  atomic<column_oid_t> next_column_oid_ = 0;

  // Indexes
  map<index_name_t, index_oid_t> index_oids_;
  map<index_oid_t, IndexSchema> index_schemas_;
  atomic<index_oid_t> next_index_oid_ = 0;

  // Tables
  map<table_name_t, table_oid_t> table_oids_;
  map<table_oid_t, table_name_t> table_names_; // Reverse mapping
  map<table_oid_t, TableSchema> table_schemas_;
  atomic<table_oid_t> next_table_oid_ = 0;
};

