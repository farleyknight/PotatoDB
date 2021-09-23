#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/schema_plan.hpp"
#include "plans/has_child_plan.hpp"

class UpdatePlan : public BasePlan,
                   public TablePlan,
                   public SchemaPlan,
                   public HasChildPlan
{
public:
  // TODO: Break out this map<...> structure into a proper
  // class called UpdateValues.
  using UpdateValues = map<column_oid_t, ptr<BaseQuery>>;

  UpdatePlan(QuerySchema schema,
             table_oid_t table_oid,
             ptr<BasePlan>&& child,
             UpdateValues&& update_values)
    : BasePlan       (PlanType::UPDATE),
      TablePlan      (table_oid),
      SchemaPlan     (schema),
      HasChildPlan   (move(child)),
      update_values_ (move(update_values))
  {}

  const UpdateValues& update_values() const {
    return update_values_;
  }

  bool is_query() const {
    return false;
  }

private:
  UpdateValues update_values_;
};
