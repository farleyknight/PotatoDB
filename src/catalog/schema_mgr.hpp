#pragma once

#include "catalog/query_schema.hpp"
#include "catalog/table_schema.hpp"
#include "catalog/schema_ref.hpp"

class Catalog;

// SchemaMgr invariants:
//
// 1)  The schema_oid == table_oid for all tables.
// 2)  For each TableSchema, we keep exactly one QuerySchema, with the same schema_oid
// 2b) Hence for any non-negative integer i, the object `query_schemas[i]` will always
//     the the QuerySchema for the corresponding TableSchema object `table_schemas[i]`
// 3)  Every time that `TableBuilder` is called, we place the result into this manager.
//     => This must be implemented in `TableBuilder`
//
// Future ideas:
// * Because we have copies of schemas, we might be able to optimize certain queries.
// * Logical Query Plans can be cached, onced an optimal query plan is found for
//   some type of query.
//   => In other words, this is a caching structure that will help us build other
//      caching structures throughout the database.
class SchemaMgr {
public:
  SchemaMgr() {}

  bool register_schema(Move<TableSchema> table_schema,
                       table_oid_t table_oid)
  {
    auto query_schema = QuerySchema::copy(table_schema);
    // NOTE: invariant #1
    table_schemas_.emplace(table_oid, move(table_schema));

    // table_schemas_.emplace(table_oid, move(table_schema));
    // NOTE: invariant #2 & 2b
    query_schemas_.emplace(table_oid, move(query_schema));
    return true;
  }

  const QuerySchema& query_schema_for(table_oid_t table_oid) const {
    return query_schemas_.at(table_oid);
  }

  const QuerySchema& as_query_schema(SchemaRef schema_ref) const {
    assert(schema_ref.is_table_schema());
    // NOTE: invariant #2
    return query_schemas_.at(schema_ref.table_oid());
  }

  const QuerySchema& query_schema_for(SchemaRef schema_ref) const {
    return query_schemas_.at(schema_ref.table_oid());
  }

  const TableSchema& table_schema_for(table_oid_t table_oid) const {
    return table_schemas_.at(table_oid);
  }

private:
  MutMap<table_oid_t, Move<QuerySchema>> query_schemas_;
  MutMap<table_oid_t, Move<TableSchema>> table_schemas_;
};
