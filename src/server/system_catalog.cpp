#include "server/system_catalog.hpp"

const string SystemCatalog::create_table_sql =
  "CREATE TABLE system_catalog ( "              \

  "id         INTEGER PRIMARY KEY, "            \
  "type       INTEGER NOT NULL, "               \
  "name       VARCHAR(32) NOT NULL, "           \
  "table_name VARCHAR(32) NOT NULL "            \

  ");";
