#pragma once

#include "types/type.hpp"
#include "types/numeric_type.hpp"

class DecimalType : public NumericType<double> {
public:
  TypeId type_id() const override {
    return TypeId::DECIMAL;
  }

  Value cast_as(UNUSED const Value& value,
                UNUSED TypeId type_id) const override {
    throw Exception("Not implemented yet");
  }
};
