#pragma once

#include "common/types.hpp"
#include "common/exceptions.hpp"

#include "buffer/buffer.hpp"

#include "types/type_id.hpp"

#include "value/value.hpp"

class Type {
public:
  virtual ~Type() = default;

  static const ptr<Type>& instance(TypeId type_id);

  virtual TypeId type_id() const = 0;

  virtual buffer_offset_t size() const = 0;

  virtual bool is_castable_from(UNUSED TypeId type_id) const {
    throw NotImplementedException("is_castable_from not implemented!");
  }

  virtual void serialize_to(UNUSED buffer_offset_t offset,
                            UNUSED Buffer& buff,
                            UNUSED Value val) const {
    throw NotImplementedException("serialize_to not implemented!");
  }

  // TODO: Rename this to 'read_from'
  virtual Value deserialize_from(buffer_offset_t offset, const Buffer& buff) const = 0;

  virtual const string to_string(UNUSED const Value& val) const  {
    throw NotImplementedException("to_string not implemented!");
  }

  static buffer_offset_t
  size_of(TypeId type_id) {
    return Type::instance(type_id)->size();
  }

  virtual bool
  eq(const Value& left,
     const Value& right) const = 0;

  virtual bool
  ne(UNUSED const Value& left,
     UNUSED const Value& right) const {
    throw NotImplementedException("ne not implemented!");
  }

  virtual bool
  lt(UNUSED const Value& left,
     UNUSED const Value& right) const {
    throw NotImplementedException("lt not implemented!");
  }

  virtual bool
  gt(UNUSED const Value& left,
     UNUSED const Value& right) const {
    throw NotImplementedException("gt not implemented!");
  }

  virtual bool
  lte(UNUSED const Value& left,
      UNUSED const Value& right) const {
    throw NotImplementedException("lte not implemented!");
  }

  virtual bool
  gte(UNUSED const Value& left,
      UNUSED const Value& right) const {
    throw NotImplementedException("gte not implemented!");
  }

  virtual Value
  cast_as(const Value& value, TypeId type_id) const = 0;

  virtual bool
  copy(UNUSED const Value& val) const {
    throw NotImplementedException("copy not implemented!");
  }

  virtual bool
  operate_null(UNUSED const Value& val,
               UNUSED const Value& right) const {
    throw NotImplementedException("operate_null not implemented!");
  }

  virtual bool
  is_zero(UNUSED const Value& val) const {
    throw NotImplementedException("is_zero not implemented!");
  }

  bool
  is_coercible_from(UNUSED const TypeId type_id) const {
    throw NotImplementedException("max not implemented!");
  }

  static int32_t
  as_int32(const TypeId type_id) {
    switch (type_id) {
    case TypeId::INVALID:   return 0;
    case TypeId::BOOLEAN:   return 1;
    case TypeId::TINYINT:   return 2;
    case TypeId::SMALLINT:  return 3;
    case TypeId::INTEGER:   return 4;
    case TypeId::BIGINT:    return 5;
    case TypeId::DECIMAL:   return 6;
    case TypeId::TIMESTAMP: return 7;
    case TypeId::VARCHAR:   return 8;
    default:                return 0;
    }
  }

  static TypeId
  from_int32(int32_t value) {
    switch (value) {
    case 0:  return TypeId::INVALID;
    case 1:  return TypeId::BOOLEAN;
    case 2:  return TypeId::TINYINT;
    case 3:  return TypeId::SMALLINT;
    case 4:  return TypeId::INTEGER;
    case 5:  return TypeId::BIGINT;
    case 6:  return TypeId::DECIMAL;
    case 7:  return TypeId::TIMESTAMP;
    case 8:  return TypeId::VARCHAR;
    default: return TypeId::INVALID;
    }
  }


  static const string
  as_string(const TypeId type_id) {
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

  static TypeId
  type_id_for(const string& name) {
    if (name == "INTEGER") {
      return TypeId::INTEGER;
    } else if (name == "VARCHAR") {
      return TypeId::VARCHAR;
    } else if (name == "BOOLEAN") {
      return TypeId::BOOLEAN;
    } else if (name == "TIMESTAMP") {
      return TypeId::TIMESTAMP;
    } else if (name == "SMALLINT") {
      return TypeId::SMALLINT;
    } else if (name == "BIGINT") {
      return TypeId::BIGINT;
    } else {
      throw Exception("Type not handled! " + name);
    }
  }

  virtual Value add(const Value& left,
                    const Value& right) const = 0;

  Value subtract(UNUSED const Value& left,
                 UNUSED const Value& right) const {
    throw NotImplementedException("subtract not implemented!");
  }

  Value multiply(UNUSED const Value& left,
                 UNUSED const Value& right) const {
    throw NotImplementedException("multiply not implemented!");
  }

  Value divide(UNUSED const Value& left,
               UNUSED const Value& right) const {
    throw NotImplementedException("divide not implemented!");
  }

  Value modulo(UNUSED const Value& left,
               UNUSED const Value& right) const {
    throw NotImplementedException("modulo not implemented!");
  }

  virtual Value min(UNUSED const Value& left,
                    UNUSED const Value& right) const = 0;
  virtual Value max(UNUSED const Value& left,
                    UNUSED const Value& right) const = 0;

  Value sqrt(UNUSED const Value& val) const {
    throw NotImplementedException("max not implemented!");
  }

  virtual Value min() const {
    throw NotImplementedException("max not implemented!");
  }

  virtual Value max() const {
    throw NotImplementedException("max not implemented!");
  }
};
