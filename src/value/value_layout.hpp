#pragma once

#include "common/ids.hpp"
#include "types/type_id.hpp"

class ValueLayout {
public:
  ValueLayout(TypeId type_id,
              buffer_offset_t buffer_offset,
              bool is_inlined)
    : type_id_       (type_id),
      buffer_offset_ (buffer_offset),
      is_inlined_    (is_inlined)
  {}

  TypeId
  type_id() const {
    return type_id_;
  }

  buffer_offset_t
  offset() const {
    return buffer_offset_;
  }

  bool
  is_inlined() const {
    return is_inlined_;
  }

private:
  const TypeId type_id_;
  const buffer_offset_t buffer_offset_;
  const bool is_inlined_;
};

