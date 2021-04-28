#pragma once

#include "common/types.hpp"
#include "common/exceptions.hpp"

#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"
#include "buffer/cast_encoder.hpp"

#include "types/type_id.hpp"

class Value;

class Type {
public:
  virtual ~Type() = default;

  virtual TypeId type_id() const {
    throw NotImplementedException("type_id not implemented!");
  }


  virtual size_t size() const {
    throw NotImplementedException("size not implemented!");
  }

  virtual bool is_castable_from(UNUSED TypeId type_id) const {
    throw NotImplementedException("is_castable_from not implemented!");
  }

  virtual Value min() const;
  virtual Value max() const;

  virtual void serialize_to(MRef<Buffer> buff, Value val) const;
  virtual Value deserialize_from(CRef<Buffer> buff) const;

  virtual MutString to_string(const Value val) const;

  static CRef<Ptr<Type>> instance(const TypeId type_id);
  static MutString as_string(const TypeId type_id);

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

  virtual Value add(CRef<Value> left, CRef<Value> right) const;
  virtual Value subtract(CRef<Value> left, CRef<Value> right) const;
  virtual Value multiply(CRef<Value> left, CRef<Value> right) const;
  virtual Value divide(CRef<Value> left, CRef<Value> right) const;
  virtual Value modulo(CRef<Value> left, CRef<Value> right) const;
  virtual Value min(CRef<Value> left, CRef<Value> right) const;
  virtual Value max(CRef<Value> left, CRef<Value> right) const;
  virtual Value sqrt(CRef<Value> val) const;

  static Value max_value(TypeId type_id);
  static Value min_value(TypeId type_id);

};
