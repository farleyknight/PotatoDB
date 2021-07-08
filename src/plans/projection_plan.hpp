#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/schema_plan.hpp"

class ProjectionPlan : public BasePlan,
                       public SchemaPlan,
                       public HasChildPlan
{
public:
  ProjectionPlan(QuerySchema schema,
                 ptr<BasePlan>&& child)
    : BasePlan     (PlanType::PROJECT),
      SchemaPlan   (schema),
      HasChildPlan (move(child))
  {}

  bool is_query() const {
    return true;
  }
};
