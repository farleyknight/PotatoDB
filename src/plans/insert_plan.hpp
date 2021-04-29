#pragma once

#include "plans/base_plan.hpp"

class InsertPlan : public BasePlan {
public:
  InsertPlan(BasePlan child,
             table_oid_t table_oid)
    : BasePlan   (SchemaRef::from_table_oid(table_oid)),
      child_     (child),
      table_oid_ (table_oid) {}

  PlanType type()                 const { return PlanType::INSERT; }
  table_oid_t table_oid()         const { return table_oid_; }

private:
  BasePlan child_;
  table_oid_t table_oid_;
};
