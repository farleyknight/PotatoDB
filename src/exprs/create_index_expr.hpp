#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"
#include "exprs/index_expr.hpp"
#include "exprs/indexed_column_list_expr.hpp"

class CreateIndexExpr : public BaseExpr {
public:
  CreateIndexExpr()
    : BaseExpr (ExprType::CREATE_INDEX)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  const TableExpr& table() const {
    return table_;
  }

  void set_index(IndexExpr index) {
    index_ = index;
  }

  const IndexExpr& index() const {
    return index_;
  }

  void set_indexed_columns(IndexedColumnListExpr indexed_columns) {
    indexed_columns_ = indexed_columns;
  }

  const IndexedColumnListExpr indexed_columns() const {
    return indexed_columns_;
  }

  virtual const string to_string() const override {
    return "CREATE INDEX " + index_.to_string() + " ON " +
      table_.to_string() + " (" + indexed_columns_.to_string() + ")";
  }

  void set_if_not_exists(bool if_not_exists) {
    if_not_exists_ = if_not_exists;
  }

protected:
  IndexExpr index_;
  IndexedColumnListExpr indexed_columns_;

  TableExpr table_;
  bool if_not_exists_ = false;
  // TODO: Eventually we should use the "unique" flag
  bool unique_ = false;
};
