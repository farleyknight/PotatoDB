#pragma once

#include <type_traits>

#include "common/config.hpp"
#include "catalog/base_column.hpp"
#include "query/query_column.hpp"
#include "catalog/table_column.hpp"

template<class ColT>
class BaseSchema {
public:
  BaseSchema(vector<ColT> columns, vector<string> names);

  // Allow copy
  BaseSchema(const BaseSchema&) = default;
  // Allow copy assign
  BaseSchema& operator=(const BaseSchema&) = default;
  // Default destructor
  ~BaseSchema() = default;

  size_t column_count() const;
  size_t tuple_length() const;

  bool has_column(const string& name) const;
  size_t index_for(const string& name) const;
  column_oid_t column_oid_for(const string& name) const;
  size_t offset_for(column_oid_t oid) const;
  size_t offset_for(const string& name) const;

  const ColT& by_offset(size_t offset) const;
  const ColT& by_index(size_t index) const {
    return by_offset(index);
  }

  const ColT& by_column_oid(column_oid_t oid) const;
  const ColT& by_name(string name) const;

  const vector<column_oid_t>& unlined_columns() const;
  const vector<ColT>& all() const;

  virtual const string to_string() const = 0;

protected:
  // Are all tuples inlined when stored on the page?
  // If some of them are not inlined, the page layout will differ.
  bool all_tuples_inlined_ = true;

  vector<ColT> columns_;
  // keeps track of unlined columns, using logical position(start with 0)
  vector<column_oid_t> unlined_columns_;

  MutMap<string, column_oid_t> column_oids_;
  vector<size_t> offsets_;

  // size of fixed length columns
  // NOTE: This *must* be uint32_t to keep consistent with page
  // layout offsets.
  uint32_t tuple_length_;
};

