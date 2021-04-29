#include "catalog/schema.hpp"

#include "exprs/agg_expr.hpp"
#include "exprs/group_by_expr.hpp"

AggExpr::AggExpr(BaseExpr expr, AggType agg_type)
  : BaseExpr  (expr.type_id()),
    agg_type_ (agg_type) {}

Value AggExpr::eval_agg(Ref<QuerySchema> schema,
                        Ref<Vec<Value>> group_bys,
                        Ref<Vec<Value>> aggregates) const
{
  auto index = schema.by_name(expr_.name());
  return aggregates[index];
}

Value AggExpr::eval(Ref<Tuple> tuple, Ref<Schema> schema) const {
  throw NotImplementedException("eval not implemented");
}

Value AggExpr::eval_join(Ref<Tuple> lt,
                         Ref<Schema> ls,
                         Ref<Tuple> rt,
                         Ref<Schema> rs) const
{
  throw NotImplementedException("eval_join not implemented");
}

String AggExpr::to_string() const {
  throw NotImplementedException("to_string not implemented for AggExpr");
}
