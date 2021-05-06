#pragma once

#include "plans/base_plan.hpp"

class HasChildPlan {
public:
  HasChildPlan(ptr<BasePlan>&& child)
    : child_ (move(child))
  {}

  ptr<BasePlan>&& child() { return move(child_); }

private:
  ptr<BasePlan> child_;
};
