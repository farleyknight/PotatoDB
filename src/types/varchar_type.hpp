#pragma once

#include <limits>

#include "types/type.hpp"

class VarCharType : public Type {
public:
  Value min() const override {
    string s = "";
    return Value::make(s);
  }

  Value max() const override {
    // TODO: We should have a better value to return back?
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
