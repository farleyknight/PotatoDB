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

  static const string create_table_sql_for(UNUSED const table_name_t table_name) {
    return "INSERT INTO system_catalog (type, name, table_name) VALUES" \
      "("                                                               \
      "1,"                                                              \
      "'" + table_name + "',"                                           \
      "'" + table_name + "'"                                           \
      ")";
  }

  static const string create_column_sql_for(UNUSED const table_name_t table_name,
                                            UNUSED const column_name_t column_name) {
    return "INSERT INTO system_catalog (type, name, table_name) VALUES" \
      "("                                                               \
      "2,"                                                              \
      "'" + column_name + "',"                                          \
      "'" + table_name + "'"                                           \
      ")";
  }
};
