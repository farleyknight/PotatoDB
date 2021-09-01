#include "server/system_catalog.hpp"

// TODO:
//
// We should add methods for each type of "query"
//
// DESCRIBE TABLE table_name
// SHOW TABLES
//
// What is the equivalent for indexes?

TableColumn
SystemCatalog::make_column_from(table_oid_t table_oid,
                                column_oid_t column_oid,
                                const ColumnDefExpr& expr) const
{
  auto name    = expr.name();
  auto type_id = expr.type_id();
  if (type_id == TypeId::VARCHAR) {
    return TableColumn(name,
                       table_oid,
                       column_oid,
                       type_id,
                       expr.type_length());
  } else {
    return TableColumn(name,
                       table_oid,
                       column_oid,
                       type_id);
  }
}

column_oid_t
SystemCatalog::make_column_oid(const table_name_t& table_name,
                               const column_name_t& column_name)
{
  auto full_name   = table_name + "." + column_name;
  assert(column_oids_.count(full_name) == 0);

  column_oid_t column_oid = next_column_oid_;
  next_column_oid_++;
  column_oids_.insert(make_pair(full_name, column_oid));

  return column_oid;
}

IndexSchema
SystemCatalog::make_schema_from(index_oid_t index_oid,
                                const CreateIndexExpr& expr) const
{
  auto index_name   = expr.index_name();
  auto table_name   = expr.table().name();
  auto table_oid    = table_oid_for(table_name);

  auto column_names = expr.column_names();
  auto table_schema = table_schema_for(table_name);

  vector<column_oid_t> column_oids;
  vector<TableColumn> columns;
  for (const auto &name : column_names) {
    auto column_oid = table_schema.column_oid_for(name);
    column_oids.push_back(column_oid);

    auto column = table_schema.by_name(name);
    columns.push_back(column);
  }

  int32_t key_size = 8; // NOTE: Fixed for now.
                        // Update to be configurable later

  return IndexSchema(columns,
                     index_name,  table_name,
                     index_oid,   table_oid,
                     column_oids, key_size);
}

TableSchema
SystemCatalog::make_schema_from(table_oid_t table_oid,
                                const CreateTableExpr& expr)
{
  auto table_name  = expr.table().name();
  auto column_list = expr.column_defs();

  vector<TableColumn> columns;
  for (const auto &col : column_list.list()) {
    auto column_oid = make_column_oid(table_name, col.name());
    columns.push_back(make_column_from(table_oid, column_oid, col));
  }

  return TableSchema(columns, table_name, table_oid);
}

void
SystemCatalog::load_index(index_oid_t index_oid,
                          const IndexSchema& schema)
{
  index_schemas_.insert(make_pair(index_oid, schema));
}

index_oid_t
SystemCatalog::create_index(const CreateIndexExpr& expr)
{
  auto table_name = expr.table().name();
  auto index_name = expr.index_name();

  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(index_name) == 0);

  auto index_oid = next_index_oid_++;
  auto schema    = make_schema_from(index_oid, expr);
  load_index(index_oid, schema);

  return index_oid;
}

table_oid_t
SystemCatalog::create_table(const CreateTableExpr& expr)
{
  auto table_name  = expr.table().name();
  assert(!table_oids_.contains(table_name));

  auto table_oid = next_table_oid_++;
  table_oids_.insert(make_pair(table_name, table_oid));

  auto schema = make_schema_from(table_oid, expr);
  table_schemas_.insert(make_pair(table_oid, schema));

  return table_oid;
}

void
SystemCatalog::load_table(table_oid_t table_oid, const TableSchema& schema) {
  table_schemas_.insert(make_pair(table_oid, schema));
}
