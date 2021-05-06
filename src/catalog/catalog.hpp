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
