#pragma once

#include "exprs/base_expr.hpp"
#include "query/comp_type.hpp"
#include "query/query_where.hpp"

class WhereClauseExpr : public BaseExpr {
public:
  WhereClauseExpr(ptr<BaseExpr>&& left_expr)
    : BaseExpr    (ExprType::WHERE),
      left_expr_  (move(left_expr))
  {}

  WhereClauseExpr(ptr<BaseExpr>&& left_expr,
                  LogicalType combine,
                  ptr<BaseExpr>&& right_expr)
    : BaseExpr    (ExprType::WHERE),
      combine_    (combine),
      left_expr_  (move(left_expr)),
      right_expr_ (move(right_expr))
  {}

  ptr<BaseExpr>& left_expr() {
    return left_expr_;
  }

  ptr<BaseExpr>& right_expr() {
    return right_expr_;
  }

  LogicalType logical_type() {
    return combine_;
  }

  const string to_string() const {
    return "WHERE .. TODO";
  }

private:
  LogicalType combine_ = LogicalType::NONE;
  ptr<BaseExpr> left_expr_, right_expr_;
};
