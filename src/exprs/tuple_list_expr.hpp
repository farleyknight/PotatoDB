#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/tuple_expr.hpp"

class TupleListExpr : public BaseExpr {
public:
  TupleListExpr()
    : BaseExpr (ExprType::TUPLE_LIST)
  {}

  void push_back(TupleExpr expr) {
    tuples_.push_back(expr);
  }

  const vector<TupleExpr>& tuples() const {
    return tuples_;
  }

  string to_string() const override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < tuples_.size(); ++i) {
      stream << tuples_[i].to_string();
      if (i != tuples_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  vector<TupleExpr> tuples_;
};
