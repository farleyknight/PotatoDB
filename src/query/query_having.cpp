
#include "query/query_having.hpp"
#include "tuple/tuple.hpp"

QueryHaving::QueryHaving(TypeId type_id,
                         BaseQuery having_clause)
  : BaseQuery      (type_id),
    having_clause_ (having_clause) {}


Value QueryHaving::eval_agg(CRef<QuerySchema> schema,
                            UNUSED CRef<Vec<Value>> group_bys,
                            CRef<Vec<Value>> aggs) const
{
  // TODO: This should evaluate the having_clause_ predicate on
  // the group_bys tuple? The comparison expression takes a
  // tuple and a schema!
  vector<Value> values;
  for (const auto &agg_value : aggs) {
    values.emplace_back(agg_value);
  }

  return having_clause_.eval(Tuple(values, schema), schema);
}
