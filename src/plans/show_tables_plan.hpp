#pragma once

#include "plans/base_plan.hpp"

class ShowTablesPlan : public BasePlan,
                       public QuerySchemaPlan
{
public:
  ShowTablesPlan(QuerySchema schema)
    : BasePlan        (PlanType::SHOW_TABLES),
      QuerySchemaPlan (schema)
  {}

  bool is_query() const {
    return true;
  }

private:
  // TODO: Any instance variables?
};
