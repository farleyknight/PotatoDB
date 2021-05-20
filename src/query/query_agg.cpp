#include "catalog/query_schema.hpp"

#include "query/query_agg.hpp"
#include "query/query_group_by.hpp"

QueryAgg::QueryAgg(QueryColumn col, AggType agg_type)
  : BaseQuery (QueryNodeType::AGG, col.type_id()),
    col_      (col),
    agg_type_ (agg_type)
{}

Value QueryAgg::eval_agg(const QuerySchema& schema,
                         UNUSED const vector<Value>& group_bys,
                         const vector<Value>& aggregates) const
{
  auto index = schema.index_for(col_.name());
  return aggregates[index];
}

Value QueryAgg::eval(const Tuple& tuple,
                     const QuerySchema& schema) const
{
  std::cout << "Got column " << col_.to_string() << std::endl;
  return col_.eval(tuple, schema);
}

Value QueryAgg::eval_join(UNUSED const Tuple& lt,
                          UNUSED const QuerySchema& ls,
                          UNUSED const Tuple& rt,
                          UNUSED const QuerySchema& rs) const
{
  throw NotImplementedException("eval_join not implemented");
}

const string QueryAgg::to_string() const {
  // TODO! Needs to be fleshed out a bit more
  return "Query Agg for : " + col_.name();
}
