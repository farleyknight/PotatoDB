#pragma once

#include "plans/base_plan.hpp"

class HasChildPlan {
public:
  HasChildPlan(ptr<BasePlan>&& child)
    : child_ (move(child))
  {
    assert(child_ != nullptr);
  }

  ptr<BasePlan>&& child() { return move(child_); }

protected:
  ptr<BasePlan> child_;
};
