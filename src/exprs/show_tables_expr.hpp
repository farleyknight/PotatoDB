#pragma once

#include "exprs/expr_type.hpp"
#include "exprs/base_expr.hpp"

class ShowTablesExpr : public BaseExpr {
public:
  ShowTablesExpr() 
    : BaseExpr (ExprType::SHOW_TABLES)
  {}
};
