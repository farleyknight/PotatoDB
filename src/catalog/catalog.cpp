#include "buffer/buff_mgr.hpp"

#include "common/config.hpp"

#include "catalog/catalog.hpp"
#include "catalog/table_meta.hpp"

#include "index/index_meta.hpp"
#include "server/potatodb.hpp"
#include "txns/lock_mgr.hpp"

const string system_table_sql =
  "CREATE TABLE system_catalog ( " \

  /*
    "id         INTEGER PRIMARY KEY, " \
    "type       INTEGER NOT NULL, " \
    "name       VARCHAR(32) NOT NULL, " \
    "table_name VARCHAR(32) NOT NULL, " \
    "sql        VARCHAR(255) NOT NULL " \
   */

  ");";


void Catalog::build_catalog_table() {
  // TODO: Use some SQL here
  // 1) Write the necessary SQL [DONE?]
  // 2) Feed it to the parser [DONE?]
  // 3) Parser feeds it to the exec eng [DONE?]

  // potatodb.execute(system_table_sql);

  // 4) Need to add operator for creating a table [TODO]

  // 5) DiskMgr should create a TableFile?
  // 6) TableFile creates TableHeap
  // 7) TableHeap creates TablePage
  // 8) TablePage adds tuples to the `system_catalog`
}

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
