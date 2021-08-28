// TODO: Probably want to move this file to under `catalog/`

#pragma once

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/index_schema.hpp"
#include "exprs/column_def_expr.hpp"

// TODO:
// Big refactor needed!
// We are doing too much SQL in here.
// We don't need to convert system internal stuff into SQL queries.
// We should just interface with the buffer pool pages directly.
// That would make this stuff faster.

class SystemCatalog {
public:
  SystemCatalog() {}

  table_oid_t table_oid_for(const table_name_t& table_name) const {
    assert(table_oids_.count(table_name) > 0);
    return table_oids_.at(table_name);
  }

  index_oid_t index_oid_for(const index_name_t& index_name) const {
    assert(index_oids_.count(index_name) > 0);
    return index_oids_.at(index_name);
  }

  table_name_t table_name_for(table_oid_t table_oid) const {
    assert(table_names_.count(table_oid) > 0);
    return table_names_.at(table_oid);
  }

  TableSchema& table_schema_for(const table_name_t table_name) {
    return table_schema_for(table_oid_for(table_name));
  }

  const TableSchema& table_schema_for(const table_name_t table_name) const {
    return table_schema_for(table_oid_for(table_name));
  }

  TableSchema& table_schema_for(table_oid_t table_oid) {
    assert(table_schemas_.count(table_oid) > 0);
    return table_schemas_.at(table_oid);
  }

  const TableSchema& table_schema_for(table_oid_t table_oid) const {
    assert(table_schemas_.count(table_oid) > 0);
    return table_schemas_.at(table_oid);
  }

  IndexSchema& index_schema_for(index_oid_t index_oid) {
    assert(index_schemas_.count(index_oid) > 0);
    return index_schemas_.at(index_oid);
  }

  const IndexSchema& index_schema_for(index_oid_t index_oid) const {
    assert(index_schemas_.count(index_oid) > 0);
    return index_schemas_.at(index_oid);
  }

  IndexSchema& index_schema_for(const index_name_t index_name) {
    return index_schema_for(index_oid_for(index_name));
  }

  const IndexSchema& index_schema_for(const index_name_t index_name) const {
    return index_schema_for(index_oid_for(index_name));
  }

  bool has_table_named(const table_name_t& table_name) const;

  bool table_has_column_named(const table_name_t& table_name,
                              const column_name_t& column_name) const;

  table_oid_t create_table(const CreateTableExpr& expr, Txn& txn);
  index_oid_t create_index(const CreateIndexExpr& expr, Txn& txn);

  void load_from_query(table_oid_t table_oid,
                       const table_name_t& table_name,
                       StatementResult& result);

  void load_table(table_oid_t table_oid,
                  const table_name_t& table_name,
                  const TableSchema& schema);

private:

  TableSchema make_schema_from(const table_name_t& table_name,
                               table_oid_t table_oid,
                               const ColumnDefListExpr& column_list) const;

  map<table_name_t, table_oid_t> table_oids_;
  map<table_oid_t, table_name_t> table_names_;

  atomic<table_oid_t> next_table_oid_ = 0;

  map<table_oid_t, TableSchema> table_schemas_;

  atomic<column_oid_t> next_column_oid_ = 0;

  map<column_name_t, column_oid_t> column_oids_;

  map<index_name_t, index_oid_t> index_oids_;
  atomic<index_oid_t> next_index_oid_ = 0;

  map<index_oid_t, IndexSchema> index_schemas_;
};

