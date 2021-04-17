#pragma once

#include "types/type_id.hpp"
#include "types/numeric_type.hpp"

class SmallIntType : public NumericType<int16_t> {
public:
  TypeId type_id() const override {
    return TypeId::SMALLINT;
  }
};
