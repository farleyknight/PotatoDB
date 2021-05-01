#pragma once

#include "plans/base_plan.hpp"

class InsertPlan : public BasePlan {
public:
  InsertPlan(SchemaRef schema,
             MutPtr<BasePlan> child)
    : BasePlan   (schema),
      child_     (move(child)),
      table_oid_ (schema.table_oid()) {}

  PlanType type()         const { return PlanType::INSERT; }
  table_oid_t table_oid() const { return table_oid_; }

  MovePtr<BasePlan> child()     { return move(child_); }

private:
  MutPtr<BasePlan> child_;
  table_oid_t table_oid_;
};
