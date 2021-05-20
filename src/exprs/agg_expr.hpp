#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_expr.hpp"

class AggExpr : public BaseExpr {
public:
  AggExpr(const string func_name, ColumnExpr col_expr)
    : BaseExpr   (ExprType::AGG),
      func_name_ (func_name),
      col_expr_  (col_expr)
  {}

  const string to_string() const {
    return func_name_ + "(" + col_expr_.to_string() + ")";
  }

  const string& function_name() const {
    return func_name_;
  }

protected:
  string func_name_;
  ColumnExpr col_expr_;
};
