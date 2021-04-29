
#include "plans/agg_plan.hpp"

/**********************************************
 * GroupByExpr and HavingExpr are both optional
 **********************************************/

AggPlan::AggPlan(MovePtr<Schema>   schema,
                 MovePtr<BasePlan> child,
                 MoveVec<AggExpr>  aggs)
  : BasePlan (move(schema)),
    child_   (move(child)),
    aggs_    (move(aggs))
{
  build_agg_types();
}

Ptr<BasePlan> AggPlan::make(MovePtr<Schema> schema,
                            MovePtr<BasePlan> child,
                            MoveVec<AggExpr> aggs)
{
  return make_unique<AggPlan>(move(schema),
                              move(child),
                              move(aggs));
}

/**********************************************
 * HavingExpr is optional
 **********************************************/

AggPlan::AggPlan(MovePtr<Schema>      schema,
                 MovePtr<BasePlan>    child,
                 MoveVec<AggExpr>     aggs,
                 MoveVec<GroupByExpr> group_bys)
  : BasePlan   (move(schema)),
    child_     (move(child)),
    aggs_      (move(aggs)),
    group_bys_ (move(group_bys))
{
  build_agg_types();
}

static Ptr<BasePlan> make(MovePtr<Schema> schema,
                          MovePtr<BasePlan> child,
                          MoveVec<AggExpr> aggs,
                          MoveVec<GroupByExpr> group_bys)
{
  return make_unique<AggPlan>(move(schema),
                              move(child),
                              move(aggs),
                              move(group_bys));
}

/**********************************************
 * All child exprs required
 **********************************************/

AggPlan::AggPlan(MovePtr<Schema>      schema,
                 MovePtr<BasePlan>    child,
                 MoveVec<AggExpr>     aggs,
                 MoveVec<GroupByExpr> group_bys,
                 MovePtr<HavingExpr>  having)
  : BasePlan   (move(schema)),
    child_     (move(child)),
    aggs_      (move(aggs)),
    group_bys_ (move(group_bys)),
    having_    (move(having))
{
  build_agg_types();
}

Ptr<BasePlan> AggPlan::make(MovePtr<Schema>      schema,
                            MovePtr<BasePlan>    child,
                            MoveVec<AggExpr>     aggs,
                            MoveVec<GroupByExpr> group_bys,
                            MovePtr<HavingExpr>  having)
{
  return make_unique<AggPlan>(move(schema),
                              move(child),
                              move(aggs),
                              move(group_bys),
                              move(having));
}

void AggPlan::build_agg_types() {
  for (auto &agg : aggs_) {
    agg_types_.emplace_back(agg.agg_type());
  }
}

