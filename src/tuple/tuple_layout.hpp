#pragma once

#include "common/config.hpp"
#include "value/value.hpp"
#include "value/value_layout.hpp"

#include "tuple/value_map.hpp"

#include "txns/txn.hpp"

class TupleLayout {
public:
  TupleLayout() = default;

  static Tuple
  make(const ValueMap& value_map,
       Txn& txn);

  void
  push_back(column_oid_t oid,
            TypeId type_id,
            buffer_offset_t buffer_offset,
            bool is_inlined);

  const ValueLayout&
  operator[](column_oid_t oid) const {
    return find(oid);
  }

  const ValueLayout&
  find(column_oid_t oid) const {
    return value_layouts_.at(oid);
  }

  const map<column_oid_t, ValueLayout>&
  value_layouts() const {
    return value_layouts_;
  }

  bool
  validate(const vector<Value>& values) const;

  column_index_t
  column_count() const {
    return value_layouts_.size();
  }

  void
  set_inlined_tuple_length(tuple_length_t tuple_length) {
    inlined_tuple_length_ = tuple_length;
  }

  tuple_length_t
  inlined_tuple_length() const {
    return inlined_tuple_length_;
  }

  const vector<column_oid_t>&
  unlined_columns() const {
    return unlined_columns_;
  }

  const string
  to_string() const;

  void
  write_values(const vector<Value>& values,
               Buffer& buffer) const;

  buffer_offset_t
  buffer_offset_for(const Buffer& buffer,
                    column_index_t index) const;

  buffer_offset_t
  buffer_offset_for(const Tuple& tuple,
                    column_index_t index) const
  {
    return buffer_offset_for(tuple.buffer(), index);
  }

  Value
  value_by_oid(const Tuple& tuple,
               column_oid_t oid) const;

  bool
  is_null(const Tuple& tuple,
          column_index_t column_index) const;

  Tuple
  key_from_tuple(const Tuple& tuple,
                 const vector<int32_t>& key_attrs,
                 Txn& txn) const;

  const ValueMap
  to_value_map(const Tuple& tuple) const;

  void
  add_defaults(ValueMap& value_map,
               const ValueMap& defaults,
               Txn& txn) const;

  const string
  to_string(const Tuple& tuple) const;
  const string
  to_string(const ValueMap& value_map) const;
  const string
  to_payload(const Tuple& tuple) const;

  static Tuple
  random_tuple();

private:
  // Are all tuples inlined when stored on the page?
  // If some of them are not inlined, the tuple layout will differ.
  bool all_tuples_inlined_ = true;
  int32_t inlined_tuple_length_ = INVALID_TUPLE_LENGTH;
  vector<column_oid_t> unlined_columns_;
  map<column_oid_t, ValueLayout> value_layouts_;
};
