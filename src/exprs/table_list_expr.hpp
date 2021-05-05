#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/table_expr.hpp"

class TableListExpr : public BaseExpr {
public:
  TableListExpr()
    : BaseExpr (ExprType::TABLE_LIST)
  {}

  void push_back(TableExpr table) {
    tables_.push_back(table);
  }

  const MutVec<TableExpr>& tables() const {
    return tables_;
  }

  MutString to_string() const override {
    std::stringstream stream;
    stream << "[";
    for (size_t i = 0; i < tables_.size(); ++i) {
      stream << tables_[i].to_string();
      if (i != tables_.size() - 1) {
        stream << ", ";
      }
    }
    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<TableExpr> tables_;
};
