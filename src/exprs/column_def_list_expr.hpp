#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_def_expr.hpp"
#include "exprs/list_expr.hpp"

class ColumnDefListExpr : public BaseExpr,
                          public ListExpr<ColumnDefExpr>
{
public:
  ColumnDefListExpr()
    : BaseExpr (ExprType::COLUMN_DEF_LIST)
  {}

  const string to_string() const override {
    return ListExpr<ColumnDefExpr>::to_string();
  }
};
