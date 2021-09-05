#pragma once

#include "exprs/base_expr.hpp"

// TODO: Maybe we can create a new class called NameExpr<T>
// that would abstract the commonality between this class
// and the IndexExpr class.
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
  // TODO: Is this used anywhere?
  table_oid_t table_oid_ = INVALID_TABLE_OID;
};
