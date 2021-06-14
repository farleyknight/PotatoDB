#pragma once

#include <memory>

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/table_meta.hpp"

#include "exprs/column_list_expr.hpp"
#include "exprs/column_def_list_expr.hpp"

#include "txns/lock_mgr.hpp"

#include "index/base_index.hpp"
#include "index/index_meta.hpp"

#include "server/statement_result.hpp"


// TODO:
// I'm thinking about renaming `Catalog` to `SchemaMgr` since it seems to be
// handling a lot of details related to the schema objects.
//
// If that does happen, then we would have to figure out what exactly
// `SystemCatalog` is responsible for.
//
class Catalog {
public:
  Catalog();

  // No copy
  Catalog(const Catalog&) = delete;
  // No copy assign
  Catalog& operator=(const Catalog&) = delete;
  // Default delete
  ~Catalog() = default;

  TableSchema
  make_schema_from(const table_name_t& table_name,
                   table_oid_t table_oid,
                   const string& primary_key,
                   const ColumnDefListExpr& column_list) const;

  table_oid_t
  create_table(Txn& txn,
               const table_name_t& table_name,
               const column_name_t& primary_key,
               ColumnDefListExpr column_list);

  table_oid_t table_oid_for(const table_name_t& table_name) const {
    return table_oids_.at(table_name);
  }

  table_name_t table_name_for(table_oid_t table_oid) const {
    return table_names_.at(table_oid);
  }

  TableSchema& table_schema_for(table_oid_t table_oid) {
    return table_schemas_.at(table_oid);
  }

  bool
  has_table_named(const table_name_t& table_name) const;

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const;

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

  void create_index(Txn& txn,
                    const string table_name,
                    const string index_name);

  vector<QueryColumn>
  all_columns_for(const vector<table_name_t>& table_names) const;

  vector<QueryColumn>
  all_columns_for(const table_name_t& table_name) const;

  vector<QueryColumn>
  all_columns_for(table_oid_t table_oid) const;

  void load_from_query(table_oid_t table_oid,
                       const table_name_t& table_name,
                       StatementResult& result);

  void load_table(table_oid_t table_oid,
                  const table_name_t& table_name,
                  const TableSchema& schema);

private:
  // I'm thinking that these two instance variables should be long to
  // `SystemCatalog`
  map<table_name_t, table_oid_t> table_oids_;
  map<table_oid_t, table_name_t> table_names_;

  atomic<table_oid_t> next_table_oid_ = 0;

  // I'm thinking this instance variable should stay here, in `Catalog`
  // (or `SchemaMgr` if I rename it)
  map<table_oid_t, TableSchema> table_schemas_;

  // I'm thinking that these two instance variables should be long to
  // `SystemCatalog`
  atomic<column_oid_t> next_column_oid_ = 0;
  map<column_name_t, column_oid_t> column_oids_;

  map<table_name_t,
      map<index_name_t, index_oid_t>> index_oids_;
  atomic<index_oid_t> next_index_oid_ = 0;
};
