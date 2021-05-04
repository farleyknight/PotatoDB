
#include "catalog/query_builder.hpp"
#include "exprs/table_expr.hpp"

TableExpr QueryBuilder::table(String table_name) const {
  auto table_oid = catalog_.table_oid_for(table_name);
  return TableExpr(table_oid, table_name);
}
