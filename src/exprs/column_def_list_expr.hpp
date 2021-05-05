#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_def_expr.hpp"

class ColumnDefListExpr : public BaseExpr {
public:
  ColumnDefListExpr()
    : BaseExpr (ExprType::COLUMN_DEF_LIST)
  {}

  void push_back(ColumnDefExpr column_def) {
    column_defs_.push_back(column_def);
  }

  virtual string to_string() const override {
    std::stringstream stream;
    stream << "[";
    for (size_t i = 0; i < column_defs_.size(); ++i) {
      stream << column_defs_[i].to_string();
      if (i != column_defs_.size() - 1) {
        stream << ", ";
      }
    }
    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  vector<ColumnDefExpr> column_defs_;
};
