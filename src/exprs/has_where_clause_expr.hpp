#pragma once

#include "exprs/where_clause_expr.hpp"

class HasWhereClauseExpr {
public:
  void set_where(ptr<WhereClauseExpr>&& where_clause) {
    where_clause_ = move(where_clause);
  }

  const ptr<WhereClauseExpr>& pred() const {
    return where_clause_;
  }

protected:
  ptr<WhereClauseExpr> where_clause_;
};

