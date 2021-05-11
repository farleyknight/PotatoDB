#pragma once

#include "exprs/base_expr.hpp"
#include "value/value.hpp"

class ValueExpr : public BaseExpr {
public:
  ValueExpr(string data)
    : BaseExpr (ExprType::VALUE),
      data_    (data)
  {}

  virtual const string to_string() const override {
    return data_;
  }

  Value to_value() const {
    // NOTE We return data_ as VARCHAR/string
    // Later in the pipeline, we cast the string to whatever type
    // is expected by the schema.
    // Likely this will be in the InsertExec object.
    return Value::make(data_);
  }

protected:
  string data_;
};

