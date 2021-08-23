#pragma once

#include "plans/base_plan.hpp"

class ShowTablesPlan : public BasePlan {
public:
  ShowTablesPlan()
    : BasePlan (PlanType::SHOW_TABLES)
  {}

private:
  // TODO: Any instance variables?
};
