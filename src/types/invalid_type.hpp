#pragma once

#include "types/type_id.hpp"
#include "types/type.hpp"

class InvalidType : public Type {
private:
  using Type::deserialize_from;

public:
  TypeId type_id() const override {
    return TypeId::INVALID;
  }

  // TODO: Rename to `write_to`
  void serialize_to(UNUSED size_t offset,
                    UNUSED Buffer& buff,
                    UNUSED Value val) const override {
    throw Exception("No serialize_to for InvalidType");
  }

  Value deserialize_from(UNUSED const Buffer& buff) const {
    throw Exception("No deserialize_from for InvalidType");
  }

  bool is_castable_from(UNUSED TypeId type_id) const override {
    return false;
  }

  size_t size() const override {
    throw Exception("No size for InvalidType");
  }

  static Value min() {
    throw Exception("No min for InvalidType");
  }

  static Value max() {
    throw Exception("No max for InvalidType");
  }
};

