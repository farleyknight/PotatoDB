#pragma once

#include "plans/base_plan.hpp"
#include "exprs/order_by_expr.hpp"

enum class SortDirection {
  INVALID = 0,
  ASC     = 1,
  DESC    = 2
};

class SortPlan : public BasePlan {
public:
  SortPlan(OrderByExpr order_by,
           ptr<BasePlan>&& child)
    : BasePlan    (PlanType::SORT),
      child_      (move(child)),
      order_by_   (order_by)
  {}

  ptr<BasePlan>&& child() {
    return move(child_);
  }

  bool is_query() const {
    return true;
  }

  const OrderByExpr order_by() const {
    return order_by_;
  }

private:
  ptr<BasePlan> child_;
  OrderByExpr order_by_;
};
