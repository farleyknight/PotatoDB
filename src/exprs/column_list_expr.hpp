#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_expr.hpp"
#include "exprs/list_expr.hpp"

class ColumnListExpr : public BaseExpr,
                       public ListExpr<ColumnExpr>
{
public:
  ColumnListExpr()
    : BaseExpr (ExprType::COLUMN_LIST)
  {}

  const string to_string() const override {
    return ListExpr<ColumnExpr>::to_string();
  }
};
