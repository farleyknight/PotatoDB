#pragma once

#include <utility>
#include <vector>

#include "plans/plan_type.hpp"
#include "catalog/query_schema.hpp"

class BasePlan {
public:
  BasePlan(PlanType type)
    : type_ (type)
  {}

  // Allow copy
  BasePlan(const BasePlan& plan) = default;
  // Allow copy assign
  BasePlan& operator=(const BasePlan& plan) = default;

  virtual ~BasePlan() = default;

  PlanType type() const { return type_; }

  virtual bool is_query() const = 0;

private:
  PlanType type_ = PlanType::INVALID;
};
