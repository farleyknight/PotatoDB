#pragma once

#include "common/config.hpp"
#include "value/value.hpp"
#include "value/value_layout.hpp"
#include "txns/txn.hpp"

class TupleLayout {
public:
  TupleLayout() = default;

  void
  push_back(TypeId type_id,
            buffer_offset_t buffer_offset,
            bool is_inlined)
  {
    if (!is_inlined) {
      column_index_t index = value_layouts_.size();
      unlined_columns_.push_back(index);
      all_tuples_inlined_ = false;
    }
    auto new_layout = ValueLayout(type_id, buffer_offset, is_inlined);
    value_layouts_.push_back(new_layout);
  }

  const ValueLayout&
  operator[](column_index_t index) const {
    return find(index);
  }

  const ValueLayout&
  find(column_index_t index) const {
    return value_layouts_[index];
  }

  // TODO: Pass in ref to Txn and abort the txn if the validation fails.
  bool
  validate(const vector<Value>& values) const
  {
    // Check size
    int32_t values_size = values.size();

    if (values_size != column_count()) {
      std::cout << "values.size() == "
                << values.size() << std::endl;
      std::cout << "schema.column_count() == "
                << column_count() << std::endl;
      assert(values_size == column_count());
    }

    // Check value types versus schema types
    //
    // TODO: Write proper error handling should be a good next step
    // towards being a robust database.
    for (int32_t i = 0; i < values_size; ++i) {
      assert(values[i].type_id() == find(i).type_id());
    }

    return true;
  }

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
  to_string() const {
    stringstream os;

    os << "NumColumns:"         << value_layouts_.size()  << ", "
       << "IsInlined:"          << all_tuples_inlined_    << ", "
       << "InlinedTupleLength:" << inlined_tuple_length_;

    return os.str();
  }

  void
  write_values(const vector<Value>& values,
               Buffer& buffer) const;

  static Tuple
  make(const map<column_oid_t, Value>& values,
       const TupleLayout& layout,
       Txn& txn);

  buffer_offset_t
  buffer_offset_for(const Tuple& tuple,
                    column_index_t index) const;

  Value
  value_by_column_index(const auto& schema,
                        column_index_t column_index) const;

  Value
  value_by_name(const QuerySchema& schema,
                const column_name_t& name) const;

  Value
  value_by_oid(const QuerySchema& schema,
               column_oid_t oid) const;

  Value
  value_by_oid(const TableSchema& schema,
               column_oid_t oid) const;

  bool
  is_null(const auto& schema,
          column_index_t column_index) const;

  Tuple
  key_from_tuple(const QuerySchema& schema,
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
