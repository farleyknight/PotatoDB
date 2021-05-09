#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"

class TableListExpr : public BaseExpr,
                      public ListExpr<TableExpr>
{
public:
  TableListExpr()
    : BaseExpr (ExprType::TABLE_LIST)
  {}

  const string to_string() const override {
    return ListExpr<TableExpr>::to_string();
  }
};
