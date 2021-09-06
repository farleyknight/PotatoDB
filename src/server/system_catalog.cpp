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
  assert(!column_oids_.contains(full_name));

  column_oid_t column_oid = next_column_oid_;
  next_column_oid_++;
  column_oids_.insert(make_pair(full_name, column_oid));

  return column_oid;
}

IndexSchema
SystemCatalog::make_schema_from(index_oid_t index_oid,
                                const CreateIndexExpr& expr) const
{
  auto index_name   = expr.index().name();
  auto table_name   = expr.table().name();
  auto table_oid    = table_oid_for(table_name);

  auto column_names = expr.indexed_columns().list();
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

  auto root_page_id = default_root_page_id(table_oid);

  return IndexSchema(columns,
                     index_oid,   table_oid,
                     index_name,  table_name,
                     column_oids, key_size,
                     root_page_id);
}

TableSchema
SystemCatalog::make_schema_from(table_oid_t table_oid,
                                const CreateTableExpr& expr)
{
  auto table_name  = expr.table().name();
  auto column_list = expr.column_defs();

  vector<TableColumn> columns;
  for (const auto &col_expr : column_list.list()) {
    auto oid = make_column_oid(table_name, col_expr.name());

    assert(!columns_.contains(oid));
    auto col = make_column_from(table_oid, oid, col_expr);
    columns_[oid] = col;

    columns.push_back(col);
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
SystemCatalog::create_index_schema(const CreateIndexExpr& expr)
{
  auto table_name = expr.table().name();
  auto index_name = expr.index().name();

  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(index_name) == 0);

  auto index_oid = next_index_oid_++;
  auto schema    = make_schema_from(index_oid, expr);
  load_index(index_oid, schema);

  return index_oid;
}

table_oid_t
SystemCatalog::create_table_schema(const CreateTableExpr& expr)
{
  auto table_name = expr.table().name();
  assert(!table_oids_.contains(table_name));

  auto table_oid = next_table_oid_++;


  assert(!table_schemas_.contains(table_oid));
  auto schema = make_schema_from(table_oid, expr);

  table_oids_[table_name] = table_oid;
  table_schemas_.emplace(table_oid, schema);
  assert(table_schemas_.contains(table_oid));

  return table_oid;
}

void
SystemCatalog::load_table(table_oid_t table_oid, const TableSchema& schema) {
  table_schemas_.insert(make_pair(table_oid, schema));
}
