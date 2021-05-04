#pragma once

#include "plans/base_plan.hpp"

class LimitPlan : public BasePlan {
public:

  /**********************************************
   * Constructors & destructor
   **********************************************/

  LimitPlan(SchemaRef schema,
            MutPtr<BasePlan> child,
            size_t limit,
            size_t offset)
   : BasePlan (schema),
     child_   (move(child)),
     limit_   (limit),
     offset_  (offset)
  {}

  /**********************************************
   * Instance methods
   **********************************************/

  PlanType type()     const { return PlanType::LIMIT; }
  size_t limit()      const { return limit_; }
  size_t offset()     const { return offset_; }
  MovePtr<BasePlan> child() { return move(child_); }

private:
  MutPtr<BasePlan> child_;
  size_t limit_;
  size_t offset_;
};
