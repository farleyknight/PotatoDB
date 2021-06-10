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
  static int32_t system_catalog_table_oid() {
    return 1;
  }

  static const string create_table_sql() {
    return "CREATE TABLE IF NOT EXISTS system_catalog ( "     \
      "id          INTEGER PRIMARY KEY AUTOINCREMENT, "  \
      "object_type INTEGER NOT NULL, "                   \
      "data_type   INTEGER, "                            \
      "data_size   INTEGER, "                            \
      "primary_key BOOLEAN NOT NULL, "                   \
      "object_name VARCHAR(32) NOT NULL, "               \
      "table_name  VARCHAR(32) NOT NULL "                \
      ");";
  }

  static TableColumn id_column() {
    auto col = TableColumn("id",
                           system_catalog_table_oid(),
                           1,
                           TypeId::INTEGER);
    col.set_primary_key(true);
    col.set_autoincrement(true);
    return col;
  }

  static TableColumn object_type_column() {
    auto col = TableColumn("object_type",
                           system_catalog_table_oid(),
                           2,
                           TypeId::INTEGER);
    col.set_nullable(false);
    return col;
  }

  static TableColumn data_type_column() {
    auto col = TableColumn("data_type",
                           system_catalog_table_oid(),
                           3,
                           TypeId::INTEGER);
    // NOTE: Can be null when the object_type != COLUMN
    col.set_nullable(true);
    return col;
  }

  // TODO: This will be NULL for some columns.
  // Need to fully implement NULL across the project.
  static TableColumn data_size_column() {
    auto col = TableColumn("data_size",
                           system_catalog_table_oid(),
                           4,
                           TypeId::INTEGER);
    col.set_nullable(false);
    return col;
  }

  static TableColumn primary_key_column() {
    auto col = TableColumn("primary_key",
                           system_catalog_table_oid(),
                           5,
                           TypeId::BOOLEAN);
    col.set_nullable(false);
    return col;
  }

  static TableColumn object_name_column() {
    auto col = TableColumn("object_name",
                           system_catalog_table_oid(),
                           6,
                           TypeId::VARCHAR,
                           32);
    col.set_nullable(false);
    return col;
  }

  static TableColumn table_name_column() {
    auto col = TableColumn("table_name",
                           system_catalog_table_oid(),
                           7,
                           TypeId::VARCHAR,
                           32);
    col.set_nullable(false);
    return col;
  }

  static TableSchema schema() {
    vector<TableColumn> cols;

    cols.push_back(id_column());
    cols.push_back(object_type_column());
    cols.push_back(data_type_column());
    cols.push_back(data_size_column());
    cols.push_back(primary_key_column());
    cols.push_back(object_name_column());
    cols.push_back(table_name_column());

    return TableSchema(cols, "system_catalog", "id", system_catalog_table_oid());
  }

  static void create(PotatoDB& db) {
    db.run(create_table_sql);

    db.run(insert_column_sql_for(id_column()));
    db.run(insert_column_sql_for(object_type_column()));
    db.run(insert_column_sql_for(data_type_column()));
    db.run(insert_column_sql_for(data_size_column()));
    db.run(insert_column_sql_for(primary_key_column()));
    db.run(insert_column_sql_for(object_name_column()));
    db.run(insert_column_sql_for(table_name_column()));
  }

  static void load(PotatoDB& db) {
    db.catalog().load_table("system_catalog", schema());

    // SELECT table_name FROM system_catalog WHERE type == table
    auto tables = run(load_tables_sql());

    for (const auto& tuple : tables.set()) {
      auto table_name = tuple->value(schema(), 0).as<string>();
      auto result = db.run(load_table_sql_for(table_name));
      db.catalog().load_from_query(table_name, result);
    }
  }

  static const string load_table_sql_for(const table_name_t table_name) {
    return "SELECT * FROM system_catalog WHERE " \
      "object_type = 2 AND table_name = '" + table_name + "'";
  }

  static const string insert_column_sql_for(const table_name_t table_name,
                                            const TableColumn& column)
  {
    auto data_type   = std::to_string(static_cast<int32_t>(column.type_id()));

    auto column_size = column.variable_length();
    auto data_size   = (column_size == 0) ? "NULL" : std::to_string(column_size);

    auto primary_key = column.primary_key() ? "true" : "false";
    auto column_name = column.name();

    return "INSERT INTO system_catalog "                                          \
      "(object_type, data_type, data_size, primary_key, object_name, table_name)" \
      " VALUES "                                                                  \

      "("                                                                         \
      // Object Type: 2 == COLUMN
      "2,"                                                                        \
      // Data Type: Type ID of column
      "" + data_type + ","                                                        \
      // Data Size: VARCHAR size or NULL
      "" + data_size + ","                                                        \
      // Primary key: boolean
      "" + primary_key + ","                                                      \
      // Object name: Name of the column, table, or index
      "'" + column_name + "',"                                                    \
      // Table name: The table this object belongs to
      "'" + table_name + "'"                                                      \
      ")";
  }

  static const string insert_table_sql_for(const table_name_t table_name)
  {
    return "INSERT INTO system_catalog "                                          \
      "(object_type, data_type, data_size, primary_key, object_name, table_name)" \
      " VALUES "                                                                  \

      "("                                                                         \
      // Object Type: 1 == TABLE
      "2,"                                                                        \
      // Data Type: Tables do not have type IDs
      "NULL,"                                                                     \
      // Data Size: Tables do not have data size
      "NULL,"                                                                     \
      // Primary key: Not valid for tables
      "false,"                                                                    \
      // Object name: Same as table name
      "'" + table_name + "',"                                                     \
      // Table name
      "'" + table_name + "'"                                                      \
      ")";
  }
};
