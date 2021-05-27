#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/has_where_clause_expr.hpp"

class UpdateExpr : public BaseExpr,
                   public HasWhereClauseExpr
{
public:
  UpdateExpr()
    : BaseExpr (ExprType::UPDATE)
  {}

  using UpdateValues = map<column_name_t, ptr<BaseExpr>>;

  void set_table(TableExpr table) {
    table_ = table;
  }

  const TableExpr& table() const {
    return table_;
  }

  void set_pair(column_name_t name, ptr<BaseExpr>&& value) {
    update_values_[name] = move(value);
  }

  const UpdateValues& update_values() {
    return update_values_;
  }

  const string to_string() const {
    return "TODO";
  }

private:
  TableExpr table_;
  UpdateValues update_values_;
};
