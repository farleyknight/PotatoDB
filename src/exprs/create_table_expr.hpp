#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"
#include "exprs/column_def_list_expr.hpp"

class CreateTableExpr : public BaseExpr {
public:
  CreateTableExpr()
    : BaseExpr (ExprType::CREATE_TABLE)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  void set_column_defs(ColumnDefListExpr column_defs) {
    column_defs_ = column_defs;
  }

  const TableExpr& table() {
    return table_;
  }

  const ColumnDefListExpr& column_defs() {
    return column_defs_;
  }

  virtual const string to_string() const override {
    return "CREATE TABLE " + table_.to_string() + "(" +
      column_defs_.to_string() + ")";
  }

protected:
  TableExpr table_;
  ColumnDefListExpr column_defs_;
};
