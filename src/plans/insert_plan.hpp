#pragma once

#include "plans/base_plan.hpp"
#include "plans/query_schema_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/has_child_plan.hpp"

class InsertPlan : public BasePlan,
                   public QuerySchemaPlan,
                   public HasChildPlan,
                   public TablePlan
{
public:
  InsertPlan(const QuerySchema schema,
             table_oid_t table_oid,
             ptr<BasePlan>&& child)
    : BasePlan        (PlanType::INSERT),
      QuerySchemaPlan (schema),
      HasChildPlan    (move(child)),
      TablePlan       (table_oid)
  {}

  bool is_query() const {
    return false;
  }
};
