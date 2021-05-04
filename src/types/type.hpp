#pragma once

#include "common/types.hpp"
#include "common/exceptions.hpp"

#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"
#include "buffer/cast_encoder.hpp"

#include "types/type_id.hpp"

#include "value/value.hpp"

class Type {
public:
  virtual ~Type() = default;

  static const Ptr<Type>& instance(TypeId type_id);

  virtual TypeId type_id() const {
    throw NotImplementedException("type_id not implemented!");
  }

  virtual size_t size() const {
    throw NotImplementedException("size not implemented!");
  }

  virtual bool is_castable_from(UNUSED TypeId type_id) const {
    throw NotImplementedException("is_castable_from not implemented!");
  }

  static Value min() {
    throw NotImplementedException("min not implemented!");
  }

  static Value max() {
    throw NotImplementedException("max not implemented!");
  }

  virtual void serialize_to(UNUSED size_t offset,
                            UNUSED Buffer& buff,
                            UNUSED Value val) const {
    throw NotImplementedException("serialize_to not implemented!");
  }

  virtual Value deserialize_from(UNUSED size_t offset,
                                 UNUSED const Buffer& buff) const {
    throw NotImplementedException("deserialize_from not implemented!");
  }

  virtual const string to_string(UNUSED const Value& val) const  {
    throw NotImplementedException("to_string not implemented!");
  }

  static size_t size_of(TypeId type_id) {
    return Type::instance(type_id)->size();
  }

  virtual bool eq(UNUSED CRef<Value> left,
                  UNUSED CRef<Value> right) const {
    throw NotImplementedException("eq not implemented!");
  }

  virtual bool ne(UNUSED CRef<Value> left,
                  UNUSED CRef<Value> right) const {
    throw NotImplementedException("ne not implemented!");
  }

  virtual bool lt(UNUSED CRef<Value> left,
                  UNUSED CRef<Value> right) const {
    throw NotImplementedException("lt not implemented!");
  }

  virtual bool gt(UNUSED CRef<Value> left,
                  UNUSED CRef<Value> right) const {
    throw NotImplementedException("gt not implemented!");
  }

  virtual bool lte(UNUSED CRef<Value> left,
                   UNUSED CRef<Value> right) const {
    throw NotImplementedException("lte not implemented!");
  }

  virtual bool gte(UNUSED CRef<Value> left,
                   UNUSED CRef<Value> right) const {
    throw NotImplementedException("gte not implemented!");
  }

  virtual bool cast_as(UNUSED CRef<Value> val,
                       UNUSED TypeId type_id) const {
    throw NotImplementedException("cast_as not implemented!");
  }

  virtual bool copy(UNUSED CRef<Value> val) const {
    throw NotImplementedException("copy not implemented!");
  }

  virtual bool operate_null(UNUSED CRef<Value> val,
                            UNUSED CRef<Value> right) const {
    throw NotImplementedException("operate_null not implemented!");
  }

  virtual bool is_zero(UNUSED CRef<Value> val) const {
    throw NotImplementedException("is_zero not implemented!");
  }

  bool is_coercible_from(UNUSED const TypeId type_id) const {
    throw NotImplementedException("max not implemented!");
  }

  static const string as_string(const TypeId type_id) {
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

  Value add(UNUSED CRef<Value> left,
            UNUSED CRef<Value> right) const {
    throw NotImplementedException("add not implemented!");
  }

  Value subtract(UNUSED CRef<Value> left,
                 UNUSED CRef<Value> right) const {
    throw NotImplementedException("subtract not implemented!");
  }

  Value multiply(UNUSED CRef<Value> left,
                 UNUSED CRef<Value> right) const {
    throw NotImplementedException("multiply not implemented!");
  }

  Value divide(UNUSED CRef<Value> left,
               UNUSED CRef<Value> right) const {
    throw NotImplementedException("divide not implemented!");
  }

  Value modulo(UNUSED CRef<Value> left,
               UNUSED CRef<Value> right) const {
    throw NotImplementedException("modulo not implemented!");
  }

  Value min(UNUSED CRef<Value> left,
            UNUSED CRef<Value> right) const {
    throw NotImplementedException("min not implemented!");
  }

  Value max(UNUSED CRef<Value> left,
            UNUSED CRef<Value> right) const {
    throw NotImplementedException("max not implemented!");
  }

  Value sqrt(UNUSED CRef<Value> val) const {
    throw NotImplementedException("max not implemented!");
  }

  Value max_value(UNUSED TypeId type_id) {
    throw NotImplementedException("max not implemented!");
  }

  Value min_value(UNUSED TypeId type_id) {
    throw NotImplementedException("max not implemented!");
  }
};
