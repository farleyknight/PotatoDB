
#include "value/value.hpp"
#include "types/type.hpp"

void Value::serialize_to(size_t offset, Buffer& buff) {
  value_type()->serialize_to(buff, offset, *this);
}

Value Value::deserialize_from(const Buffer& buff,
                              size_t offset,
                              TypeId type_id) {
  return Type::instance(type_id)->deserialize_from(offset, buff);
}

bool Value::eq(const Value& other) const {
  return value_type()->eq(*this, other);
}

const Ptr<Type>& Value::value_type() const {
  return Type::instance(type_id_);
}

size_t Value::size() const {
  if (type_id_ == TypeId::VARCHAR) {
    return as<string>().size() + sizeof(int8_t);
  }
  return value_type()->size();
}

bool Value::is_null() const {
  return is_null_;
}

MutString Value::to_string() const {
  return value_type()->to_string(*this);
}

Value Value::add(const Value& other) const {
  return value_type()->add(*this, other);
}

Value Value::subtract(const Value& other) const {
  return value_type()->subtract(*this, other);
}

Value Value::multiply(const Value& other) const {
  return value_type()->multiply(*this, other);
}

Value Value::divide(const Value& other) const {
  return value_type()->divide(*this, other);
}
