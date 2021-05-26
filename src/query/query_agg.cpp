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
  auto name = agg_type_string() + "(" + col_.name() + ")";
  return "Query Agg : " + name;
}

const string QueryAgg::agg_type_string() const {
  switch (agg_type_) {
  case AggType::COUNT: return "COUNT";
  case AggType::SUM:   return "SUM";
  case AggType::MIN:   return "MIN";
  case AggType::MAX:   return "MAX";
  }
}

const QueryColumn QueryAgg::to_query_column() const {
  if (col_.is_splat() && agg_type_ == AggType::COUNT) {
    return QueryColumn::count_splat();
  }

  auto name = agg_type_string() + "(" + col_.name() + ")";
  return QueryColumn(col_.type_id(),
                     col_.table_oid(),
                     col_.column_oid(),
                     name);
}
