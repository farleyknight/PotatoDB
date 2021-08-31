#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"

class CreateIndexExpr : public BaseExpr {
public:
  CreateIndexExpr()
    : BaseExpr (ExprType::CREATE_INDEX)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  const TableExpr& table() const {
    return table_;
  }

  // TODO: Create IndexExpr
  const string index_name() const {
    return index_name_;
  }

  const vector<string> column_names() const {
    return column_names_;
  }

protected:
  // TODO: Create IndexExpr, rename this to index_
  string index_name_;

  vector<string> column_names_;

  TableExpr table_;
  bool if_not_exists_ = false;
  // TODO: Eventually we should use the "unique" flag
  bool unique_ = false;
};
