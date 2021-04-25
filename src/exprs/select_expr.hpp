#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_list_expr.hpp"
#include "exprs/column_list_expr.hpp"

class SelectExpr : public BaseExpr {
public:
  SelectExpr()
    : BaseExpr (ExprType::SELECT)
  {}

  void set_columns(ColumnListExpr columns) {
    column_list_ = columns;
  }

  void set_tables(TableListExpr tables) {
    table_list_ = tables;
  }

  CRef<TableListExpr> table_list() {
    return table_list_;
  }

  CRef<ColumnListExpr> column_list() {
    return column_list_;
  }

  virtual MutString to_string() const override {
    return "SELECT " + column_list_.to_string() +
      "FROM " + table_list_.to_string();
  }

protected:
  TableListExpr table_list_;
  ColumnListExpr column_list_;
};
