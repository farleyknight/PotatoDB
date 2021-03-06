#pragma once

#include "query/query_comp.hpp"
#include "plans/query_schema_plan.hpp"
#include "plans/maybe_pred_plan.hpp"

class NestedLoopJoinPlan : public BasePlan,
                           public QuerySchemaPlan,
                           public MaybePredPlan
{
public:
  NestedLoopJoinPlan(QuerySchema schema,
                     ptr<BasePlan>&& left_child,
                     ptr<BasePlan>&& right_child)
    : BasePlan        (PlanType::LOOP_JOIN),
      QuerySchemaPlan (schema),
      left_child_     (move(left_child)),
      right_child_    (move(right_child)) {}

  NestedLoopJoinPlan(QuerySchema schema,
                     ptr<BasePlan>&& left_child,
                     ptr<BasePlan>&& right_child,
                     ptr<QueryWhere>&& pred)
    : BasePlan        (PlanType::LOOP_JOIN),
      QuerySchemaPlan (schema),
      MaybePredPlan   (move(pred)),
      left_child_     (move(left_child)),
      right_child_    (move(right_child))
   {}

  QuerySchema
  left_schema() const {
    return dynamic_cast<QuerySchemaPlan*>(left_child_.get())->schema();
  }

  QuerySchema
  right_schema() const {
    return dynamic_cast<QuerySchemaPlan*>(right_child_.get())->schema();
  }

  ptr<BasePlan>&&
  left_plan() {
    return move(left_child_);
  }

  ptr<BasePlan>&&
  right_plan() { return move(right_child_); }

  bool is_query() const {
    return true;
  }

private:
  ptr<BasePlan> left_child_, right_child_;
};
