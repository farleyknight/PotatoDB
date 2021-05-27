#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_list_expr.hpp"
#include "exprs/column_list_expr.hpp"
#include "exprs/where_clause_expr.hpp"
#include "exprs/has_order_by_expr.hpp"
#include "exprs/agg_list_expr.hpp"

#include "query/query_comp.hpp"

class SelectExpr : public BaseExpr,
                   public HasOrderByExpr
{
public:
  SelectExpr()
    : BaseExpr (ExprType::SELECT)
  {}

  void set_columns(ColumnListExpr columns) {
    column_list_ = columns;
  }

  void set_tables(TableListExpr tables) {
    table_list_ = tables;
  }

  void set_aggs(AggListExpr aggs) {
    agg_list_ = aggs;
  }

  void set_where(ptr<WhereClauseExpr>&& where_clause) {
    where_clause_ = move(where_clause);
  }

  const TableListExpr& table_list() {
    return table_list_;
  }

  const AggListExpr& agg_list() {
    return agg_list_;
  }

  ptr<WhereClauseExpr>& pred() {
    return where_clause_;
  }

  const ColumnListExpr& column_list() {
    return column_list_;
  }

  virtual const string to_string() const override {
    return "SELECT " + column_list_.to_string() +
      "FROM " + table_list_.to_string();
  }

protected:
  TableListExpr table_list_;
  ColumnListExpr column_list_;
  AggListExpr agg_list_;
  ptr<WhereClauseExpr> where_clause_;
};
