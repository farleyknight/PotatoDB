
#include "catalog/base_schema.hpp"

template<class ColT>
BaseSchema<ColT>::BaseSchema(Vec<ColT> cols) {
  size_t offset = 0;
  for (size_t oid = 0; oid < cols.size(); ++oid) {
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
bool BaseSchema<ColT>::has_column(Ref<String> name) const {
  return column_oids_.find(name) > 0;
}

template<class ColT>
column_oid_t BaseSchema<ColT>::column_oid_for(Ref<String> name) const {
  return column_oids_[name];
}

template<class ColT>
size_t BaseSchema<ColT>::offset_for(column_oid_t oid) const {
  return offsets_[oid];
}

template<class ColT>
size_t BaseSchema<ColT>::offset_for(Ref<String> name) const {
  return offset_for(column_oid_for(name));
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
Ref<Vec<size_t>> BaseSchema<ColT>::unlined_columns() const {
  return unlined_columns_;
}

template<class ColT>
Ref<ColT> BaseSchema<ColT>::by_name(Ref<String> name) const {
  return columns_.at(column_oid_for(name));
}

template<class ColT>
Ref<ColT> BaseSchema<ColT>::by_column_oid(const column_oid_t oid) const {
  return columns_.at(oid);
}

template<class ColT>
Ref<Vec<ColT>> BaseSchema<ColT>::all() const {
  return columns_;
}
