#pragma once

#include "plans/base_plan.hpp"

class DescribeTablePlan : public BasePlan,
                          public SchemaPlan
{
public:
  DescribeTablePlan(QuerySchema schema,
                    const table_name_t table_name)
    : BasePlan    (PlanType::DESCRIBE_TABLE),
      SchemaPlan  (schema),
      table_name_ (table_name)
  {}

  bool is_query() const {
    return true;
  }

  const table_name_t&
  table_name() const {
    return table_name_;
  }

private:
  const table_name_t table_name_;
};

