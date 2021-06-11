#pragma once

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "exprs/column_def_expr.hpp"
#include "server/potatodb.hpp"

class SystemCatalog {
public:
  enum class ObjectTypes {
    INVALID = 0,
    TABLE   = 1,
    COLUMN  = 2,
    INDEX   = 3
  };

  static int32_t system_catalog_table_oid() {
    return 1;
  }

  static const string table_type() {
    return std::to_string(static_cast<int32_t>(ObjectTypes::TABLE));
  }

  static const string column_type() {
    return std::to_string(static_cast<int32_t>(ObjectTypes::COLUMN));
  }

  static const string create_table_sql() {
    return "CREATE TABLE IF NOT EXISTS system_catalog ( "     \
      "id          INTEGER PRIMARY KEY AUTOINCREMENT, "  \
      "object_type INTEGER NOT NULL, "                   \
      // TODO: Allow this to be NULL
      // "data_type   INTEGER, "
      "data_type   INTEGER NOT NULL, "                   \
      // TODO: Allow this to be NULL
      // "data_size   INTEGER, "
      "data_size   INTEGER NOT NULL, "                   \
      "primary_key BOOLEAN NOT NULL, "                   \
      "object_name VARCHAR(32) NOT NULL, "               \
      "table_name  VARCHAR(32) NOT NULL "                \
      ");";
  }

  static const string load_tables_sql() {
    return "SELECT id, table_name FROM system_catalog WHERE object_type = 1";
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
    // TODO: Allow this to be NULL
    col.set_nullable(false);
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
    db.run(create_table_sql());
  }

  static void load(PotatoDB& db) {
    db.catalog().load_table(system_catalog_table_oid(), "system_catalog", schema());

    assert(db.catalog().has_table_named("system_catalog"));

    auto all_tables_sql = load_tables_sql();
    std::cout << "SQL for LOADING ALL TABLES " << std::endl;
    std::cout << all_tables_sql << std::endl;

    auto tables      = db.run(all_tables_sql);
    auto &result_set = tables.set();

    assert(result_set);
    assert(result_set->size() > 0);

    auto &txn = db.txn_mgr().begin();

    for (size_t i = 0; i < result_set->size(); ++i) {
      auto table_oid  = result_set->value_at<int32_t>("id", i);
      auto table_name = result_set->value_at<string>("table_name", i);
      std::cout << "Found table_name " << table_name << std::endl;
      if (table_name == "system_catalog") {
        continue;
      }
      auto table_sql = load_table_sql_for(table_name);
      std::cout << "SQL for LOADING TABLE " << std::endl;
      std::cout << table_sql << std::endl;
      auto result = db.run(table_sql);
      db.catalog().load_from_query(table_oid, table_name, result);
      db.table_mgr().load_table(table_name, table_oid, txn);
    }

    db.txn_mgr().commit(txn);
  }

  static const string load_table_sql_for(const table_name_t table_name) {
    return "SELECT * FROM system_catalog WHERE " \
      "object_type = 2 AND table_name = '" + table_name + "'";
  }

  static const string insert_column_sql_for(const table_name_t table_name,
                                            const ColumnDefExpr& column)
  {
    auto data_type   = std::to_string(static_cast<int32_t>(column.type_id()));
    auto column_size = column.type_length();
    // TODO: Allow this to be NULL
    // auto data_size   = (column_size == 0) ? "NULL" : std::to_string(column_size);
    auto data_size   = std::to_string(column_size);

    auto primary_key = column.is_primary_key() ? "true" : "false";
    auto column_name = column.name();

    return make_insert_column_sql(data_type, data_size, primary_key, column_name, table_name);
  }

  static const string insert_column_sql_for(const table_name_t table_name,
                                            const TableColumn& column)
  {
    auto data_type   = std::to_string(static_cast<int32_t>(column.type_id()));

    auto column_size = column.variable_length();
    // TODO: Allow this to be NULL
    // auto data_size   = (column_size == 0) ? "NULL" : std::to_string(column_size);
    auto data_size   = std::to_string(column_size);

    auto primary_key = column.primary_key() ? "true" : "false";
    auto column_name = column.name();

    return make_insert_column_sql(data_type, data_size, primary_key, column_name, table_name);
  }

  static const string make_insert_column_sql(const string& data_type,
                                             const string& data_size,
                                             const string& primary_key,
                                             const string& column_name,
                                             const string& table_name)
  {
    auto object_type = SystemCatalog::column_type();

    return "INSERT INTO system_catalog "                                          \
      "(object_type, data_type, data_size, primary_key, object_name, table_name)" \
      " VALUES "                                                                  \
      "("                                                                         \
      // Object Type: 2 == COLUMN
      "" + object_type + ","                                                      \
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
    auto object_type = SystemCatalog::table_type();

    return "INSERT INTO system_catalog "                                          \
      "(object_type, data_type, data_size, primary_key, object_name, table_name)" \
      " VALUES "                                                                  \

      "("                                                                         \
      // Object Type: 1 == TABLE
      "" + object_type + ","                                                      \
      // Data Type: Tables do not have type IDs
      // TODO: Allow this to be NULL
      "0,"                                                                        \
      // Data Size: Tables do not have data size
      // TODO: Allow this to be NULL
      "0,"                                                                        \
      // Primary key: Not valid for tables
      "false,"                                                                    \
      // Object name: Same as table name
      "'" + table_name + "',"                                                     \
      // Table name
      "'" + table_name + "'"                                                      \
      ")";
  }
};
