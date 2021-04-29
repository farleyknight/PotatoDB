
#include "exprs/having_expr.hpp"
#include "tuple/tuple.hpp"

HavingExpr::HavingExpr(TypeId type_id,
                       Ref<Schema> source_schema,
                       MovePtr<BaseExpr> having_clause)
  : BaseExpr       (type_id),
    source_schema_ (source_schema),
    having_clause_ (move(having_clause)) {}


Ptr<HavingExpr> HavingExpr::make(TypeId type_id,
                                 Ref<Schema> source_schema,
                                 MovePtr<BaseExpr> having_clause)
{
  return make_unique<HavingExpr>(type_id,
                                 source_schema,
                                 move(having_clause));
}


Value HavingExpr::eval_agg(Ref<Vec<Value>> group_bys,
                           Ref<Vec<Value>> aggs) const
{
  // TODO: This should evaluate the having_clause_ predicate on
  // the group_bys tuple? The comparison expression takes a
  // tuple and a schema!
  MutVec<Value> values;
  for (const auto &agg_value : aggs) {
    values.emplace_back(agg_value);
  }

  return having_clause_->eval(Tuple(move(values), source_schema_),
                              source_schema_);
}
