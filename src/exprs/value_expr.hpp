#pragma once

#include "exprs/base_expr.hpp"
#include "value/value.hpp"

enum class ValueType {
  UNKNOWN   = 0,
  NUMERIC   = 1,
  STRING    = 2,
  TIMESTAMP = 3
};

class ValueExpr : public BaseExpr {
public:
  explicit ValueExpr(string data)
    : BaseExpr     (ExprType::VALUE),
      value_type_  (ValueType::UNKNOWN),
      string_data_ (data)
  {}

  explicit ValueExpr(ValueType type, string data)
    : BaseExpr     (ExprType::VALUE),
      value_type_  (type),
      string_data_ (data)
  {}

  explicit ValueExpr(timestamp_t timestamp)
    : BaseExpr        (ExprType::VALUE),
      value_type_     (ValueType::TIMESTAMP),
      timestamp_data_ (timestamp)
  {}

  virtual const string to_string() const override {
    if (value_type_ == ValueType::STRING) {
      return string_data_;
    } else if (value_type_ == ValueType::TIMESTAMP) {
      return std::to_string(timestamp_data_);
    } else {
      return string_data_; // TODO: Specialize more here
    }
  }

  Value to_value() const {
    // TODO: Use the ValueType enum to properly convert this into a value
    if (value_type_ == ValueType::STRING) {
      return Value::make(string_data_);
    } else if (value_type_ == ValueType::TIMESTAMP) {
      return Value::make(timestamp_data_);
    } else {
      return Value::make(string_data_); // TODO: Fix this!
    }
  }

protected:
  ValueType value_type_;
  string string_data_;
  timestamp_t timestamp_data_ = 0;
};
