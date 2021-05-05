#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_expr.hpp"

class ColumnListExpr : public BaseExpr {
public:
  ColumnListExpr()
    : BaseExpr (ExprType::COLUMN_LIST)
  {}

  void push_back(ColumnExpr expr) {
    columns_.push_back(expr);
  }

  const MutVec<ColumnExpr>& columns() const {
    return columns_;
  }

  MutString to_string() const override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < columns_.size(); ++i) {
      stream << columns_[i].to_string();
      if (i != columns_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<ColumnExpr> columns_;
};
