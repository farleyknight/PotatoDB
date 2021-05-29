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

class CompoundSelectExpr : public BaseExpr,
                           public HasOrderByExpr
{
public:
  CompoundSelectExpr()
    : BaseExpr (ExprType::COMPOUND_SELECT)
  {}

  void set_left(ptr<SelectExpr>&& left) {
    left_ = move(left);
  }

  void set_right(ptr<SelectExpr>&& right) {
    right_ = move(right);
  }

  const ptr<SelectExpr>& left_select() const {
    return left_;
  }

  const ptr<SelectExpr>& right_select() const {
    return right_;
  }

  const string to_string() const {
    // TODO FIXME
    return left_->to_string();
  }

private:
  ptr<SelectExpr> left_, right_;
  UNUSED CompoundType type_ = CompoundType::NONE;
};
