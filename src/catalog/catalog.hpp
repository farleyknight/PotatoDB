#pragma once

#include <memory>

#include "catalog/schema_mgr.hpp"
#include "catalog/table_schema.hpp"
#include "catalog/table_meta.hpp"
#include "catalog/index_meta.hpp"

#include "common/config.hpp"

#include "txns/lock_mgr.hpp"

#include "index/base_index.hpp"

class SchemaRef;
class SchemaManager;

class Catalog {
public:
  /**********************************************
  * Constructors & destructor
  **********************************************/
  Catalog() {}

  // No copy
  Catalog(CRef<Catalog>) = delete;
  // No copy assign
  Catalog& operator=(CRef<Catalog>) = delete;
  // Default delete
  ~Catalog() = default;

  void register_table(Txn& txn,
                      String table_name,
                      SchemaRef schema_ref);

  table_oid_t table_oid_for(CRef<String> table_name) const {
    return table_oids_.at(table_name);
  }

  SchemaRef table_schema_ref_for(CRef<String> table_name) const {
    return table_schema_refs_.at(table_oid_for(table_name));
  }

  void register_index(Txn& txn,
                      String table_name,
                      String index_name,
                      SchemaRef schema_ref);

  CRef<QuerySchema> find_query_schema(table_oid_t table_oid) const {
    return schema_mgr_.query_schema_for(table_oid);
  }

  CRef<QuerySchema> find_query_schema(SchemaRef schema_ref) const {
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

  MutMap<MutString, table_oid_t> table_oids_;
  Atomic<table_oid_t> next_table_oid_ = 0;
  MutMap<table_oid_t, SchemaRef> table_schema_refs_;

  MutMap<MutString,
         MutMap<MutString, index_oid_t>> index_oids_;
  Atomic<index_oid_t> next_index_oid_ = 0;
  MutMap<index_oid_t, SchemaRef> index_schema_refs_;
};
