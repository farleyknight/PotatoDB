#include "common/config.hpp"
#include "catalog/base_schema.hpp"

template<class ColT>
BaseSchema<ColT>::BaseSchema(vector<ColT> cols) {
  size_t offset = 0;

  assert(cols.size() > 0); // NOTE: Empty schemas are not a thing :/
  // NOTE: If we have a table_oid_ for the schema, it is because
  // all columns have the same table_oid_
  table_oid_ = cols[0].table_oid();

  for (uint32_t index = 0; index < cols.size(); ++index) {
    auto &col = cols[index];

    // NOTE: If the 2nd column has a different table_oid,
    // then we have more than one.
    // The variable is set to INVALID_TABLE_OID
    if (index > 0 && table_oid_ != col.table_oid()) {
      table_oid_ = INVALID_TABLE_OID;
    }

    if (column_oids_.count(col.name()) > 0) {
      continue; // NOTE: Skip duplicates
    }

    if (!col.is_inlined()) {
      // NOTE: Inlined tuples are faster to read because of less indirection
      all_tuples_inlined_ = false;
      unlined_columns_.push_back(index);
    }

    indexes_[col.name()] = index;

    offsets_.push_back(offset);
    offset += col.fixed_length();

    column_oids_[col.name()] = col.column_oid();
    columns_.push_back(col);
  }

  tuple_length_ = offset;
}

template<class ColT>
bool BaseSchema<ColT>::has_column(const column_name_t& name) const {
  return column_oids_.count(name) > 0;
}

template<class ColT>
column_oid_t
BaseSchema<ColT>::column_oid_for(const column_name_t& name) const
{
  assert(column_oids_.size() > 0);
  if (column_oids_.count(name) == 0) {
    std::cout << "Could not find column with name " << name << std::endl;
  }
  assert(column_oids_.count(name) == 1);
  return column_oids_.at(name);
}

template<class ColT>
column_oid_t
BaseSchema<ColT>::column_oid_for(column_index_t index) const
{
  return columns_[index].column_oid();
}


template<class ColT>
bool BaseSchema<ColT>::operator==(const BaseSchema& other) const {
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

template<class ColT>
buffer_offset_t
BaseSchema<ColT>::buffer_offset_for(column_index_t index) const {
  return offsets_.at(index);
}

template<class ColT>
buffer_offset_t
BaseSchema<ColT>::buffer_offset_for(const column_name_t& name) const {
  return buffer_offset_for(column_oid_for(name));
}

template<class ColT>
column_index_t
BaseSchema<ColT>::column_index_for(const column_name_t& name) const {
  assert(indexes_.count(name) == 1);
  return indexes_.at(name);
}

template<class ColT>
column_index_t
BaseSchema<ColT>::column_count() const {
  return columns_.size();
}

template<class ColT>
buffer_offset_t
BaseSchema<ColT>::tuple_length() const {
  return tuple_length_;
}

template<class ColT>
const vector<column_index_t>&
BaseSchema<ColT>::unlined_columns() const {
  return unlined_columns_;
}

template<class ColT>
const ColT&
BaseSchema<ColT>::by_name(const column_name_t& name) const {
  auto index = column_index_for(name);
  return by_column_index(index);
}

template<class ColT>
const ColT&
BaseSchema<ColT>::operator[](const column_name_t& name) const {
  return by_name(name);
}

template<class ColT>
const ColT&
BaseSchema<ColT>::by_column_index(column_index_t index) const {
  auto size = static_cast<long>(columns_.size());
  assert(size >= index);
  return columns_.at(index);
}

template<class ColT>
const vector<ColT>& BaseSchema<ColT>::all() const {
  return columns_;
}

template<class ColT>
const vector<ColT>& BaseSchema<ColT>::columns() const {
  return columns_;
}

template class BaseSchema<QueryColumn>;
template class BaseSchema<TableColumn>;
