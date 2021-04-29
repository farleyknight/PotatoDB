#pragma once

#include <cstring>

#include "tuple/tuple.hpp"
#include "value/value.hpp"

// TODO: I really hate the name GenericKey. I feel the like word
// Generic does not help the reader at all.
//
// I think a better name would just be, like, `Key`?
// But not sure if that helps.. I think it's too short.
//
// I would prefer something at least 5 letters.
// Maybe Value Key? Or Tuple Key?
// TupleKey might even work..
//
// Because the main data attribute `data_` is interpreted as a tuple.
// And we are indexing via some tuple (1, 2) or (3, 4), in
// lexicographical order.
//
class GenericKey {
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
  // TODO: Add tests for KEY_SIZE = 16 and 32.
  static constexpr int KEY_SIZE = 8;

  GenericKey() = default;
  GenericKey(int key) {
    set_from_integer(key);
  }

  void set_from_key(CRef<Tuple> tuple) {
    data_.copy_n_bytes(0,
                       0,
                       tuple.buffer(),
                       tuple.size());
  }

  // NOTE: for test purpose only
  void set_from_integer(int64_t key) {
    data_.write_int64(0, key);
  }

  template<class C>
  Value to_value(CRef<BaseSchema<C>> schema, size_t index) const {
    size_t offset = 0;
    const auto &col = schema.by_column_oid(index);
    const TypeId column_type = col.type_id();
    const bool is_inlined = col.is_inlined();
    if (is_inlined) {
      offset = schema.offset_for(index);
    } else {
      auto schema_offset = schema.offset_for(index);
      auto index_offset =
        *reinterpret_cast<const int32_t *>(data_.cptr(schema_offset));
      offset =
        *reinterpret_cast<const int32_t *>(data_.cptr(index_offset));
    }
    return Value::deserialize_from(data_, offset, column_type);
  }

  Buffer data_ {KEY_SIZE};
};
