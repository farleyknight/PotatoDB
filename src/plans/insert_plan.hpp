#pragma once

#include "plans/base_plan.hpp"
#include "plans/schema_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/has_child_plan.hpp"

class InsertPlan : public BasePlan, public SchemaPlan, public HasChildPlan, public TablePlan {
public:
  InsertPlan(QuerySchema schema, table_oid_t table_oid, ptr<BasePlan> child)
    : BasePlan     (PlanType::INSERT),
      SchemaPlan   (schema),
      HasChildPlan (move(child)),
      TablePlan    (table_oid)
  {}

};
