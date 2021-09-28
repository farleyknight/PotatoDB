#include "common/config.hpp"
#include "catalog/base_schema.hpp"

template<class ColT>
BaseSchema<ColT>::BaseSchema(vector<ColT> cols) {
  int32_t offset = 0;
  column_index_t cols_size = cols.size();
  assert(cols_size > 0);

  table_oid_ = cols[0].table_oid();

  for (int32_t index = 0; index < cols_size; ++index) {
    const auto &col  = cols[index];
    auto oid         = col.oid();
    const auto &name = col.name();

    // NOTE: If the 2nd column has a different table_oid,
    // then we have more than one.
    // The variable is set to INVALID_TABLE_OID
    if (index > 0 && table_oid_ != col.table_oid()) {
      table_oid_ = INVALID_TABLE_OID;
    }

    if (column_names_to_oids_.contains(name)) {
      // TODO: ABORT!
      // If we happen to hit a duplicate, we should probably ABORT with info
      // about it
      continue; // NOTE: Skip duplicates
    }

    tuple_layout_.push_back(col.type_id(),
                            offset,
                            col.is_inlined());
    offset += col.fixed_length();

    indexes_.emplace(name, index);
    column_oids_to_indices_.emplace(oid, index);
    column_names_to_oids_.emplace(name, oid);

    column_oids_.push_back(oid);
    columns_.push_back(col);
  }

  tuple_layout_.set_inlined_tuple_length(offset);
}

template<class ColT>
bool
BaseSchema<ColT>::has_column(const column_name_t& name) const {
  return column_names_to_oids_.contains(name);
}


template<class ColT>
bool
BaseSchema<ColT>::has_column(column_oid_t oid) const {
  return column_oids_to_indices_.contains(oid);
}

template<class ColT>
column_oid_t
BaseSchema<ColT>::column_oid_for(const column_name_t& name) const
{
  if (!column_names_to_oids_.contains(name)) {
    std::cout << "Could not find column with name " << name << std::endl;
  }
  assert(column_names_to_oids_.contains(name));
  return column_names_to_oids_.at(name);
}

template<class ColT>
column_oid_t
BaseSchema<ColT>::column_oid_for(column_index_t index) const
{
  return column_oids_[index];
}

template<class ColT>
bool
BaseSchema<ColT>::operator==(const BaseSchema& other) const {
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
  return tuple_layout_[index].offset();
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
column_index_t
BaseSchema<ColT>::column_index_for(column_oid_t oid) const {
  return column_oids_to_indices_.at(oid);
}

template<class ColT>
tuple_length_t
BaseSchema<ColT>::inlined_tuple_length() const {
  return tuple_layout_.inlined_tuple_length();
}

template<class ColT>
const vector<column_index_t>&
BaseSchema<ColT>::unlined_columns() const {
  return tuple_layout_.unlined_columns();
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
BaseSchema<ColT>::operator[](column_oid_t oid) const {
  assert(column_oids_to_indices_.contains(oid));
  return by_column_index(column_oids_to_indices_.at(oid));
}

template<class ColT>
const ColT&
BaseSchema<ColT>::by_column_index(column_index_t index) const {
  auto size = static_cast<int32_t>(columns_.size());
  assert(size >= index);
  return columns_.at(index);
}

template<class ColT>
const vector<ColT>& BaseSchema<ColT>::all() const {
  return columns_;
}

template<class ColT>
vector<ColT>& BaseSchema<ColT>::all() {
  return columns_;
}

template<class ColT>
const vector<ColT>& BaseSchema<ColT>::columns() const {
  return columns_;
}

template class BaseSchema<QueryColumn>;
template class BaseSchema<TableColumn>;
