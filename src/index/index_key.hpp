#pragma once

#include <cstring>

#include "tuple/tuple.hpp"
#include "value/value.hpp"
#include "tuple/tuple_layout.hpp"

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

  Value
  to_value(const TupleLayout& layout,
           column_index_t index) const
  {
    auto offset = layout.buffer_offset_for(data_, index);
    auto type_id = layout.find(index).type_id();
    return Value::deserialize_from(offset, data_, type_id);
  }

  Buffer data_ {KEY_SIZE};
};
