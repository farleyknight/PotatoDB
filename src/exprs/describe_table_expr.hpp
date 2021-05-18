#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"

class DescribeTableExpr : BaseExpr {
public:
  DescribeTableExpr()
    : BaseExpr (ExprType::DESCRIBE_TABLE)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  const TableExpr& table() {
    return table_;
  }


private:
  TableExpr table_;
};
