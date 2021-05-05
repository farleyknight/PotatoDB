#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/value_expr.hpp"

class TupleExpr : public BaseExpr {
public:
  TupleExpr()
    : BaseExpr (ExprType::TUPLE)
  {}

  void push_back(ValueExpr expr) {
    values_.push_back(expr);
  }

  const MutVec<ValueExpr>& values() const {
    return values_;
  }

  MutString to_string() const override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < values_.size(); ++i) {
      stream << values_[i].to_string();
      if (i != values_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<ValueExpr> values_;
};
