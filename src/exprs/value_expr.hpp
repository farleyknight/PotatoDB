#pragma once

#include "exprs/base_expr.hpp"

class ValueExpr : public BaseExpr {
public:
  ValueExpr(string data)
    : BaseExpr (ExprType::VALUE),
      data_    (data)
  {}

  virtual const string to_string() const override {
    return data_;
  }

protected:
  string data_;
};

