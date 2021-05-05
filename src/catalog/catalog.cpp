#include "catalog/catalog.hpp"

// #include "catalog/table_meta.hpp"
// #include "server/potatodb.hpp"

void Catalog::register_table(UNUSED Txn& txn,
                             const string table_name,
                             SchemaRef schema_ref)
{
  assert(table_oids_.count(table_name) == 0);

  table_oid_t table_oid = next_table_oid_++;
  table_oids_[table_name] = table_oid;
  table_schema_refs_.emplace(table_oid, schema_ref);

  index_oids_.emplace(table_name,
                      MutMap<string, index_oid_t>());
}


void Catalog::register_index(UNUSED Txn& txn,
                             const string index_name,
                             const string table_name,
                             SchemaRef schema_ref)
{
  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(table_name) == 1);
  assert(index_oids_[table_name].count(index_name) == 0);

  index_oid_t index_oid = next_index_oid_++;
  index_oids_[table_name][index_name] = index_oid;
  index_schema_refs_.emplace(index_oid, schema_ref);
}
