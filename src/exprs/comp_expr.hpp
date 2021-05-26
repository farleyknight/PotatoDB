#pragma once

#include "exprs/base_expr.hpp"

class CompExpr : public BaseExpr {
public:
  CompExpr(ptr<BaseExpr>&& left,
           CompareType comp,
           ptr<BaseExpr>&& right)
    : BaseExpr (ExprType::COMPARE),
      left_    (move(left)),
      right_   (move(right)),
      comp_    (comp)
  {}

  const string to_string() const {
    // TODO: Properly handle when CompareType is NOT equals
    return left_->to_string() + " == " + right_->to_string();
  }

  const ptr<BaseExpr>& left_expr() const {
    return left_;
  }

  const ptr<BaseExpr>& right_expr() const {
    return right_;
  }

  CompareType compare_type() const {
    return comp_;
  }

protected:
  ptr<BaseExpr> left_, right_;
  CompareType comp_;
};
