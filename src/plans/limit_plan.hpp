#pragma once

#include "plans/base_plan.hpp"

class LimitPlan : public BasePlan {
public:

  /**********************************************
   * Constructors & destructor
   **********************************************/

  LimitPlan(SchemaRef schema_ref,
            BasePlan child,
            size_t limit,
            size_t offset)
   : BasePlan (schema_ref),
     limit_   (limit),
     offset_  (offset),
     child_   (child)
  {}

  /**********************************************
   * Instance methods
   **********************************************/

  PlanType type()  const { return PlanType::LIMIT; }
  size_t limit()   const { return limit_; }
  size_t offset()  const { return offset_; }

private:
  size_t limit_;
  size_t offset_;
  BasePlan child_;
};
