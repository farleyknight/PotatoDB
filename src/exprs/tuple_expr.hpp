#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/value_expr.hpp"
#include "exprs/list_expr.hpp"

class TupleExpr : public BaseExpr,
                  public ListExpr<ValueExpr>
{
public:
  TupleExpr()
    : BaseExpr (ExprType::TUPLE)
  {}

  const string to_string() const override {
    return ListExpr<ValueExpr>::to_string();
  }
};
