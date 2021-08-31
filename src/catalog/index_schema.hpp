#pragma once

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

class IndexSchema : public BaseSchema<TableColumn> {
public:
  IndexSchema(
              index_name_t index_name,
              table_name_t table_name,
              index_oid_t index_oid,
              table_oid_t table_oid,
              // NOTE: This is the mapping relation between
              // key schema and tuple schema
              vector<column_oid_t> key_attrs,
              int32_t key_size);

  const index_name_t index_name() const;
  const table_name_t table_name() const;

  const vector<column_oid_t>& key_attrs() const;
  const string to_string() const;

private:
  const index_name_t index_name_;
  const table_name_t table_name_;
  index_oid_t index_oid_;
  table_oid_t table_oid_;
  vector<column_oid_t> key_attrs_;
};
