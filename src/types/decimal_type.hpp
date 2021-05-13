#pragma once

#include "types/type.hpp"
#include "types/numeric_type.hpp"

class DecimalType : public NumericType<double> {
public:
  TypeId type_id() const override {
    return TypeId::DECIMAL;
  }

};
