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

  virtual bool eq(UNUSED CRef<Value> left, UNUSED CRef<Value> right) const {
    throw NotImplementedException("eq not implemented!");
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

  static CRef<BufferRW<>> rw() {
    static const BufferRW rw_;
    return rw_;
  }
};
