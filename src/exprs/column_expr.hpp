#pragma once

#include "exprs/base_expr.hpp"

class ColumnExpr : public BaseExpr {
public:
  ColumnExpr(const column_name_t name)
    : BaseExpr (ExprType::COLUMN),
      name_    (name)
  {}

  ColumnExpr(const column_name_t name, const table_name_t table)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      table_   (table)
  {}

  const string& name() const {
    return name_;
  }

  bool is_all_columns_splat() const {
    return name_ == "*" && table_ == "";
  }

  bool is_table_splat() const {
    return name_ == "*" && table_ != "";
  }

  const string& table() const {
    return table_;
  }

  virtual const string to_string() const override {
    return name_;
  }

protected:
  column_name_t name_;
  table_name_t  table_;
};
