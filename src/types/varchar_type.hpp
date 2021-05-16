#pragma once

#include <limits>

#include "types/type.hpp"

class VarCharType : public Type {
public:
  TypeId type_id() const override {
    return TypeId::VARCHAR;
  }

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
    // std::cout << "Writing string in VarCharType" << std::endl;
    buff.write_string(offset, val.as<string>());
  }

  Value deserialize_from(size_t offset, const Buffer& buff) const override {
    return Value::make(buff.read_string(offset));
  }

  size_t size() const override {
    return 12; // TODO Find out if this is correct
  }

  Value cast_as(const Value& value, TypeId type_id) const override {
    switch(type_id) {
    case TypeId::INTEGER: {
      int32_t integer = 0;
      try {
        integer = static_cast<int32_t>(std::stoi(value.to_string()));
      } catch (std::out_of_range &e) {
        throw Exception(ExceptionType::OUT_OF_RANGE, "Numeric value out of range.");
      }
      return Value(type_id, integer);
    }
    case TypeId::VARCHAR: {
      return Value(TypeId::VARCHAR, "'" + value.to_string() + "'");
    }
    default:
      throw Exception("Not implemented! for this type : " + Type::as_string(type_id));
    }
  }
};
