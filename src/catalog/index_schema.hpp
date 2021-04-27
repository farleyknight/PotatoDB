#pragma once

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

class IndexSchema : BaseSchema<TableColumn> {
public:
  IndexSchema(Vec<TableColumn> columns,
              String index_name,
              String table_name,
              index_oid_t index_oid,
              table_oid_t table_oid,
              // The mapping relation between key schema and tuple schema
              Vec<column_oid_t> key_attrs,
              size_t key_size);

  Ref<String>            index_name() const;
  Ref<String>            table_name() const;

  Ref<Vec<column_oid_t>> key_attrs() const;
  String                 to_string() const;

private:
  String index_name_;
  String table_name_;
  index_oid_t index_oid_;
  table_oid_t table_oid_;
  Vec<column_oid_t> key_attrs_;

};
