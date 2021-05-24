#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"

class BooleanType : public Type {
private:
  using Type::serialize_to;

public:
  TypeId type_id() const override {
    return TypeId::BOOLEAN;
  }

  buffer_offset_t size() const override {
    return sizeof(bool);
  }

  Value add(const Value& left,
            const Value& right) const override
  {
    bool lhs = left.as<bool>(), rhs = right.as<bool>();
    if (lhs || rhs) {
      return Value::make(true);
    } else {
      return Value::make(false);
    }
  }

  Value min(const Value& left,
            const Value& right) const override
  {
    bool lhs = left.as<bool>(), rhs = right.as<bool>();
    if (lhs && rhs) {
      return Value::make(true);
    } else {
      return Value::make(false);
    }
  }

  Value max(const Value& left,
            const Value& right) const override
  {
    bool lhs = left.as<bool>(), rhs = right.as<bool>();
    if (lhs || rhs) {
      return Value::make(true);
    } else {
      return Value::make(false);
    }
  }

  Value min() const override {
    return Value::make(false);
  }

  Value max() const override {
    return Value::make(true);
  }

  // TODO: Rename to `write_to`
  void serialize_to(buffer_offset_t offset, Buffer& buff, Value val) const override {
    buff.write_bool(offset, val.as<bool>());
  }

  // TODO: Rename to `read_from`
  Value deserialize_from(buffer_offset_t offset, const Buffer& buff) const override {
    return Value::make(buff.read_bool(offset));
  }

  bool is_castable_from(UNUSED TypeId type_id) const override {
    return true;
  }

  bool eq(const Value& left, const Value& right) const override {
    if (left.is_null() && right.is_null()) {
      return true;
    } else if (left.is_null() || right.is_null()) {
      return false;
    } else {
      return left.as<bool>() == right.as<bool>();
    }
  }

  const string to_string(const Value& value) const override {
    if (value.is_null()) {
      return "NULL";
    } else {
      return value.as<bool>() ? "true" : "false";
    }
  }

  Value cast_as(const Value& value,
                TypeId type_id) const override {
    switch (type_id) {
    case TypeId::BOOLEAN:
      return value;
    default:
      throw Exception("Not implemented yet for BooleanType into " + Type::as_string(type_id));
    }
  }
};
