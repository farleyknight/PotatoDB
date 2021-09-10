#include "catalog/catalog.hpp"


QuerySchema
Catalog::query_schema_for(table_oid_t table_oid) const
{
  return QuerySchema(all_columns_for(table_oid));
}

QuerySchema
Catalog::query_schema_for(const table_name_t& table_name) const
{
  return QuerySchema(all_columns_for(table_name));
}

QuerySchema
Catalog::query_schema_for(const vector<table_name_t>& table_names,
                          const ColumnListExpr& column_list) const
{
  vector<QueryColumn> columns;
  for (const auto &column : column_list.list()) {
    if (column.is_all_columns_splat()) {
      return QuerySchema(all_columns_for(table_names));
    } else if (column.is_table_splat()) {
      for (const auto &query_col : all_columns_for(column.table())) {
        columns.push_back(query_col);
      }
    } else if (column.table() != "") {
      auto query_column = query_column_for(column.table(), column.name());
      columns.push_back(query_column);
    } else {
      auto query_column = query_column_for(table_names, column.name());
      columns.push_back(query_column);
    }
  }

  return QuerySchema(columns);
}

vector<QueryColumn>
Catalog::all_columns_for(const vector<table_name_t>& table_names) const {
  vector<QueryColumn> columns;
  for (const auto &table_name : table_names) {
    for (const auto &col : all_columns_for(table_name)) {
      columns.push_back(col);
    }
  }
  return columns;
}

vector<QueryColumn>
Catalog::all_columns_for(const table_name_t& table_name) const {
  auto table_oid = sys_catalog_.table_oid_for(table_name);
  return all_columns_for(table_oid);
}

vector<QueryColumn>
Catalog::all_columns_for(table_oid_t table_oid) const {
  auto table_schema = sys_catalog_.table_schema_for(table_oid);
  vector<QueryColumn> cols;
  for (const auto &col : table_schema.columns()) {
    cols.push_back(QueryColumn::from(col));
  }
  return cols;
}

QuerySchema
Catalog::show_tables_schema() const
{
  vector<QueryColumn> cols;
  cols.push_back(QueryColumn(TypeId::VARCHAR, "table_name"));
  return QuerySchema(cols);
}

QuerySchema
Catalog::describe_table_schema() const
{
  vector<QueryColumn> cols;

  cols.push_back(QueryColumn(TypeId::VARCHAR, "field_name"));
  // NOTE Can be "varchar(16)" or "date"
  cols.push_back(QueryColumn(TypeId::VARCHAR, "type"));
  // NOTE: Should be "YES" or "NO"
  cols.push_back(QueryColumn(TypeId::VARCHAR, "nullable"));
  cols.push_back(QueryColumn(TypeId::VARCHAR, "key"));
  // NOTE: Can be "NULL"
  cols.push_back(QueryColumn(TypeId::VARCHAR, "default"));
  // NOTE: Should include info about "AUTOINCREMENT"
  cols.push_back(QueryColumn(TypeId::VARCHAR, "extra"));

  return QuerySchema(cols);
}

QuerySchema
Catalog::query_schema_for(const table_name_t& table_name,
                          const ColumnListExpr& column_list) const
{
  if (column_list.list().size() == 0) {
    return QuerySchema(all_columns_for(table_name));
  }

  vector<QueryColumn> cols;
  for (const auto& col : column_list.list()) {
    if (col.name() == "*") {
      for (const auto& query_col : all_columns_for(table_name)) {
        cols.push_back(query_col);
      }
    } else {
      cols.push_back(query_column_for(table_name, col.name()));
    }
  }

  assert(cols.size() > 0);
  return QuerySchema(cols);
}

QueryColumn
Catalog::query_column_for(const table_name_t& table_name,
                          const column_name_t& column_name) const
{
  const auto &schema = sys_catalog_.table_schema_for(table_name);
  const auto &col    = schema.by_name(column_name);
  return QueryColumn::from(col);
}


QueryColumn
Catalog::query_column_for(const vector<table_name_t>& table_names,
                          const column_name_t& column_name) const
{
  vector<QueryColumn> candidates;
  for (const auto &table_name : table_names) {
    if (table_has_column_named(table_name, column_name)) {
      auto query_column = query_column_for(table_name, column_name);
      candidates.push_back(query_column);
    }
  }

  if (candidates.size() == 0) {
    auto message = "No column named " + column_name + " in the tables given in the query";
    throw NoColumnsNamedException(message);
  } else if (candidates.size() > 1) {
    // TODO: Give a better error message that shows the list of all tables that have
    // a matching column name.
    auto message = "More than one table has a column named " + column_name;
    throw MoreThanOneColumnException(message);
  } else {
    return candidates[0];
  }
}

