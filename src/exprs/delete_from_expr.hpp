#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/has_where_clause_expr.hpp"

class DeleteFromExpr : public BaseExpr,
                       public HasWhereClauseExpr
{
public:
  DeleteFromExpr()
    : BaseExpr (ExprType::DELETE_FROM)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  const TableExpr& table() const {
    return table_;
  }

  const string to_string() const {
    return "TODO";
  }

private:
  TableExpr table_;
};
