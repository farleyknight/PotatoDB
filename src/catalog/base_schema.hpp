#pragma once

#include <type_traits>

#include "common/config.hpp"
#include "catalog/base_column.hpp"
#include "catalog/table_column.hpp"
#include "tuple/tuple_layout.hpp"

template<class ColT>
class BaseSchema {
public:
  BaseSchema(vector<ColT> columns);

  // Allow copy
  BaseSchema(const BaseSchema&) = default;
  // Allow copy assign
  BaseSchema& operator=(const BaseSchema&) = default;
  // Default destructor
  ~BaseSchema() = default;

  column_index_t
  column_count() const;

  tuple_length_t
  inlined_tuple_length() const;

  tuple_length_t
  tuple_length(const vector<Value>& values) const;

  buffer_offset_t
  inline_tuple_length() const;

  bool
  has_column(column_oid_t oid) const;
  bool
  has_column(const column_name_t& name) const;

  column_index_t
  column_index_for(const column_name_t& name) const;
  column_index_t
  column_index_for(column_oid_t oid) const;

  column_oid_t
  column_oid_for(const column_name_t& name) const;
  column_oid_t
  column_oid_for(column_index_t index) const;

  buffer_offset_t
  buffer_offset_for(const column_name_t& name) const;
  buffer_offset_t
  buffer_offset_for(column_index_t index) const;

  const ColT&
  by_column_index(column_index_t index) const;
  const ColT&
  by_name(const column_name_t& name) const;

  const vector<column_index_t>&
  unlined_columns() const;

  vector<ColT>&
  all();
  const vector<ColT>&
  all() const;
  const vector<ColT>&
  columns() const;

  bool
  valid(const vector<Value>& values) const;

  virtual const string
  to_string() const = 0;

  table_oid_t
  table_oid() const {
    return table_oid_;
  }

  bool
  operator==(const BaseSchema& other) const;

  const ColT&
  operator[](const column_name_t& name) const;

  const ColT&
  operator[](column_oid_t oid) const;

  const vector<column_oid_t>&
  column_oids() const {
    return column_oids_;
  }

  const TupleLayout&
  layout() const {
    return tuple_layout_;
  }

protected:
  TupleLayout tuple_layout_;

  vector<ColT> columns_;
  vector<column_oid_t> column_oids_;

  map<column_name_t, column_index_t> indexes_;
  map<column_oid_t, column_index_t> column_oids_to_indices_;
  map<column_name_t, column_oid_t> column_names_to_oids_;

  table_oid_t table_oid_ = INVALID_TABLE_OID;
};
