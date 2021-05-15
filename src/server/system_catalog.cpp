#include "server/system_catalog.hpp"

const string SystemCatalog::create_table_sql =
  "CREATE TABLE system_catalog ( "              \

  "id         INTEGER PRIMARY KEY, "            \
  "type       INTEGER NOT NULL, "               \
  "name       VARCHAR(32) NOT NULL, "           \
  "table_name VARCHAR(32) NOT NULL "            \

  ");";

const string SystemCatalog::insert_sql =
  "INSERT INTO system_catalog VALUES"           \
  "("                                           \

  "1,"                                          \
  "1,"                                          \
  "'system_catalog',"                           \
  "'system_catalog'"                            \

  ");";
