#pragma once

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

class IndexSchema {
public:
  IndexSchema(index_oid_t index_oid,
              table_oid_t table_oid,
              index_name_t index_name,
              // NOTE: This is the mapping relation between
              // key schema and tuple schema
              // TODO: Provide an example here.
              //
              // The command:
              //
              //   CREATE INDEX ???
              //
              // Means to map .. to ..
              vector<column_oid_t> column_oids,
              int32_t key_size,
              PageId root_page_id)
    : index_oid_    (index_oid),
      table_oid_    (table_oid),
      index_name_   (index_name),
      column_oids_  (column_oids),
      key_size_     (key_size),
      root_page_id_ (root_page_id)
  {}

  index_oid_t index_oid() const {
    return index_oid_;
  }

  table_oid_t table_oid() const {
    return table_oid_;
  }

  const index_name_t index_name() const {
    return index_name_;
  }


  const vector<column_oid_t>& column_oids() const {
    return column_oids_;
  }

  const string to_string() const {
    return "TODO";
  }

  // TODO: This should be update-able, and should trigger a write to the
  // header page of the file.
  const PageId root_page_id() const {
    return root_page_id_;
  }

  int32_t key_size() const {
    return key_size_;
  }

private:
  // NOTE: We should NOT store `TableColumn`s in this object, because that creates
  // a dependency on the TableSchema. Instead, let's keep this class separate,
  // and only hold `column_oid_t`s
  index_oid_t index_oid_;
  table_oid_t table_oid_;

  const index_name_t index_name_;

  vector<column_oid_t> column_oids_;
  const int32_t key_size_;

  PageId root_page_id_;
};
