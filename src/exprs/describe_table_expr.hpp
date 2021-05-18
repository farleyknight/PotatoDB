#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"

class DescribeTableExpr : public BaseExpr {
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

  const string to_string() const {
    return "DESCRIBE TABLE " + table_.to_string();
  }

protected:
  TableExpr table_;
};
