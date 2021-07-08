#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"
#include "types/numeric_type.hpp"

class IntegerType : public NumericType<int32_t> {
public:
  TypeId type_id() const override {
    return TypeId::INTEGER;
  }

  buffer_offset_t size() const override {
    return sizeof(int32_t);
  }

  void serialize_to(buffer_offset_t offset,
                    Buffer& buff,
                    Value val) const override
  {
    buff.write_int32(offset, val.as<int32_t>());
  }

  Value cast_as(const Value& value,
                TypeId type_id) const override
  {
    switch (type_id) {
    case TypeId::INTEGER: {
      return value;
    }
    case TypeId::SMALLINT: {
      auto as_int32 = value.as<int32_t>();
      if (as_int32 > Int16::MAX || as_int32 < Int16::MIN) {
        throw Exception(ExceptionType::OUT_OF_RANGE, "Numeric value out of range.");
      }
      auto as_int16 = static_cast<int16_t>(as_int32);
      return Value::make(as_int16);
    }
    default:
      throw Exception("cast_as in IntegerType is not fully implemented! :(");
    }

    throw Exception("This cast not handled yet");
  }
};
