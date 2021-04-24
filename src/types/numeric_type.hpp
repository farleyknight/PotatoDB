#pragma once

#include "types/type_id.hpp"
#include "types/type.hpp"
#include "buffer/buffer.hpp"

template<typename numeric_t>
class NumericType : public Type {
public:
  size_t size() const override {
    return sizeof(numeric_t);
  }

  bool is_castable_from(TypeId type_id) const override {
    switch (type_id) {
    case TypeId::TINYINT:
    case TypeId::SMALLINT:
    case TypeId::INTEGER:
    case TypeId::BIGINT:
    case TypeId::DECIMAL:
    case TypeId::VARCHAR:
      return true;
    default:
      break;
    }

    return false;
  }

  bool eq(CRef<Value> left, CRef<Value> right) const override {
    if (left.is_null() && right.is_null()) {
      return true;
    } else if (left.is_null() || right.is_null()) {
      return false;
    } else {
      return left.as<numeric_t>() == right.as<numeric_t>();
    }
  }

  void serialize_to(MRef<Buffer> buff, Value val) const override {
    Type::rw().write_int<numeric_t>(buff, val.as<numeric_t>());
  }

  Value deserialize_from(CRef<Buffer> buff) const override {
    return Value::make(Type::rw().read_int<numeric_t>(buff));
  }

  Value min() const override {
    return Value::make(numeric_limits<numeric_t>::min());
  }

  Value max() const override {
    return Value::make(numeric_limits<numeric_t>::max());
  }
};
