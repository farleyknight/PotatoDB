#include "server/system_catalog.hpp"

const string SystemCatalog::create_table_sql =
  "CREATE TABLE IF NOT EXISTS system_catalog ( "    \

  "id         INTEGER PRIMARY KEY AUTOINCREMENT, "  \
  "type       INTEGER NOT NULL, "                   \
  "name       VARCHAR(32) NOT NULL, "               \
  "table_name VARCHAR(32) NOT NULL "                \

  ");";
