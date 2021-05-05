#pragma once

#include "query/query_comp.hpp"

class NestedLoopJoinPlan : public BasePlan {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  NestedLoopJoinPlan(SchemaRef schema_ref,
                     ptr<BasePlan>&& left_child,
                     ptr<BasePlan>&& right_child)
    : BasePlan     (schema_ref),
      left_child_  (move(left_child)),
      right_child_ (move(right_child)) {}

  NestedLoopJoinPlan(SchemaRef schema_ref,
                     ptr<BasePlan>&& left_child,
                     ptr<BasePlan>&& right_child,
                     ptr<QueryComp>&& pred)
    : BasePlan     (schema_ref),
      left_child_  (move(left_child)),
      right_child_ (move(right_child)),
      pred_        (move(pred)) {}

  bool has_pred() {
    return pred_ != nullptr;
  }

  const QueryComp& pred() {
    return *pred_;
  }

  PlanType type()              const { return PlanType::LOOP_JOIN; }

  SchemaRef left_schema_ref()  const { return left_child_->schema_ref(); }
  SchemaRef right_schema_ref() const { return right_child_->schema_ref(); }

  ptr<BasePlan>&& left_plan()      { return move(left_child_); }
  ptr<BasePlan>&& right_plan()     { return move(right_child_); }

private:
  ptr<BasePlan> left_child_;
  ptr<BasePlan> right_child_;
  ptr<QueryComp> pred_;
};
