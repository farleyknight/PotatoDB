#pragma once

#include "exprs/base_expr.hpp"

class ColumnExpr : public BaseExpr {
public:
  ColumnExpr()
    : BaseExpr (ExprType::COLUMN)
  {}

  ColumnExpr(const column_name_t name,
             column_oid_t oid)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      oid_     (oid)
  {}

  ColumnExpr(const column_name_t name,
             const table_name_t table,
             column_oid_t oid)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      table_   (table),
      oid_     (oid)
  {}

  const string&
  name() const {
    return name_;
  }

  column_oid_t
  oid() const {
    return oid_;
  }

  bool
  is_all_columns_splat() const {
    return name_ == "*" && table_ == "";
  }

  bool
  is_table_splat() const {
    return name_ == "*" && table_ != "";
  }

  const string&
  table() const {
    return table_;
  }

  const string
  to_string() const {
    // TODO: Handle AggExpr case
    if (table_.size() > 0) {
      return table_ + "." + name_;
    } else {
      return name_;
    }
  }

protected:
  column_name_t name_;
  table_name_t  table_;
  column_oid_t oid_ = INVALID_COLUMN_OID;
};
