#pragma once

#include "exprs/base_expr.hpp"

class ColumnExpr : public BaseExpr {
public:
  ColumnExpr(MutString name)
    : BaseExpr (ExprType::COLUMN),
      name_    (name)
  {}

  ColumnExpr(MutString name, MutString table)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      table_   (table)
  {}

  virtual MutString to_string() const override {
    return name_;
  }

protected:
  MutString name_, table_;
};

