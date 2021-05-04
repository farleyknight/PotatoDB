#pragma once

#include "exprs/base_expr.hpp"

class ValueExpr : public BaseExpr {
public:
  ValueExpr(MutString data)
    : BaseExpr (ExprType::VALUE),
      data_    (data)
  {}

  virtual MutString to_string() const override {
    return data_;
  }

protected:
  MutString data_;
};

