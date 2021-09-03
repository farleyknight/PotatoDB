#pragma once

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

class IndexSchema : public BaseSchema<TableColumn> {
public:
  IndexSchema(vector<TableColumn> columns,
              index_oid_t index_oid,
              table_oid_t table_oid,
              index_name_t index_name,
              table_name_t table_name,
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
    : BaseSchema    (columns),
      index_oid_    (index_oid),
      table_oid_    (table_oid),
      index_name_   (index_name),
      table_name_   (table_name),
      column_oids_  (column_oids),
      key_size_     (key_size),
      root_page_id_ (root_page_id)
  {}

  index_oid_t index_oid() const;
  table_oid_t table_oid() const;

  const index_name_t index_name() const;
  const table_name_t table_name() const;

  const vector<column_oid_t>& column_oids() const;
  const string to_string() const;

  const PageId root_page_id() const;

private:
  index_oid_t index_oid_;
  table_oid_t table_oid_;

  const index_name_t index_name_;
  const table_name_t table_name_;

  vector<column_oid_t> column_oids_;
  const int32_t key_size_;

  PageId root_page_id_;
};
