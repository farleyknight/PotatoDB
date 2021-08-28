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

protected:
  string index_name_;

  // TODO: Eventually we should allow for more columns
  string index_column_;

  TableExpr table_;
  bool if_not_exists_ = false;
  // TODO: Eventually we should use the "unique" flag
  bool unique_ = false;
};
