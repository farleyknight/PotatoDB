#pragma once

#include <cstring>

#include "tuple/tuple.hpp"
#include "value/value.hpp"
#include "catalog/index_schema.hpp"

class IndexKey {
public:
  // NOTE: In reality, the only thing we test on is eight byte keys.
  //
  // However, if we keep it this way, then whenever we go and create
  // new indexes, it will only recognize the first 8 bytes of the
  // columns.
  //
  // This limit might be hit later.
  //
  // So keep this in mind, and add more tests for 16 and 32 byte keys.
  //
  // TODO: Make KEY_SIZE a parameter.
  // This is effectively the max length of the key.
  static constexpr int KEY_SIZE = 8;

  IndexKey() = default;
  IndexKey(int key) {
    set_from_integer(key);
  }

  void set_from_key(const Tuple& tuple) {
    data_.copy_n_bytes(0,
                       0,
                       tuple.buffer(),
                       tuple.size());
  }

  // NOTE: for test purpose only
  void set_from_integer(int64_t key) {
    data_.write_int64(0, key);
  }

  Value to_value(const IndexSchema& schema, column_index_t index) const {
    size_t offset = 0;
    const auto &col = schema.by_column_index(index);
    const TypeId column_type = col.type_id();
    const bool is_inlined = col.is_inlined();
    if (is_inlined) {
      offset = schema.buffer_offset_for(index);
    } else {
      auto schema_offset = schema.buffer_offset_for(index);
      auto index_offset =
        *reinterpret_cast<const buffer_offset_t *>(data_.const_ptr(schema_offset));
      offset =
        *reinterpret_cast<const buffer_offset_t *>(data_.const_ptr(index_offset));
    }
    return Value::deserialize_from(offset, data_, column_type);
  }

  Value to_value(const QuerySchema& schema, column_index_t index) const {
    size_t offset = 0;
    const auto &col = schema.by_column_index(index);
    const TypeId column_type = col.type_id();
    const bool is_inlined = col.is_inlined();
    if (is_inlined) {
      offset = schema.buffer_offset_for(index);
    } else {
      auto schema_offset = schema.buffer_offset_for(index);
      auto index_offset =
        *reinterpret_cast<const buffer_offset_t *>(data_.const_ptr(schema_offset));
      offset =
        *reinterpret_cast<const buffer_offset_t *>(data_.const_ptr(index_offset));
    }
    return Value::deserialize_from(offset, data_, column_type);
  }

  Buffer data_ {KEY_SIZE};
};
