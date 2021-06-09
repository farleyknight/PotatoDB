#pragma once

#include "common/config.hpp"
#include "catalog/table_schema.hpp"
#include "server/potatodb.hpp"

enum class SystemCatalogObjectTypes {
  INVALID = 0,
  TABLE   = 1,
  COLUMN  = 2,
  INDEX   = 3
};

class SystemCatalog {
public:

  static TableColumn id_column() {
    auto col = TableColumn("id",
                           INVALID_TABLE_OID,
                           INVALID_COLUMN_OID,
                           TypeId::INTEGER);
    id_column.set_primary_key(true);
    return col;
  }

  static void create(PotatoDB& db) {
    db.run(create_table_sql);

    // Primary key of the object
    db.run(insert_column_sql_for("system_catalog",
                                 "id", TypeId::INTEGER));

    // One of the SystemCatalogObjectTypes
    db.run(insert_column_sql_for("system_catalog",
                                 "object_type", TypeId::INTEGER));

    // Data types, such as TypeId::INTEGER or TypeId::VARCHAR
    db.run(insert_column_sql_for("system_catalog",
                                 "data_type", TypeId::INTEGER));

    // Data size is currently only used for VARCHAR
    db.run(insert_column_sql_for("system_catalog",
                                 "data_size", TypeId::INTEGER));

    // Flag that tells us if it's a primary key
    db.run(insert_column_sql_for("system_catalog",
                                 "primary_key", TypeId::BOOLEAN));

    // Object name
    db.run(insert_column_sql_for("system_catalog",
                                 "object_name", TypeId::VARCHAR, 32));

    // Table name
    db.run(insert_column_sql_for("system_catalog",
                                 "table_name", TypeId::VARCHAR, 32));
  }

  static void load(PotatoDB& db) {
    db.catalog().load_table("system_catalog", schema());

    // SELECT * FROM system_catalog WHERE type == table
    auto tables = run(load_tables_sql);

    for (const auto& table_name : tables) {
      // SELECT * FROM system_catalog WHERE type == column AND table = table_name
      auto result = db.run(load_table_sql_for(table_name));
      db.catalog().load_from_query(table_name, result);
    }
  }

  static const string load_table_sql_for(const table_name_t table_name) {
    return "SELECT * FROM "
  }

  static TableSchema schema() {
    vector<TableColumn> cols;

    // TODO: Figure out what the column OIDs and table OIDs should be!
    //
    // NOTE: The column OIDs and table OIDs will be something that
    // the `Catalog` keeps track of. In other words, each of these
    // object connstructions should be done in `Catalog`, not here.
    //
    // An example might be:
    // > catalog().next_table_oid()
    //
    // Or
    // > catalog().next_column_oid()
    //
    // We might even want to give `Catalog` the same params as we do
    // the constructor.

    auto id_column = TableColumn("id",
                                 INVALID_TABLE_OID,
                                 INVALID_COLUMN_OID,
                                 TypeId::INTEGER);
    id_column.set_primary_key(true);
    cols.push_back(id_column);

    auto type_column = TableColumn("data_type",
                                   INVALID_TABLE_OID,
                                   INVALID_COLUMN_OID,
                                   TypeId::INTEGER);
    cols.push_back(type_column);

    auto name_column = TableColumn("object_name",
                                   INVALID_TABLE_OID,
                                   INVALID_COLUMN_OID,
                                   TypeId::VARCHAR,
                                   32);
    cols.push_back(name_column);

    auto table_name_column = TableColumn("table_name",
                                         INVALID_TABLE_OID,
                                         INVALID_COLUMN_OID,
                                         TypeId::VARCHAR,
                                         32);
    cols.push_back(table_name_column);

    return TableSchema(cols, "system_catalog", "id", INVALID_TABLE_OID);
  }

  static const string create_table_sql() {
    return "CREATE TABLE IF NOT EXISTS system_catalog ( "    \
           "id          INTEGER PRIMARY KEY AUTOINCREMENT, "  \
           "object_type INTEGER NOT NULL, "                   \
           "name        VARCHAR(32) NOT NULL, "               \
           "table_name  VARCHAR(32) NOT NULL "                \
           ");";
  }

  static const string insert_table_sql_for(UNUSED const table_name_t table_name) {
    return "INSERT INTO system_catalog (object_type, name, table_name)" \
      " VALUES "                                                        \
      "("                                                               \
      "1,"                                                              \
      "'" + table_name + "',"                                           \
      "'" + table_name + "'"                                            \
      ")";
  }

  static const string insert_column_sql_for(const table_name_t table_name,
                                            const column_name_t column_name)
  {
    return "INSERT INTO system_catalog (object_type, name, table_name) " \
      " VALUES "                                                         \
      "("                                                                \
      "2,"                                                               \
      "'" + column_name + "',"                                           \
      "'" + table_name + "'"                                             \
      ")";
  }
};
