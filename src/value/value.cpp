
#include "value/value.hpp"
#include "types/type.hpp"

void Value::serialize_to(MutRef<Buffer> buff) {
  value_type()->serialize_to(buff, *this);
}

void Value::deserialize_from(Ref<Buffer> buff) {
  data_ = value_type()->deserialize_from(buff).data_;
}

bool Value::eq(Ref<Value> other) const {
  return value_type()->eq(*this, other);
}

Ref<Ptr<Type>> Value::value_type() const {
  return Type::instance(type_id_);
}

size_t Value::size() const {
  if (type_id_ == TypeId::VARCHAR) {
    return as<std::string>().size() + sizeof(int8_t);
  }
  return value_type()->size();
}

bool Value::is_null() const {
  return is_null_;
}

MutString Value::to_string() const {
  return value_type()->to_string(*this);
}