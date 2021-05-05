#pragma once

#include "plans/base_plan.hpp"

enum class SortDirection {
  INVALID = 0,
  ASC     = 1,
  DESC    = 2
};

class SortPlan : public BasePlan {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  SortPlan(SchemaRef schema_ref,
           ptr<BasePlan> child,
           vector<SortDirection> directions)
    : BasePlan    (schema_ref),
      child_      (move(child)),
      directions_ (directions)
  {
    // assert(schema->column_count() == directions_.size());
  }

  PlanType type()     const { return PlanType::SORT; }
  ptr<BasePlan>&& child() { return move(child_); }

private:
  ptr<BasePlan> child_;
  vector<SortDirection> directions_;
};
