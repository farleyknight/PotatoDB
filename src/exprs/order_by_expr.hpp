#pragma once

#include "exprs/base_expr.hpp"

class OrderByExpr : public BaseExpr {
public:
  OrderByExpr()
    : BaseExpr (ExprType::ORDER_BY)
  {}

  void set_column(ColumnExpr col) {
    col_ = col;
  }

  void set_direction(string direction) {
    direction_ = direction;
  }

  const ColumnExpr& column() const {
    return col_;
  }

  const string& direction() const {
    return direction_;
  }

  const string to_string() const {
    return col_.name() + " " + direction_;
  }

private:
  ColumnExpr col_;
  string direction_;
};
