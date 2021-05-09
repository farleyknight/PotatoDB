
#include "catalog/query_builder.hpp"
#include "catalog/query_table.hpp"

QueryTable QueryBuilder::table(const table_name_t table_name) const {
  auto table_oid = catalog_.table_oid_for(table_name);
  return QueryTable(&catalog_, table_oid, table_name);
}
