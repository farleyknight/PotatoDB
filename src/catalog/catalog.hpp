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

class SchemaRef;
class SchemaManager;

class Catalog {
public:
  Catalog();

  // No copy
  Catalog(const Catalog&) = delete;
  // No copy assign
  Catalog& operator=(const Catalog&) = delete;
  // Default delete
  ~Catalog() = default;

  TableSchema make_schema_from(const table_name_t& table_name,
                               table_oid_t table_oid,
                               const ColumnDefListExpr& column_list);

  void create_table(UNUSED Txn& txn,
                    const string& table_name,
                    ColumnDefListExpr column_list);

  table_oid_t table_oid_for(const string& table_name) const {
    return table_oids_.at(table_name);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name);

  QuerySchema
  query_schema_for(table_oid_t table_oid);

  QuerySchema
  query_schema_for(const vector<string>& table_names,
                   const ColumnListExpr& column_list);

  QueryColumn
  query_column_for(const table_name_t& table_name,
                   const column_name_t& column_name);

  QueryColumn
  query_column_for(const vector<table_name_t>& table_names,
                   const column_name_t& column_name);

  void create_index(Txn& txn,
                    const string table_name,
                    const string index_name);
  vector<QueryColumn> all_columns_for(const vector<table_name_t>& table_names);
  vector<QueryColumn> all_columns_for(const table_name_t& table_name);
  vector<QueryColumn> all_columns_for(table_oid_t table_oid);

private:
  MutMap<table_name_t, table_oid_t> table_oids_;
  Atomic<table_oid_t> next_table_oid_ = 0;
  MutMap<table_oid_t, TableSchema> table_schemas_;
  // MutMap<column_name_t, vector<table_oid_t>> column_name_to_table_oids_;

  MutMap<table_name_t,
         MutMap<index_name_t, index_oid_t>> index_oids_;
  Atomic<index_oid_t> next_index_oid_ = 0;
};
