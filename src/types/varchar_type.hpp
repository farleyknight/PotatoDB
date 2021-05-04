#pragma once

#include <limits>

#include "types/type.hpp"

class VarCharType : public Type {
public:
  static Value min() {
    string s = "";
    return Value::make(s);
  }

  static Value max() {
    string s = "";
    return Value::make(s);
  }

  const string to_string(const Value& value) const override {
    if (value.is_null()) {
      return "NULL";
    }
    return value.as<string>();
  }

  // TODO: Rename to `write_to`
  void serialize_to(size_t offset, Buffer& buff, Value val) const override {
    buff.write_string(offset, val.as<string>());
  }
};
