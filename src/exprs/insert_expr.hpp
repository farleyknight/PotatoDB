#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"
#include "exprs/column_list_expr.hpp"
#include "exprs/tuple_list_expr.hpp"

class InsertExpr : public BaseExpr {
public:
  InsertExpr()
    : BaseExpr (ExprType::INSERT)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  void set_columns(ColumnListExpr columns) {
    columns_ = columns;
  }

  void set_tuples(TupleListExpr tuples) {
    tuples_ = tuples;
  }

  CRef<MutString> table_name() const {
    return table_.to_string();
  }

  CRef<ColumnListExpr> column_list() const {
    return columns_;
  }

  CRef<TupleListExpr> tuple_list() const {
    return tuples_;
  }

  virtual MutString to_string() const override {
    return "INSERT INTO " + table_.to_string() +
      columns_.to_string() +
      "VALUES " + tuples_.to_string();
  }

protected:
  TableExpr table_;
  ColumnListExpr columns_;
  TupleListExpr tuples_;
};
