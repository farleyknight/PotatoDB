#include "query/query_group_by.hpp"
#include "catalog/query_schema.hpp"

QueryGroupBy::QueryGroupBy(TypeId type_id,
                           string column_name)
  : BaseQuery    (QueryNodeType::GROUP_BY, type_id),
    column_name_ (column_name) {}

QueryGroupBy::QueryGroupBy(string column_name)
  : BaseQuery    (QueryNodeType::GROUP_BY, TypeId::INTEGER),
    column_name_ (column_name) {}


Value QueryGroupBy::eval_agg(const QuerySchema& schema,
                             const vector<Value>& group_bys,
                             UNUSED const vector<Value>& aggrs) const
{
  auto index = schema.column_oid_for(column_name_);
  return group_bys[index];
}
