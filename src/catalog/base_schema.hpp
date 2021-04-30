#pragma once

#include <type_traits>

#include "common/config.hpp"
#include "catalog/base_column.hpp"

template<class ColT>
class BaseSchema {
public:
  BaseSchema(Vec<ColT> columns);

  // No copy
  BaseSchema(CRef<BaseSchema>) = delete;
  // No copy assign
  BaseSchema& operator=(CRef<BaseSchema>) = delete;
  // Default destructor
  ~BaseSchema() = default;

  size_t column_count() const;
  size_t tuple_length() const;

  bool has_column(CRef<String> name) const;
  column_oid_t column_oid_for(CRef<String> name) const;
  size_t offset_for(column_oid_t oid) const;
  size_t offset_for(CRef<String> name) const;

  CRef<ColT> by_column_oid(const column_oid_t oid) const;
  CRef<ColT> by_name(CRef<String> name) const;

  CRef<Vec<size_t>> unlined_columns() const;
  CRef<Vec<ColT>> all() const;

  virtual string to_string() const = 0;

protected:
  // Are all tuples inlined when stored on the page?
  // If some of them are not inlined, the page layout will differ.
  bool all_tuples_inlined_ = true;

  MutVec<ColT> columns_;
  // keeps track of unlined columns, using logical position(start with 0)
  MutVec<column_oid_t> unlined_columns_;

  MutMap<MutString, column_oid_t> column_oids_;
  MutVec<size_t> offsets_;

  // size of fixed length columns
  // NOTE: This *must* be uint32_t to keep consistent with page
  // layout offsets.
  uint32_t tuple_length_;
};
