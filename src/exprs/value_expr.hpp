#pragma once

#include "common/exceptions.hpp"
#include "exprs/base_expr.hpp"
#include "value/value.hpp"

enum class ValueType {
  NIL       = 0,
  BOOLEAN   = 1,
  INTEGER   = 2,
  STRING    = 3,
  TIMESTAMP = 4
};

class ValueExpr : public BaseExpr {
public:
  explicit ValueExpr(bool flag)
    : BaseExpr    (ExprType::VALUE),
      value_type_ (ValueType::BOOLEAN),
      flag_       (flag)
  {}

  explicit ValueExpr(int32_t number)
    : BaseExpr    (ExprType::VALUE),
      value_type_ (ValueType::INTEGER),
      number_     (number)
  {}

  explicit ValueExpr(ValueType type)
    : BaseExpr     (ExprType::VALUE),
      value_type_  (type)
  {
    assert(type == ValueType::NIL);
  }

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

  const string to_string() const override {
    // TODO: Use the ValueType enum to properly convert this into a value
    switch (value_type_) {
    case ValueType::STRING:    return string_data_;
    case ValueType::TIMESTAMP: return std::to_string(timestamp_data_);
    case ValueType::BOOLEAN:   return std::to_string(flag_);
    case ValueType::INTEGER:   return std::to_string(number_);
    case ValueType::NIL:       return "NULL";
    }
  }

  Value to_value() const {
    // TODO: Use the ValueType enum to properly convert this into a value
    switch (value_type_) {
    case ValueType::STRING:    return Value::make(string_data_);
    case ValueType::TIMESTAMP: return Value::make(timestamp_data_);
    case ValueType::BOOLEAN:   return Value::make(flag_);
    case ValueType::INTEGER:   return Value::make(number_);
    case ValueType::NIL:       return Value::make(nullptr);
    }
  }

protected:
  ValueType value_type_;
  string string_data_;
  timestamp_t timestamp_data_ = 0;
  bool flag_ = false;
  int32_t number_ = 0;
};
