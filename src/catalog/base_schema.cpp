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
column_oid_t BaseSchema<ColT>::column_oid_for(const column_name_t& name) const {
  return column_oids_.at(name);
}

template<class ColT>
size_t BaseSchema<ColT>::offset_for(column_oid_t oid) const {
  return offsets_.at(oid);
}

template<class ColT>
size_t BaseSchema<ColT>::offset_for(const column_name_t& name) const {
  return offset_for(column_oid_for(name));
}

template<class ColT>
size_t BaseSchema<ColT>::index_for(const column_name_t& name) const {
  return column_oid_for(name);
}

template<class ColT>
size_t BaseSchema<ColT>::column_count() const {
  return columns_.size();
}

template<class ColT>
size_t BaseSchema<ColT>::tuple_length() const {
  return tuple_length_;
}

template<class ColT>
const vector<column_oid_t>& BaseSchema<ColT>::unlined_columns() const {
  return unlined_columns_;
}

template<class ColT>
const ColT& BaseSchema<ColT>::by_name(const column_name_t& name) const {
  return columns_.at(column_oid_for(name));
}

template<class ColT>
const ColT& BaseSchema<ColT>::by_column_oid(column_oid_t oid) const {
  return columns_.at(oid);
}

template<class ColT>
const ColT& BaseSchema<ColT>::by_offset(offset_t offset) const {
  return columns_.at(offset);
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
