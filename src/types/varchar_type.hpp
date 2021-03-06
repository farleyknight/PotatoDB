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

  bool eq(const Value& left, const Value& right) const override {
    if (left.is_null() && right.is_null()) {
      return true;
    }
    if (left.is_null() || right.is_null()) {
      return false;
    }
    return left.as<string>() == right.as<string>();
  }

  // TODO: Rename to `write_to`
  void serialize_to(buffer_offset_t offset,
                    Buffer& buff,
                    Value val) const override
  {
    // std::cout << "Writing string in VarCharType" << std::endl;
    buff.write_string(offset, val.as<string>());
  }

  Value deserialize_from(buffer_offset_t offset,
                         const Buffer& buff) const override
  {
    return Value::make(buff.read_string(offset));
  }

  buffer_offset_t size() const override {
    return 12; // TODO Find out if this is correct
  }

  Value add(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    // TODO: Add a TypeMismatchException to the list of possible exceptions
    throw Exception("Type mismatch! The operation `add` is available for VARCHAR!");
  }

  Value min(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    // TODO: Add a TypeMismatchException to the list of possible exceptions
    throw Exception("Type mismatch! The operation `min` is available for VARCHAR!");
  }

  Value max(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    // TODO: Add a TypeMismatchException to the list of possible exceptions
    throw Exception("Type mismatch! The operation `max` is available for VARCHAR!");
  }

  Value cast_as(const Value& value, TypeId type_id) const override {
    switch(type_id) {
    case TypeId::BOOLEAN: {
      auto string_value = value.to_string();
      std::cout << "BOOLEAN value as string: " << string_value << std::endl;
      if (string_value == "true" || string_value == "1") {
        return Value::make(true);
      } else if (string_value == "false" || string_value == "0") {
        return Value::make(false);
      } else {
        assert(false);
        throw Exception(ExceptionType::OUT_OF_RANGE, "BOOLEAN value out of range.");
      }
    }
    case TypeId::INTEGER: {
      int32_t integer = 0;
      try {
        integer = static_cast<int32_t>(std::stoi(value.to_string()));
      } catch (std::out_of_range &e) {
        throw Exception(ExceptionType::OUT_OF_RANGE, "INTEGER value out of range.");
      }
      return Value(type_id, integer);
    }
    case TypeId::TIMESTAMP: {
      int64_t timestamp = 0;
      try {
        timestamp = static_cast<int64_t>(std::stoi(value.to_string()));
      } catch (std::out_of_range &e) {
        throw Exception(ExceptionType::OUT_OF_RANGE, "TIMESTAMP value out of range.");
      }
      return Value(type_id, timestamp);
    }
    case TypeId::VARCHAR: {
      return value;
    }
    default:
      throw Exception("Not implemented! for this type : " + Type::as_string(type_id));
    }
  }
};
