#include "buffer/buff_mgr.hpp"

#include "common/config.hpp"

#include "catalog/catalog.hpp"
#include "catalog/table_meta.hpp"
#include "catalog/index_meta.hpp"

#include "txns/lock_mgr.hpp"

/*************************************
 * TODO: Doc me!
 *************************************/

Catalog::Catalog()
  : schema_mgr_ (*this) {}

/*************************************
 * TODO: Doc me!
 *************************************/

void Catalog::register_table(UNUSED Txn& txn,
                             String table_name,
                             SchemaRef schema_ref)
{
  assert(table_oids_.count(table_name) == 0);

  table_oid_t table_oid = next_table_oid_++;
  table_oids_[table_name] = table_oid;
  table_schema_refs_.emplace(table_oid, schema_ref);

  index_oids_.emplace(table_name,
                      MutMap<MutString, index_oid_t>());
}


/*************************************
 * TODO: Doc me!
 *************************************/

void Catalog::register_index(UNUSED Txn& txn,
                             String index_name,
                             String table_name,
                             SchemaRef schema_ref)
{
  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(table_name) == 1);
  assert(index_oids_[table_name].count(index_name) == 0);

  index_oid_t index_oid = next_index_oid_++;
  index_oids_[table_name][index_name] = index_oid;
  index_schema_refs_.emplace(index_oid, schema_ref);
}
