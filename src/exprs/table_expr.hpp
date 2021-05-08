#pragma once

#include "exprs/base_expr.hpp"

class TableExpr : public BaseExpr {
public:
  TableExpr()
    : BaseExpr (ExprType::TABLE)
  {}

  TableExpr(string name)
    : BaseExpr (ExprType::TABLE),
      name_    (name)
  {}

  TableExpr(table_oid_t table_oid, string name)
    : BaseExpr   (ExprType::TABLE),
      name_      (name),
      table_oid_ (table_oid)
  {}

  void set_name(string name) {
    name_ = name;
  }

  const string& name() const {
    return name_;
  }

  virtual const string to_string() const override {
    return name_;
  }

protected:
  string name_;
  table_oid_t table_oid_;
};


