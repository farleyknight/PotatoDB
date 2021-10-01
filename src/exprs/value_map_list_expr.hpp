#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/value_map_expr.hpp"
#include "exprs/list_expr.hpp"

class ValueMapListExpr : public BaseExpr,
                         public ListExpr<ValueMapExpr>
{
public:
  ValueMapListExpr()
    : BaseExpr (ExprType::VALUE_MAP_LIST)
  {}

  virtual const string to_string() const override {
    return ListExpr<ValueMapExpr>::to_string();
  }
};
