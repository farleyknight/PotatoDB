#pragma once

#include "plans/base_plan.hpp"

class ShowTablesPlan : public BasePlan,
                       public SchemaPlan
{
public:
  ShowTablesPlan(QuerySchema schema)
    : BasePlan   (PlanType::SHOW_TABLES),
      SchemaPlan (schema)
  {}

  bool is_query() const {
    return true;
  }

private:
  // TODO: Any instance variables?
};
