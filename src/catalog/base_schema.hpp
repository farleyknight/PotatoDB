#pragma once

#include <type_traits>

#include "common/config.hpp"
#include "catalog/base_column.hpp"
#include "query/query_column.hpp"
#include "catalog/table_column.hpp"

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

  size_t column_count() const;
  size_t tuple_length() const;

  bool has_column(const column_name_t& name) const;
  size_t index_for(const column_name_t& name) const;
  column_oid_t column_oid_for(const column_name_t& name) const;
  size_t offset_for(column_oid_t oid) const;
  size_t offset_for(const column_name_t& name) const;

  const ColT& by_column_oid(column_oid_t oid) const;
  const ColT& by_name(const column_name_t& name) const;

  const vector<column_oid_t>& unlined_columns() const;
  const vector<ColT>& all() const;
  const vector<ColT>& columns() const;

  virtual const string to_string() const = 0;

  bool operator==(const BaseSchema& other) const {
    if (other.columns_.size() != columns_.size()) {
      return false;
    }

    for (index_t i = 0; i < columns_.size(); ++i) {
      if (other.columns_[i] != columns_[i]) {
        return false;
      }
    }

    return true;
  }
protected:
  // Are all tuples inlined when stored on the page?
  // If some of them are not inlined, the page layout will differ.
  bool all_tuples_inlined_ = true;

  vector<ColT> columns_;
  // keeps track of unlined columns, using logical position(start with 0)
  vector<column_oid_t> unlined_columns_;

  MutMap<column_name_t, column_oid_t> column_oids_;
  vector<offset_t> offsets_;

  // size of fixed length columns
  // NOTE: This *must* be uint32_t to keep consistent with page
  // layout offsets.
  uint32_t tuple_length_;
};

