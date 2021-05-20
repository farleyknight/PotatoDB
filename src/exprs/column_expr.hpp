#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/agg_expr.hpp"

class ColumnExpr : public BaseExpr {
public:
  ColumnExpr(const column_name_t name)
    : BaseExpr (ExprType::COLUMN),
      name_    (name)
  {}

  ColumnExpr(const column_name_t name, const table_name_t table)
    : BaseExpr (ExprType::COLUMN),
      name_    (name),
      table_   (table)
  {}

  // No copy
  ColumnExpr(const ColumnExpr&) = delete;
  // No copy assign
  ColumnExpr& operator=(const ColumnExpr&) = delete;

  const string& name() const {
    return name_;
  }

  bool is_all_columns_splat() const {
    return name_ == "*" && table_ == "";
  }

  bool is_table_splat() const {
    return name_ == "*" && table_ != "";
  }

  const string& table() const {
    return table_;
  }

  const string to_string() const {
    // TODO: Handle AggExpr case
    if (table_.size() > 0) {
      return table_ + "." + name_;
    } else {
      return name_;
    }
  }

  void set_agg(ptr<AggExpr> agg) {
    agg_ = move(agg);
  }

  const ptr<AggExpr>& agg() {
    return agg_;
  }

protected:
  column_name_t name_;
  table_name_t  table_;
  ptr<AggExpr> agg_;
};
