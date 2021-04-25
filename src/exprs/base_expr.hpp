#pragma once

#include "exprs/expr_type.hpp"

class BaseExpr {
public:
  BaseExpr(ExprType expr_type)
    : expr_type_ (expr_type)
  {}

  virtual ~BaseExpr() = default;

  virtual MutString to_string() const {
    // TODO: Throw not implemented error
    return "BASE EXPR";
  }

protected:
  ExprType expr_type_;
};
