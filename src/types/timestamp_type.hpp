#pragma once

#include "types/type.hpp"
#include "types/numeric_type.hpp"

class TimestampType : public NumericType<timestamp_t> {
public:
  TypeId type_id() const override {
    return TypeId::TIMESTAMP;
  }

  Value cast_as(UNUSED const Value& value,
                UNUSED TypeId type_id) const override
  {
    switch (type_id) {
    case TypeId::TIMESTAMP: {
      return value;
    }
    default:
      throw Exception("Not implemented! :(");
    }
    throw Exception("This cast not handled yet");
  }
};
