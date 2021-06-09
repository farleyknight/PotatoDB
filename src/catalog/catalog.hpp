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

  TableColumn
  create_table_column(const column_name_t& column_name) {

  }

  table_oid_t table_oid_for(const column_name_t& table_name) const {
    return table_oids_.at(table_name);
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

  void load_from_query(const table_name_t& table_name,
                       StatementResult& result);

private:
  map<table_name_t, table_oid_t> table_oids_;
  atomic<table_oid_t> next_table_oid_ = 0;
  map<table_oid_t, TableSchema> table_schemas_;

  atomic<column_oid_t> next_column_oid_ = 0;
  // MutMap<column_name_t, vector<table_oid_t>> column_name_to_table_oids_;

  map<table_name_t,
      map<index_name_t, index_oid_t>> index_oids_;
  atomic<index_oid_t> next_index_oid_ = 0;
};
