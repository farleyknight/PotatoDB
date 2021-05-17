#pragma once

#include "exprs/base_expr.hpp"
#include "query/comp_type.hpp"

class WhereClauseExpr : BaseExpr {
public:
  WhereClauseExpr(ptr<BaseExpr>&& left_expr,
                  CompType comp,
                  ptr<BaseExpr>&& right_expr)
    : BaseExpr    (ExprType::WHERE),
      comp_       (comp),
      left_expr_  (move(left_expr)),
      right_expr_ (move(right_expr))
  {}

  ptr<BaseExpr>& left_expr() {
    return left_expr_;
  }

  ptr<BaseExpr>& right_expr() {
    return right_expr_;
  }

  CompType comp_type() {
    return comp_;
  }

  const string to_string() const {
    return "WHERE .. TODO";
  }

private:
  CompType comp_;
  ptr<BaseExpr> left_expr_, right_expr_;
};
