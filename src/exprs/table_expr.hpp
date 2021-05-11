#pragma once

#include "exprs/base_expr.hpp"

class TableExpr : public BaseExpr {
public:
  TableExpr()
    : BaseExpr (ExprType::TABLE)
  {}

  TableExpr(table_name_t name)
    : BaseExpr (ExprType::TABLE),
      name_    (name)
  {}

  TableExpr(table_oid_t table_oid, table_name_t name)
    : BaseExpr   (ExprType::TABLE),
      name_      (name),
      table_oid_ (table_oid)
  {}

  void set_name(table_name_t name) {
    name_ = name;
  }

  const string& name() const {
    return name_;
  }

  virtual const string to_string() const override {
    return name_;
  }

protected:
  table_name_t name_;
  table_oid_t table_oid_ = INVALID_TABLE_OID;
};
