#include "plans/agg_plan.hpp"

AggPlan::AggPlan(QuerySchema      schema,
                 ptr<BasePlan>&&  child,
                 vector<QueryAgg> aggs)
  : BasePlan        (PlanType::AGG),
    HasChildPlan    (move(child)),
    QuerySchemaPlan (schema),
    aggs_           (aggs)
{
  assert(child_ != nullptr);
  build_agg_types();
}

AggPlan::AggPlan(QuerySchema           schema,
                 ptr<BasePlan>&&       child,
                 vector<QueryAgg>      aggs,
                 vector<QueryGroupBy>  group_bys)
  : BasePlan        (PlanType::AGG),
    HasChildPlan    (move(child)),
    QuerySchemaPlan (schema),
    aggs_           (aggs),
    group_bys_      (group_bys)
{
  assert(child_ != nullptr);
  build_agg_types();
}

AggPlan::AggPlan(QuerySchema schema,
                 ptr<BasePlan>&&     child,
                 vector<QueryAgg>     aggs,
                 vector<QueryGroupBy> group_bys,
                 ptr<QueryHaving>&&  having)
  : BasePlan        (PlanType::AGG),
    HasChildPlan    (move(child)),
    QuerySchemaPlan (schema),
    aggs_           (aggs),
    group_bys_      (group_bys),
    having_         (move(having))
{
  assert(child_ != nullptr);
  build_agg_types();
}

void AggPlan::build_agg_types() {
  assert(aggs_.size() > 0);
  for (auto &agg : aggs_) {
    agg_types_.emplace_back(agg.agg_type());
  }
}
