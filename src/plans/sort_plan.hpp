#pragma once

#include "plans/base_plan.hpp"
#include "plans/has_child_plan.hpp"
#include "exprs/order_by_expr.hpp"

enum class SortDirection {
  INVALID = 0,
  ASC     = 1,
  DESC    = 2
};

class SortPlan : public BasePlan,
                 public QuerySchemaPlan,
                 public HasChildPlan
{
public:
  SortPlan(QuerySchema schema,
           OrderByExpr order_by,
           ptr<BasePlan>&& child)
    : BasePlan        (PlanType::SORT),
      QuerySchemaPlan (schema),
      HasChildPlan    (move(child)),
      order_by_       (order_by)
  {}

  bool is_query() const {
    return true;
  }

  const OrderByExpr& order_by() const {
    return order_by_;
  }

private:
  OrderByExpr order_by_;
};
