#include "catalog/catalog.hpp"

Catalog::Catalog() {}

TableSchema
Catalog::make_schema_from(const table_name_t& table_name,
                          table_oid_t table_oid,
                          const ColumnDefListExpr& column_list)
{
  // 1) Iterate over column_list
  // 2) Add TableColumn elements to schema object
  vector<TableColumn> columns;
  for (size_t col_index = 0; col_index < column_list.list().size(); ++col_index) {
    auto &column = column_list.list()[col_index];
    auto type_id = Type::from_string(column.type_name());
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

QuerySchema
Catalog::query_schema_for(table_oid_t table_oid)
{
  return QuerySchema(all_columns_for(table_oid));
}

QuerySchema
Catalog::query_schema_for(const vector<table_name_t>& table_names,
                          const ColumnListExpr& column_list)
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
Catalog::all_columns_for(const vector<table_name_t>& table_names)
{
  vector<QueryColumn> columns;
  for (const auto &table_name : table_names) {
    for (const auto &col : all_columns_for(table_name)) {
      columns.push_back(col);
    }
  }
  return columns;
}

vector<QueryColumn>
Catalog::all_columns_for(const table_name_t& table_name)
{
  return all_columns_for(table_oids_.at(table_name));
}

vector<QueryColumn>
Catalog::all_columns_for(table_oid_t table_oid)
{
  auto table_schema = table_schemas_.at(table_oid);
  vector<QueryColumn> columns;
  for (const auto &table_col : table_schema.columns()) {
    columns.push_back(QueryColumn(table_col.type_id(), table_col.name()));
  }
  return columns;
}

bool
Catalog::table_has_column_named(const table_name_t& table_name,
                                const column_name_t& column_name)
{
  return table_schemas_.at(table_oids_.at(table_name)).has_column(column_name);
}

QueryColumn
Catalog::query_column_for(const table_name_t& table_name,
                          const column_name_t& column_name)
{
  auto table_column = table_schemas_.at(table_oids_.at(table_name)).by_name(column_name);
  return QueryColumn(table_column.type_id(), table_column.name());
}

QueryColumn
Catalog::query_column_for(const vector<table_name_t>& table_names,
                          const column_name_t& column_name)
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


void Catalog::create_table(UNUSED Txn& txn, // TODO: We should be attempting to get an exclusive lock on the table
                           const table_name_t& table_name,
                           ColumnDefListExpr column_list)
{
  assert(table_oids_.count(table_name) == 0);

  table_oid_t table_oid = next_table_oid_++;
  table_oids_[table_name] = table_oid;

  auto schema = make_schema_from(table_name, table_oid, column_list);
  table_schemas_.insert(std::make_pair(table_oid, schema));

  std::cout << "New table created: " << table_name << std::endl;

  index_oids_.emplace(table_name,
                      MutMap<string, index_oid_t>());
}


void Catalog::create_index(UNUSED Txn& txn,
                           const string index_name,
                           const string table_name)
{
  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(table_name) == 1);
  assert(index_oids_[table_name].count(index_name) == 0);

  index_oid_t index_oid = next_index_oid_++;
  index_oids_[table_name][index_name] = index_oid;
  // index_schema_refs_.emplace(index_oid, schema_ref);
}
