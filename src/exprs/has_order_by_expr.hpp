#pragma once

#include "exprs/order_by_expr.hpp"

class HasOrderByExpr {
public:
  void set_order_by(OrderByExpr order_by) {
    order_by_ = order_by;
  }

  const OrderByExpr& order_by() const {
    return order_by_;
  }

protected:
  OrderByExpr order_by_;
};
