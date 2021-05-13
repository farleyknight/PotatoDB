#include "plans/agg_plan.hpp"

AggPlan::AggPlan(ptr<BasePlan>&& child,
                 MoveVec<QueryAgg> aggs)
  : BasePlan     (PlanType::AGG),
    HasChildPlan (move(child)),
    aggs_        (move(aggs))
{
  build_agg_types();
}

AggPlan::AggPlan(ptr<BasePlan>&&       child,
                 MoveVec<QueryAgg>     aggs,
                 MoveVec<QueryGroupBy> group_bys)
  : BasePlan     (PlanType::AGG),
    HasChildPlan (move(child)),
    aggs_        (move(aggs)),
    group_bys_   (move(group_bys))
{
  build_agg_types();
}

AggPlan::AggPlan(ptr<BasePlan>&&     child,
                 MoveVec<QueryAgg>     aggs,
                 MoveVec<QueryGroupBy> group_bys,
                 ptr<QueryHaving>&&  having)
  : BasePlan     (PlanType::AGG),
    HasChildPlan (move(child)),
    aggs_        (move(aggs)),
    group_bys_   (move(group_bys)),
    having_      (move(having))
{
  build_agg_types();
}

void AggPlan::build_agg_types() {
  for (auto &agg : aggs_) {
    agg_types_.emplace_back(agg.agg_type());
  }
}
