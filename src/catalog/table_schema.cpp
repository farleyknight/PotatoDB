#include <sstream>
#include <vector>

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/query_schema.hpp"

#include "query/query_column.hpp"

TableSchema::TableSchema(vector<TableColumn> columns,
                         const table_name_t& table_name,
                         table_oid_t table_oid)
  : BaseSchema   (columns),
    table_oid_   (table_oid),
    table_name_  (table_name)
{
  // NOTE: Let's make the constructor arguments as simple as possible
  // by moving this logic into the constructor instead of expecting
  // the caller to do it.

  int32_t column_count = columns_.size();

  for (int32_t offset = 0; offset < column_count; ++offset) {
    if (columns_[offset].is_primary_key()) {
      primary_keys_.push_back(offset);
    }

    if (columns_[offset].is_autoincrement()) {
      auto oid = columns_[offset].oid();
      std::cout << "Initializing AUTO INCREMENT with column oid: " << oid << std::endl;
      autoincrement_values_[oid] = 0;
    }
  }
}

QueryColumn TableSchema::operator[](const column_name_t& col_name) const
{
  if (!has_column(col_name)) {
    throw Exception("No such column " + col_name + " + on table " + table_name_);
  }

  auto column = by_name(col_name);
  auto column_oid = column_oid_for(col_name);

  return QueryColumn(column.type_id(),
                     table_oid_,
                     column_oid,
                     col_name);
}

vector<TableColumn>
TableSchema::missing_columns(const QuerySchema& query_schema) const
{
  vector<TableColumn> missing;
  for (const auto &col : columns_) {
    if (!query_schema.has_column(col.name())) {
      std::cout << "Missing column: " << col.name() << std::endl;
      missing.push_back(col);
    }
  }

  return missing;
}

// TODO!
// We do NOT need multiple auto-increment values!
// MySQL does NOT support them:
// https://stackoverflow.com/questions/22824439/how-to-create-two-auto-increment-columns-in-mysql

const map<column_oid_t, Value>
TableSchema::defaults(const vector<TableColumn>& missing) {
  map<column_oid_t, Value> defaults;
  for (const auto &col : missing) {
    auto oid = col.oid();

    assert(autoincrement_values_.contains(oid));
    auto value_as_int32 = autoincrement_values_[oid];
    std::cout << "AUTO INCREMENT before value " << value_as_int32 << std::endl;
    defaults.emplace(oid, Value::make(value_as_int32));
    // TODO: After increment, these values should be persisted to disk somehow!
    // autoincrement_values_.emplace(oid, value_as_int32 + 1);

    autoincrement_values_[oid]++;

    std::cout << "AUTO INCREMENT after value " << autoincrement_values_[oid] << std::endl;
  }

  assert(missing.size() == defaults.size());

  return defaults;
}

const string
TableSchema::to_string() const {
  stringstream os;

  os << "TableSchema[" << tuple_layout_.to_string() << "]";
  os << " :: (\n";

  for (int32_t i = 0; i < column_count(); i++) {
    // TODO: Is there a better way to interleave these strings with commas?
    if (i > 0) {
      os << ", \n";
    }
    os << columns_[i].to_string();
  }
  os << "\n)\n";

  return os.str();
}
