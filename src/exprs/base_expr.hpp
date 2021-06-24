#pragma once

#include "common/config.hpp"
#include "exprs/expr_type.hpp"
#include "query/query_column.hpp"

class BaseExpr {
public:
  BaseExpr(ExprType expr_type)
    : expr_type_ (expr_type)
  {}

  virtual ~BaseExpr() = default;

  virtual const string to_string() const = 0;

  ExprType expr_type() const {
    return expr_type_;
  }

protected:
  ExprType expr_type_;
};

