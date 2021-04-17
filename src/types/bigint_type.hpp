#pragma once

#include "types/type_id.hpp"
#include "types/numeric_type.hpp"

class BigIntType : public NumericType<int64_t> {
public:
  TypeId type_id() const override {
    return TypeId::BIGINT;
  }
};
