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
      autoincrement_offsets_.push_back(offset);
      autoincrement_values_[offset] = 0;
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
TableSchema::missing_columns(const QuerySchema& query_schema) const {
  vector<TableColumn> missing;
  for (const auto &col : columns_) {
    if (!query_schema.has_column(col.name())) {
      // std::cout << "Missing column: " << col.name() << std::endl;
      missing.push_back(col);
    }
  }

  return missing;
}

deque<Value>
TableSchema::defaults(const vector<TableColumn>& missing) {
  // std::cout << "***********" << std::endl;
  // std::cout << "primary key: " << primary_key_ << std::endl;
  // std::cout << "***********" << std::endl;

  deque<Value> values;
  for (auto offset : autoincrement_offsets_) {
    int32_t int_value = autoincrement_values_[offset];
    // std::cout << "AUTO INCREMENT value " << autoincrement_ << std::endl;
    auto value = Value::make(int_value);
    values.push_back(value);
    // TODO: After increment, these values should be persisted to disk somehow!
    autoincrement_values_[offset]++;
  }

  assert(missing.size() == values.size());

  return values;
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
