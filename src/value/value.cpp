
#include "value/value.hpp"
#include "types/type.hpp"

void Value::serialize_to(size_t offset, Buffer& buff) const {
  value_type()->serialize_to(offset, buff, *this);
}

Value Value::deserialize_from(size_t offset,
                              const Buffer& buff,
                              TypeId type_id) {
  return Type::instance(type_id)->deserialize_from(offset, buff);
}

const ptr<Type>& Value::value_type() const {
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

const string Value::to_string() const {
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

bool Value::eq(const Value& other) const {
  return value_type()->eq(*this, other);
}


bool Value::ne(const Value& other) const {
  return value_type()->ne(*this, other);
}

bool Value::lt(const Value& other) const {
  return value_type()->lt(*this, other);
}

bool Value::gt(const Value& other) const {
  return value_type()->gt(*this, other);
}

bool Value::lte(const Value& other) const {
  return value_type()->lte(*this, other);
}

bool Value::gte(const Value& other) const {
  return value_type()->gte(*this, other);
}


Value Value::max(const Value& other) const {
  return value_type()->max(*this, other);
}

Value Value::min(const Value& other) const {
  return value_type()->min(*this, other);
}
