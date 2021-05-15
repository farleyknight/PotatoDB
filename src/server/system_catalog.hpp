#pragma once

#include "common/config.hpp"
#include "catalog/table_schema.hpp"

enum class SystemCatalogTypes {
  INVALID = 0,
  TABLE   = 1,
  COLUMN  = 2,
  INDEX   = 3
};

class SystemCatalog {
public:
  static const string create_table_sql;
  static const string insert_sql;

  static const string sql_for(const TableSchema& schema) {
    // TODO: Given a table name, and it's schema, write a function that
    // will generate the SQL for the system catalog.
    // 1) One statement for the table itself
    // 2) One statement for each column in the schema;

    return "";
  }
};
