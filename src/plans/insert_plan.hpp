#pragma once

#include "plans/base_plan.hpp"

class InsertPlan : public BasePlan {
public:
  InsertPlan(SchemaRef schema,
             ptr<BasePlan> child)
    : BasePlan   (schema),
      child_     (move(child)),
      table_oid_ (schema.table_oid()) {}

  PlanType type()         const { return PlanType::INSERT; }
  table_oid_t table_oid() const { return table_oid_; }

  ptr<BasePlan>&& child()     { return move(child_); }

private:
  ptr<BasePlan> child_;
  table_oid_t table_oid_;
};
