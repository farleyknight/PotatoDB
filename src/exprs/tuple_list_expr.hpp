#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/tuple_expr.hpp"
#include "exprs/list_expr.hpp"

class TupleListExpr : public BaseExpr,
                      public ListExpr<TupleExpr>
{
public:
  TupleListExpr()
    : BaseExpr (ExprType::TUPLE_LIST)
  {}

};
