#pragma once

#include "exprs/base_expr.hpp"

class TableExpr : public BaseExpr {
public:
  TableExpr()
    : BaseExpr (ExprType::TABLE)
  {}

  TableExpr(MutString name)
    : BaseExpr (ExprType::TABLE),
      name_    (name)
  {}

  void set_name(MutString name) {
    name_ = name;
  }

  virtual MutString to_string() const override {
    return name_;
  }

protected:
  MutString name_;
};


