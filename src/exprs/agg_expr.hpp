#pragma once

#include "exprs/base_expr.hpp"

class AggExpr : public BaseExpr {
public:
  AggExpr(const string func_name)
    : BaseExpr   (ExprType::AGG),
      func_name_ (func_name)
  {}

  const string to_string() const {
    return func_name_ + "(...)";
  }

  const string& function_name() const {
    return func_name_;
  }

protected:
  const string func_name_;
};
