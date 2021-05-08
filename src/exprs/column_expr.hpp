#pragma once

#include "exprs/base_expr.hpp"

class ColumnExpr : public BaseExpr {
public:
  ColumnExpr(const string name)
    : BaseExpr (ExprType::COLUMN),
      name_    (name)
  {}

  ColumnExpr(const string name, string table)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      table_   (table)
  {}

  const string& name() {
    return name_;
  }

  const string& table() {
    return table_;
  }

  virtual string to_string() const override {
    return name_;
  }

protected:
  string name_, table_;
};
