#include "catalog/catalog.hpp"

Catalog::Catalog() {}

TableSchema Catalog::make_schema_from(const string& table_name,
                                      table_oid_t table_oid,
                                      ColumnDefListExpr column_list) {
  // 1) Iterate over column_list
  // 2) Add TableColumn elements to schema object
  vector<TableColumn> columns;
  vector<string> names;
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

    names.push_back(column.name());
  }

  return TableSchema(columns, names, table_name, table_oid);
}

void Catalog::create_table(UNUSED Txn& txn,
                           const string& table_name,
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


void Catalog::register_index(UNUSED Txn& txn,
                             const string index_name,
                             const string table_name,
                             SchemaRef schema_ref)
{
  assert(table_oids_.count(table_name) == 1);
  assert(index_oids_.count(table_name) == 1);
  assert(index_oids_[table_name].count(index_name) == 0);

  index_oid_t index_oid = next_index_oid_++;
  index_oids_[table_name][index_name] = index_oid;
  index_schema_refs_.emplace(index_oid, schema_ref);
}
