#pragma once

#include "exprs/base_expr.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  ColumnDefExpr(String name, String type)
    : BaseExpr (ExprType::COLUMN_DEF),
      name_    (name),
      type_    (type)
  {}

  virtual MutString to_string() const override {
    return name_ + " " + type_;
  }

protected:
  MutString name_, type_;
};
