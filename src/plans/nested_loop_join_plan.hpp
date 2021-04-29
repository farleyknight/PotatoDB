#pragma once

#include "query/query_comp.hpp"

class NestedLoopJoinPlan : public BasePlan {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  NestedLoopJoinPlan(SchemaRef schema_ref,
                     BasePlan left_child,
                     BasePlan right_child,
                     Option<QueryComp> pred = std::nullopt)
    : BasePlan     (schema_ref),
      left_child_  (left_child),
      right_child_ (right_child),
      pred_        (pred) {}

  bool has_pred() {
    return pred_.has_value();
  }

  CRef<QueryComp> pred() {
    return pred_.value();
  }

  PlanType type()              const { return PlanType::LOOP_JOIN; }

  SchemaRef left_schema_ref()  const { return left_child_.schema_ref(); }
  SchemaRef right_schema_ref() const { return right_child_.schema_ref(); }

 private:
  BasePlan left_child_;
  BasePlan right_child_;
  Option<QueryComp> pred_;
};
