#pragma once

#include "types/type_id.hpp"
#include "types/type.hpp"

class InvalidType : public Type {
public:
  TypeId type_id() const override {
    return TypeId::INVALID;
  }

  Value deserialize_from(UNUSED Ref<Buffer> buff) const override {
    throw Exception("No deserialize_from for InvalidType");
  }

  bool is_castable_from(UNUSED TypeId type_id) const override {
    return false;
  }

  size_t size() const override {
    throw Exception("No size for InvalidType");
  }

  Value min() const override {
    throw Exception("No min for InvalidType");
  }

  Value max() const override {
    throw Exception("No max for InvalidType");
  }
};

