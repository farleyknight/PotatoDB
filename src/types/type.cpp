#include "types/type.hpp"
#include "types/boolean_type.hpp"
#include "types/tinyint_type.hpp"
#include "types/smallint_type.hpp"
#include "types/integer_type.hpp"
#include "types/bigint_type.hpp"
#include "types/decimal_type.hpp"
#include "types/timestamp_type.hpp"
#include "types/varchar_type.hpp"
#include "types/invalid_type.hpp"

#include "value/value.hpp"

CRef<Ptr<Type>> Type::instance(TypeId type_id) {
  static MutMap<TypeId, Ptr<Type>> types_;
  if (types_.empty()) {
    types_.emplace(TypeId::BOOLEAN,  make_unique<BooleanType>());
    types_.emplace(TypeId::TINYINT,  make_unique<TinyIntType>());
    types_.emplace(TypeId::SMALLINT, make_unique<SmallIntType>());
    types_.emplace(TypeId::INTEGER,  make_unique<IntegerType>());
    types_.emplace(TypeId::BIGINT,   make_unique<BigIntType>());
    types_.emplace(TypeId::DECIMAL,  make_unique<DecimalType>());
    types_.emplace(TypeId::VARCHAR,  make_unique<VarCharType>());
    types_.emplace(TypeId::INVALID,  make_unique<InvalidType>());
  }

  return types_.at(type_id);
}

Value Type::min() const {
  throw NotImplementedException("min not implemented!");
}

Value Type::max() const {
  throw NotImplementedException("max not implemented!");
}

void Type::serialize_to(UNUSED MRef<Buffer> buff, UNUSED Value val) const {
  throw NotImplementedException("serialize_to not implemented!");
}

Value Type::deserialize_from(UNUSED CRef<Buffer> buff) const {
  throw NotImplementedException("deserialize_from not implemented!");
}

MutString Type::to_string(UNUSED const Value val) const {
  throw NotImplementedException("to_string not implemented!");
}

MutString Type::as_string(const TypeId type_id) {
  switch (type_id) {
  case TypeId::INVALID:   return "INVALID";
  case TypeId::BOOLEAN:   return "BOOLEAN";
  case TypeId::TINYINT:   return "TINYINT";
  case TypeId::SMALLINT:  return "SMALLINT";
  case TypeId::INTEGER:   return "INTEGER";
  case TypeId::BIGINT:    return "BIGINT";
  case TypeId::DECIMAL:   return "DECIMAL";
  case TypeId::TIMESTAMP: return "TIMESTAMP";
  case TypeId::VARCHAR:   return "VARCHAR";
  default:                return "INVALID";
  }
}

Value Type::add(UNUSED CRef<Value> left,
                UNUSED CRef<Value> right) const {
  throw NotImplementedException("add not implemented!");
}

Value Type::subtract(UNUSED CRef<Value> left,
                     UNUSED CRef<Value> right) const {
  throw NotImplementedException("subtract not implemented!");
}

Value Type::multiply(UNUSED CRef<Value> left,
                     UNUSED CRef<Value> right) const {
  throw NotImplementedException("multiply not implemented!");
}

Value Type::divide(UNUSED CRef<Value> left,
                   UNUSED CRef<Value> right) const {
  throw NotImplementedException("divide not implemented!");
}

Value Type::modulo(UNUSED CRef<Value> left,
                   UNUSED CRef<Value> right) const {
  throw NotImplementedException("modulo not implemented!");
}

Value Type::min(UNUSED CRef<Value> left,
                UNUSED CRef<Value> right) const {
  throw NotImplementedException("min not implemented!");
}

Value Type::max(UNUSED CRef<Value> left,
                UNUSED CRef<Value> right) const {
  throw NotImplementedException("max not implemented!");
}

Value Type::sqrt(UNUSED CRef<Value> val) const {
  throw NotImplementedException("max not implemented!");
}

Value Type::max_value(UNUSED TypeId type_id) {
  throw NotImplementedException("max not implemented!");
}

Value Type::min_value(UNUSED TypeId type_id) {
  throw NotImplementedException("max not implemented!");
}

