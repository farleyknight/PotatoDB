#pragma once

#include <memory>

#include "common/config.hpp"

#include "catalog/schema_mgr.hpp"
#include "catalog/table_schema.hpp"
#include "catalog/table_meta.hpp"

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

  TableSchema make_schema_from(const string& table_name,
                               table_oid_t table_oid,
                               ColumnDefListExpr column_list);

  void create_table(UNUSED Txn& txn,
                    const string& table_name,
                    ColumnDefListExpr column_list);

  table_oid_t table_oid_for(const string& table_name) const {
    return table_oids_.at(table_name);
  }

  QuerySchema query_schema_for(vector<string> table_names,
                               const ColumnListExpr& column_list)
  {
    // TODO: Support the * expression
    vector<QueryColumn> columns;
    for (const auto column : column_list.list()) {
      if (column.has_table_name()) {
        columns.push_back(QueryColumn(...));
      } else {
        auto column_info = column_for(table_names, column->name());
        columns.push_back(QueryColumn(...));
      }
    }

    return QuerySchema(columns);
  }

  QueryColumn column_for(vector<string> table_names, const string& column_name) {
    vector<QueryColumn> candidates;
    for (const auto &table_name : table_names) {
      if (table_has_column_named(table_name, column_name)) {
        auto query_column = table_column_for(table_name, column_name);
        candidates.push_back(query_column);
      }
    }

    if (candidates.size() == 0) {
      // TODO Create new exception type
      // message = "No column named " + column_name + " in the tables given in the query"
      throw NoColumnsNamedException(column_name);
    } else if (candidates.size() > 1) {
      // TODO: Give a better error message that shows the list of all tables that have
      // a matching column name.
      // message = "More than one table has a column named " + column_name;
      throw MoreThanOneColumnException(column_name);
    } else {
      return candidates[0];
    }
  }

  void register_index(Txn& txn,
                      const string table_name,
                      const string index_name,
                      SchemaRef schema_ref);

  const QuerySchema& find_query_schema(table_oid_t table_oid) const {
    return schema_mgr_.query_schema_for(table_oid);
  }

  const QuerySchema& find_query_schema(SchemaRef schema_ref) const {
    if (schema_ref.is_query_schema()) {
      return schema_mgr_.query_schema_for(schema_ref);
    } else if (schema_ref.is_table_schema()) {
      return schema_mgr_.as_query_schema(schema_ref);
    } else {
      throw NotImplementedException("could not handle schema type!");
    }
  }

private:
  SchemaMgr schema_mgr_;

  MutMap<string, table_oid_t> table_oids_;
  Atomic<table_oid_t> next_table_oid_ = 0;
  MutMap<table_oid_t, TableSchema> table_schemas_;

  MutMap<string,
         MutMap<string, index_oid_t>> index_oids_;
  Atomic<index_oid_t> next_index_oid_ = 0;
  MutMap<index_oid_t, SchemaRef> index_schema_refs_;
};
