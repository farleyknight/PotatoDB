#pragma once

#include "common/config.hpp"
#include "value/value.hpp"
#include "value/value_layout.hpp"
#include "txns/txn.hpp"

#include "txns/txn.hpp"

class TupleLayout {
public:
  TupleLayout() = default;

  static Tuple
  make(const map<column_oid_t, Value>& values,
       const TupleLayout& layout,
       Txn& txn);

  void
  push_back(TypeId type_id,
            buffer_offset_t buffer_offset,
            bool is_inlined);

  const ValueLayout&
  operator[](column_index_t index) const {
    return find(index);
  }

  const ValueLayout&
  find(column_index_t index) const {
    return value_layouts_[index];
  }

  bool
  validate(const vector<Value>& values) const;

  column_index_t
  column_count() const {
    return value_layouts_.size();
  }

  tuple_length_t
  tuple_length(const vector<Value>& values) const;

  void
  set_inlined_tuple_length(tuple_length_t tuple_length) {
    inlined_tuple_length_ = tuple_length;
  }

  tuple_length_t
  inlined_tuple_length() const {
    return inlined_tuple_length_;
  }

  const vector<column_index_t>&
  unlined_columns() const {
    return unlined_columns_;
  }

  const string
  to_string() const;

  void
  write_values(const vector<Value>& values,
               Buffer& buffer) const;

  buffer_offset_t
  buffer_offset_for(const Tuple& tuple,
                    column_index_t index) const;

  Value
  value_by_index(const Tuple& tuple,
                 column_index_t column_index) const;

  Value
  value_by_name(const Tuple& tuple,
                const column_name_t& name) const;

  Value
  value_by_oid(const Tuple& tuple,
               column_oid_t oid) const;

  bool
  is_null(const Tuple& tuple,
          column_index_t column_index) const;

  Tuple
  key_from_tuple(const Tuple& tuple,
                 const QuerySchema& key_schema,
                 const vector<int32_t>& key_attrs,
                 Txn& txn) const;

  const vector<Value>
  to_values(const QuerySchema& schema) const;

  const map<column_oid_t, Value>
  to_value_map(const QuerySchema& schema) const;

  Tuple
  add_defaults(const map<column_oid_t, Value>& defaults,
               const TableSchema& table_schema,
               const QuerySchema& query_schema,
               Txn& txn) const;

  const string
  to_string(const Tuple& tuple) const;
  const string
  to_payload(const Tuple& tuple) const;

  static Tuple
  random_tuple();

private:
  // Are all tuples inlined when stored on the page?
  // If some of them are not inlined, the tuple layout will differ.
  bool all_tuples_inlined_ = true;
  int32_t inlined_tuple_length_ = INVALID_TUPLE_LENGTH;
  vector<column_index_t> unlined_columns_;
  vector<ValueLayout> value_layouts_;
};
