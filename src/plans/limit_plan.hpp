#pragma once

#include "plans/base_plan.hpp"

class LimitPlan : public BasePlan {
public:

  /**********************************************
   * Constructors & destructor
   **********************************************/

  LimitPlan(ptr<BasePlan> child,
            size_t limit,
            size_t offset)
    : BasePlan (PlanType::LIMIT),
      child_   (move(child)),
      limit_   (limit),
      offset_  (offset)
  {}

  /**********************************************
   * Instance methods
   **********************************************/

  size_t limit()      const { return limit_; }
  size_t offset()     const { return offset_; }
  ptr<BasePlan>&& child() { return move(child_); }

private:
  ptr<BasePlan> child_;
  size_t limit_;
  size_t offset_;
};
