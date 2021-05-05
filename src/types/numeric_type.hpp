#pragma once

#include "types/type_id.hpp"
#include "types/type.hpp"
#include "buffer/buffer.hpp"

template<typename numeric_t>
class NumericType : public Type {
private:
  using Type::serialize_to;
public:

  size_t size() const override {
    return sizeof(numeric_t);
  }

  const string to_string(const Value& value) const override {
    if (value.is_null()) {
      return "NULL";
    }
    return std::to_string(value.as<numeric_t>());
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

  bool eq(const Value& left, const Value& right) const override {
    if (left.is_null() && right.is_null()) {
      return true;
    } else if (left.is_null() || right.is_null()) {
      return false;
    } else {
      return left.as<numeric_t>() == right.as<numeric_t>();
    }
  }

  void serialize_to(size_t offset, Buffer& buff, Value val) const override {
    buff.write_numeric<numeric_t>(offset, val.as<numeric_t>());
  }

  Value deserialize_from(size_t offset, const Buffer& buff) const override {
    return Value::make(buff.read_numeric<numeric_t>(offset));
  }

  Value min() const override {
    return Value::make(numeric_limits<numeric_t>::min());
  }

  Value max() const override {
    return Value::make(numeric_limits<numeric_t>::max());
  }
};

template class NumericType<signed char>;
template class NumericType<int16_t>;
template class NumericType<int32_t>;
template class NumericType<int64_t>;
template class NumericType<double>;
