#pragma once

#include <random>

#include "catalog/base_column.hpp"

#include "common/config.hpp"

#include "types/comp_bool.hpp"

#include "value/value.hpp"

class ValueFactory {
public:
  static Value tinyint(int8_t value) {
    return Value(TypeId::TINYINT, value);
  }

  static Value smallint(int16_t value) {
    return Value(TypeId::SMALLINT, value);
  }

  static Value integer(int32_t value) {
    return Value(TypeId::INTEGER, value);
  }

  static Value bigint(int64_t value) {
    return Value(TypeId::BIGINT, value);
  }

  static Value timestamp(int64_t value) {
    return Value(TypeId::TIMESTAMP, value);
  }

  static Value decimal(double value) {
    return Value(TypeId::DECIMAL, value);
  }

  static Value boolean(CompBool value) {
    return Value(
      TypeId::BOOLEAN,
      value == CompBool::NIL ? Boolean::NIL : static_cast<int8_t>(value)
    );
  }

  static Value boolean(bool value) {
    return Value(TypeId::BOOLEAN, static_cast<int8_t>(value));
  }

  static inline Value boolean(int8_t value) {
    return Value(TypeId::BOOLEAN, value);
  }

  static Value random_boolean() {
    int random_int = std::rand();
    int8_t boolean = random_int % 2;
    return Value(TypeId::BOOLEAN, boolean);
  }

  static Value random_smallint() {
    int16_t smallint = std::rand() % Int16::MAX;
    return Value(TypeId::SMALLINT, smallint);
  }

  static Value random_integer() {
    int32_t integer = std::rand() % Int32::MAX;
    return Value(TypeId::INTEGER, integer);
  }

  static Value random_bigint() {
    int32_t bigint = std::rand();
    return Value(TypeId::BIGINT, bigint);
  }

  static Value abcde_varchar() {
    String value("abcde");
    return Value(TypeId::VARCHAR, value);
  }

  static Value random_varchar(uint32_t length) {
    return Value(TypeId::VARCHAR, random_string(length));
  }

  static String random_string(uint32_t length);
  static Value from_column(BaseColumn column);
};
