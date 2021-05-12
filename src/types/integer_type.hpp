#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"
#include "types/numeric_type.hpp"

class IntegerType : public NumericType<int32_t> {
public:
  TypeId type_id() const override {
    return TypeId::INTEGER;
  }

  size_t size() const override {
    return 4;
  }
};
