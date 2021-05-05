#pragma once

#include "exprs/expr_type.hpp"

class ShowTablesExpr : public BaseExpr {
public:
  ShowTablesExpr() 
    : BaseExpr (ExprType::SHOW_TABLES)
  {}
};
