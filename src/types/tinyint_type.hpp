#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"
#include "types/numeric_type.hpp"

class TinyIntType : public NumericType<int8_t> {
public:
  TypeId type_id() const override {
    return TypeId::TINYINT;
  }
};
