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

  bool eq(UNUSED const Value& left,
          UNUSED const Value& right) const override
  {
    throw Exception("No deserialize_from for InvalidType");
  }

  // TODO: Rename to `write_to`
  void serialize_to(UNUSED buffer_offset_t offset,
                    UNUSED Buffer& buff,
                    UNUSED Value val) const override
  {
    throw Exception("No serialize_to for InvalidType");
  }

  Value deserialize_from(UNUSED buffer_offset_t offset, UNUSED const Buffer& buff) const override
  {
    throw Exception("No deserialize_from for InvalidType");
  }

  bool is_castable_from(UNUSED TypeId type_id) const override {
    return false;
  }

  buffer_offset_t size() const override {
    throw Exception("No size for InvalidType");
  }

  Value min() const override {
    throw Exception("No min for InvalidType");
  }

  Value max() const override {
    throw Exception("No max for InvalidType");
  }

  Value add(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    throw Exception("No add for InvalidType");
  }

  Value min(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    throw Exception("No min for InvalidType");
  }

  Value max(UNUSED const Value& left,
            UNUSED const Value& right) const override
  {
    throw Exception("No max for InvalidType");
  }

  Value cast_as(UNUSED const Value& value, UNUSED TypeId type_id) const override {
    throw Exception("No cast_as for InvalidType");
  }
};

