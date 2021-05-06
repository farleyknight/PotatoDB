#pragma once

#include <utility>
#include <vector>

#include "plans/plan_type.hpp"
#include "catalog/query_schema.hpp"
#include "catalog/schema_ref.hpp"

class BasePlan {
public:
  BasePlan(PlanType type)
    : type_ (type)
  {}

  // Allow copy
  BasePlan(const BasePlan& plan) = default;
  // Allow copy assign
  BasePlan& operator=(const BasePlan& plan) = default;

  virtual ~BasePlan() = 0;

  PlanType type() const { return type_; }

private:
  PlanType type_ = PlanType::INVALID;
};
