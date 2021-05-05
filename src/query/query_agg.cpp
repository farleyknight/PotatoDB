#include "catalog/query_schema.hpp"

#include "query/query_agg.hpp"
#include "query/query_group_by.hpp"

QueryAgg::QueryAgg(BaseQuery node, AggType agg_type)
  : BaseQuery (node.type_id()),
    agg_type_ (agg_type) {}

Value QueryAgg::eval_agg(const QuerySchema& schema,
                         UNUSED const vector<Value>& group_bys,
                         const vector<Value>& aggregates) const
{
  auto index = schema.column_oid_for(node_.name());
  return aggregates[index];
}

Value QueryAgg::eval(UNUSED const Tuple& tuple,
                     UNUSED const QuerySchema& schema) const {
  throw NotImplementedException("eval not implemented");
}

Value QueryAgg::eval_join(UNUSED const Tuple& lt,
                          UNUSED const QuerySchema& ls,
                          UNUSED const Tuple& rt,
                          UNUSED const QuerySchema& rs) const
{
  throw NotImplementedException("eval_join not implemented");
}

const string QueryAgg::to_string() const {
  throw NotImplementedException("to_string not implemented for QueryAgg");
}
