#pragma once

#include "exprs/base_expr.hpp"
#include "query/query_where.hpp"

class WhereClauseExpr : public BaseExpr {
public:
  WhereClauseExpr(ptr<BaseExpr>&& left_expr)
    : BaseExpr    (ExprType::WHERE),
      left_expr_  (move(left_expr))
  {}

  WhereClauseExpr(ptr<BaseExpr>&& left_expr,
                  LogicalType type,
                  ptr<BaseExpr>&& right_expr)
    : BaseExpr    (ExprType::WHERE),
      type_       (type),
      left_expr_  (move(left_expr)),
      right_expr_ (move(right_expr))
  {}

  const ptr<BaseExpr>& left_expr() const {
    return left_expr_;
  }

  const ptr<BaseExpr>& right_expr() const {
    return right_expr_;
  }

  LogicalType logical_type() const {
    return type_;
  }

  const string to_string() const {
    return "WHERE .. TODO";
  }

private:
  LogicalType type_ = LogicalType::NONE;
  ptr<BaseExpr> left_expr_, right_expr_;
};
