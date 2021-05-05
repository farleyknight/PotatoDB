#pragma once

#include "exprs/base_expr.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  ColumnDefExpr(string name, string type)
    : BaseExpr (ExprType::COLUMN_DEF),
      name_    (name),
      type_    (type)
  {}

  virtual string to_string() const override {
    return name_ + " " + type_;
  }

protected:
  string name_, type_;
};
