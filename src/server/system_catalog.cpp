#include "server/system_catalog.hpp"


// TODO: We're no longer putting the SystemCatalog into a .tbl on it's own
// Instead, the schema for each table lives in the .tbl itself, as block_id=0
// This choice serves two purposes:
// 1) SystemCatalog as an in-memory data structure, not as rows in a .tbl
// 2) It's easier to "query" an in-memory data structure versus going to disk every time.
// 3) Makes querying against SystemCatalog 10x faster.

void SystemCatalog::create_table(const table_name_t& table_name,
                                 ColumnDefListExpr columns,
                                 Txn& txn);
{
  auto table_oid          = next_table_oid_++;
  table_oids_[table_name] = table_oid;
  table_names_[table_oid] = table_name;

  vector<TableColumn> cols;

  for (column_index_t i = 0; i < columns.list().size(); ++i) {
    // TODO: Make col
    auto column_oid     = result_set->value_at<int32_t>("id", i);
    auto data_type      = result_set->value_at<int32_t>("data_type", i);

    auto size           = result_set->value_at<int32_t>("data_size", i);
    auto column_name    = result_set->value_at<string>("object_name", i);
    auto is_primary_key = result_set->value_at<bool>("primary_key", i);

    auto type_id = static_cast<TypeId>(data_type);
    if (type_id == TypeId::VARCHAR) {
      cols.push_back(TableColumn(column_name, table_oid, column_oid, type_id, size));
    } else {
      cols.push_back(TableColumn(column_name, table_oid, column_oid, type_id));
    }
  }

  auto table_schema = TableSchema(cols, table_name, table_oid);

  table_schemas_.insert(make_pair(table_oid, table_schema));

  load_table(table_oid, table_name, table_schema);
}

TableSchema SystemCatalog::make_schema_from(const table_name_t& table_name,
                                            table_oid_t table_oid,
                                            const ColumnDefListExpr& column_list) const
{
  vector<TableColumn> columns;
  for (size_t col_index = 0; col_index < column_list.list().size(); ++col_index) {
    const auto &column = column_list.list()[col_index];
    auto type_id = column.type_id();
    if (type_id == TypeId::VARCHAR) {
      columns.push_back(TableColumn(column.name(),
                                    table_oid,
                                    col_index,
                                    type_id,
                                    column.type_length()));
    } else {
      columns.push_back(TableColumn(column.name(),
                                    table_oid,
                                    col_index,
                                    type_id));
    }
  }

  return TableSchema(columns, table_name, table_oid);
}

// TODO: We should be attempting to get an
// exclusive lock on the table, and abort the txn
// if we cannot get it.
table_oid_t SystemCatalog::create_table(const CreateTableExpr& expr, Txn& txn)
{
  assert(table_oids_.count(table_name) == 0);

  table_oid_t table_oid = next_table_oid_++;
  auto schema = make_schema_from(table_name,
                                 table_oid,
                                 primary_key,
                                 column_list);

  load_table(table_oid, table_name, schema);
  return table_oid;
}

void SystemCatalog::load_table(table_oid_t table_oid,
                               const table_name_t& table_name,
                               const TableSchema& schema)
{
  table_schemas_.insert(make_pair(table_oid, schema));

  // TODO: This should be sent to a logger.
  // std::cout << "New table created: " << table_name << std::endl;

  index_oids_.emplace(table_name,
                      map<index_name_t, index_oid_t>());
}

index_oid_t SystemCatalog::create_index(const CreateIndexExpr& expr, UNUSED Txn& txn)
{
  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(table_name) == 1);
  assert(index_oids_[table_name].count(index_name) == 0);

  index_oid_t index_oid = next_index_oid_++;
  index_oids_[table_name][index_name] = index_oid;

  return index_oid;
}
