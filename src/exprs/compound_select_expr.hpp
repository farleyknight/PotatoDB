#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/order_by_expr.hpp"

enum class CompoundType {
  NONE        = 0,
  UNION       = 1,
  UNION_ALL   = 2,
  INTERSCTION = 3,
  EXCEPT      = 4
};

class CompoundSelectExpr : public BaseExpr {
public:
  CompoundSelectExpr()
    : BaseExpr (ExprType::COMPOUND_SELECT)
  {}

  void set_left(SelectExpr&& left) {
    left_ = move(left);
  }

  SelectExpr&& left_select() {
    return move(left_);
  }

  void set_right(SelectExpr&& right) {
    right_ = move(right);
  }

  void set_order_by(OrderByExpr order_by) {
    order_by_ = order_by;
  }

  OrderByExpr order_by() const {
    return order_by_;
  }

  const string to_string() const {
    return left_.to_string();
  }

private:
  // TODO
  // left & right select
  // type
  SelectExpr left_, right_;
  OrderByExpr order_by_;
  CompoundType type_ = CompoundType::NONE;
};
