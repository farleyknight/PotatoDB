#pragma once

#include "exprs/base_expr.hpp"
#include "value/value.hpp"

enum class ValueType {
  UNKNOWN = 0,
  NUMERIC = 1,
  STRING  = 2
};

class ValueExpr : public BaseExpr {
public:
  ValueExpr(string data)
    : BaseExpr    (ExprType::VALUE),
      value_type_ (ValueType::UNKNOWN),
      data_       (data)
  {}

  ValueExpr(ValueType type, string data)
    : BaseExpr    (ExprType::VALUE),
      value_type_ (type),
      data_       (data)
  {}

  virtual const string to_string() const override {
    return data_;
  }

  Value to_value() const {
    // TODO: Use the ValueType enum to properly convert this into a value
    return Value::make(data_);
  }

protected:
  ValueType value_type_;
  string data_;
};
