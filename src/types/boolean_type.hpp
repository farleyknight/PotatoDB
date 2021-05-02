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

  void serialize_to(Buffer& buff, Value val) const override {
    size_t offset = 0;
    buff.write_int8(offset, val.as<bool>());
  }

  Value deserialize_from(CRef<Buffer> buff) const override {
    size_t offset = 0;
    return Value::make(buff.read_int8(offset));
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
