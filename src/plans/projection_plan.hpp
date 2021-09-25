#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/query_schema_plan.hpp"

class ProjectionPlan : public BasePlan,
                       public QuerySchemaPlan,
                       public HasChildPlan
{
public:
  ProjectionPlan(QuerySchema schema,
                 ptr<BasePlan>&& child)
    : BasePlan        (PlanType::PROJECT),
      QuerySchemaPlan (schema),
      HasChildPlan    (move(child))
  {}

  bool is_query() const {
    return true;
  }
};
