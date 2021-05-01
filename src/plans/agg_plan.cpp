
#include "plans/agg_plan.hpp"

AggPlan::AggPlan(SchemaRef         schema,
                 MovePtr<BasePlan> child,
                 MoveVec<AggExpr>  aggs)
  : BasePlan (schema),
    child_   (move(child)),
    aggs_    (move(aggs))
{
  build_agg_types();
}

AggPlan::AggPlan(SchemaRef            schema,
                 MovePtr<BasePlan>    child,
                 MoveVec<AggExpr>     aggs,
                 MoveVec<GroupByExpr> group_bys)
  : BasePlan   (schema),
    child_     (move(child)),
    aggs_      (move(aggs)),
    group_bys_ (move(group_bys))
{
  build_agg_types();
}

AggPlan::AggPlan(SchemaRef            schema,
                 MovePtr<BasePlan>    child,
                 MoveVec<AggExpr>     aggs,
                 MoveVec<GroupByExpr> group_bys,
                 MovePtr<HavingExpr>  having)
  : BasePlan   (schema),
    child_     (move(child)),
    aggs_      (move(aggs)),
    group_bys_ (move(group_bys)),
    having_    (move(having))
{
  build_agg_types();
}

void AggPlan::build_agg_types() {
  for (auto &agg : aggs_) {
    agg_types_.emplace_back(agg.agg_type());
  }
}
