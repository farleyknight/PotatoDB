#pragma once

#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/query_schema_plan.hpp"
#include "plans/has_child_plan.hpp"

class DeletePlan : public BasePlan,
                   public TablePlan,
                   public QuerySchemaPlan,
                   public HasChildPlan
{
public:
  DeletePlan(QuerySchema schema,
             table_oid_t table_oid,
             ptr<BasePlan>&& child)
    : BasePlan        (PlanType::DELETE),
      TablePlan       (table_oid),
      QuerySchemaPlan (schema),
      HasChildPlan    (move(child))
  {}

  bool is_query() const {
    return false;
  }
};
