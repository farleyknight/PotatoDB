#include "common/config.hpp"
#include "catalog/base_schema.hpp"

template<class ColT>
BaseSchema<ColT>::BaseSchema(vector<ColT> cols) {
  size_t offset = 0;
  for (index_t oid = 0; oid < cols.size(); ++oid) {
    auto &col = cols[oid];

    if (!col.is_inlined()) {
      all_tuples_inlined_ = false;
      unlined_columns_.push_back(oid);
    }

    offsets_.push_back(offset);
    offset += col.fixed_length();

    column_oids_[col.name()] = oid;
    columns_.push_back(col);
  }

  tuple_length_ = offset;
}

template<class ColT>
bool BaseSchema<ColT>::has_column(const column_name_t& name) const {
  return column_oids_.count(name) > 0;
}

template<class ColT>
column_oid_t BaseSchema<ColT>::column_oid_for(const column_name_t& name) const
{
  assert(column_oids_.size() > 0);
  if (column_oids_.count(name) == 0) {
    std::cout << "Could not find column with name " << name << std::endl;
  }
  assert(column_oids_.count(name) == 1);
  return column_oids_.at(name);
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
buffer_offset_t BaseSchema<ColT>::buffer_offset_for(column_oid_t oid) const {
  return offsets_.at(oid);
}

template<class ColT>
buffer_offset_t BaseSchema<ColT>::buffer_offset_for(const column_name_t& name) const {
  return buffer_offset_for(column_oid_for(name));
}

template<class ColT>
column_index_t BaseSchema<ColT>::index_for(const column_name_t& name) const {
  return column_oid_for(name);
}

template<class ColT>
column_index_t BaseSchema<ColT>::column_count() const {
  return columns_.size();
}

template<class ColT>
buffer_offset_t BaseSchema<ColT>::tuple_length() const {
  return tuple_length_;
}

template<class ColT>
const vector<column_index_t>& BaseSchema<ColT>::unlined_columns() const {
  return unlined_columns_;
}

template<class ColT>
const ColT& BaseSchema<ColT>::by_name(const column_name_t& name) const {
  return columns_.at(column_oid_for(name));
}

template<class ColT>
const ColT& BaseSchema<ColT>::operator[](const column_name_t& name) const {
  return by_name(name);
}

template<class ColT>
const ColT& BaseSchema<ColT>::by_column_oid(column_oid_t oid) const {
  return columns_.at(oid);
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
