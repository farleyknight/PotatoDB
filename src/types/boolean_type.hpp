#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"

class BooleanType : public Type {
public:
  TypeId type_id() const override {
    return TypeId::BOOLEAN;
  }

  size_t size() const override {
    return sizeof(bool);
  }

  Value min() const override {
    return Value::make(false);
  }

  Value max() const override {
    return Value::make(true);
  }

  void serialize_to(MRef<Buffer> buff, Value val) const override {
    Type::rw().write_int8(buff, val.as<bool>());
  }

  Value deserialize_from(CRef<Buffer> buff) const override {
    return Value::make(Type::rw().read_int8(buff));
  }

  bool is_castable_from(UNUSED TypeId type_id) const override {
    return true;
  }

  bool eq(CRef<Value> left, CRef<Value> right) const override {
    if (left.is_null() && right.is_null()) {
      return true;
    } else if (left.is_null() || right.is_null()) {
      return false;
    } else {
      return left.as<bool>() == right.as<bool>();
    }
  }
};
