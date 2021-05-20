#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/agg_expr.hpp"
#include "exprs/list_expr.hpp"

class AggListExpr : public BaseExpr,
                    public ListExpr<AggExpr>
{
public:
  AggListExpr()
    : BaseExpr (ExprType::AGG_LIST)
  {}

  const string to_string() const override {
    return ListExpr<AggExpr>::to_string();
  }
};
