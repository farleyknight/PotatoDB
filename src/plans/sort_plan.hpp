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

  SortPlan(ptr<BasePlan> child,
           vector<SortDirection> directions)
    : BasePlan    (PlanType::SORT),
      child_      (move(child)),
      directions_ (directions)
  {
    // assert(schema->column_count() == directions_.size());
  }

  ptr<BasePlan>&& child() { return move(child_); }

private:
  ptr<BasePlan> child_;
  vector<SortDirection> directions_;
};
