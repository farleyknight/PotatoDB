#pragma once

#include "exprs/base_expr.hpp"

class WhereClauseExpr : BaseExpr {
public:
  WhereClauseExpr(ptr<BaseExpr>&& left_expr,
                  CompType comp,
                  ptr<BaseExpr>&& right_expr)
    : BaseExpr    (ExprType::WHERE),
      left_expr_  (move(left_expr)),
      comp_       (comp),
      right_expr_ (move(right_expr))
  {}

  

};
