#pragma once

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

class IndexSchema : public BaseSchema<TableColumn> {
public:
  IndexSchema(vector<TableColumn> columns,
              index_name_t index_name,
              table_name_t table_name,
              index_oid_t index_oid,
              table_oid_t table_oid,
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
              int32_t key_size)
    : BaseSchema   (columns),
      index_name_  (index_name),
      table_name_  (table_name),
      index_oid_   (index_oid),
      table_oid_   (table_oid),
      column_oids_ (column_oids),
      key_size_    (key_size)
  {}

  const index_name_t index_name() const;
  const table_name_t table_name() const;

  const vector<column_oid_t>& column_oids() const;
  const string to_string() const;

private:
  const index_name_t index_name_;
  const table_name_t table_name_;
  index_oid_t index_oid_;
  table_oid_t table_oid_;
  vector<column_oid_t> column_oids_;
  const int32_t key_size_;
};
