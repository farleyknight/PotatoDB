#pragma once

#include "plans/base_plan.hpp"

class DescribeTablePlan : public BasePlan {
public:
  DescribeTablePlan(const table_name_t table_name)
    : BasePlan    (PlanType::DESCRIBE_TABLE),
      table_name_ (table_name)
  {}

private:
  const table_name_t table_name_;
};

