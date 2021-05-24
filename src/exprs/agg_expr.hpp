#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_expr.hpp"
#include "query/agg_type.hpp"

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

  const ColumnExpr& column_expr() const {
    return col_expr_;
  }

  AggType agg_type() const {
    if (func_name_ == "COUNT") {
      return AggType::COUNT;
    } else if (func_name_ == "SUM") {
      return AggType::SUM;
    } else if (func_name_ == "MIN") {
      return AggType::MIN;
    } else if (func_name_ == "MAX") {
      return AggType::MAX;
    } else {
      throw Exception("Function name not recognized! : " + func_name_);
    }
  }

protected:
  string func_name_;
  ColumnExpr col_expr_;
};
