#include <sstream>
#include <vector>

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/query_schema.hpp"

#include "query/query_column.hpp"

TableSchema::TableSchema(vector<TableColumn> columns,
                         const table_name_t& table_name,
                         const string& primary_key,
                         table_oid_t table_oid)
  : BaseSchema   (columns),
    primary_key_ (primary_key),
    table_oid_   (table_oid),
    table_name_  (table_name)
{}


QueryColumn TableSchema::operator[](const column_name_t& col_name) const {
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
TableSchema::defaults(const vector<TableColumn>& cols) {
  //std::cout << "***********" << std::endl;
  //std::cout << "primary key: " << primary_key_ << std::endl;
  //std::cout << "***********" << std::endl;

  deque<Value> values;
  for (const auto& col : cols) {
    // TODO: The only kind of DEFAULT we handle is PRIMARY KEY AUTOINCREMENT
    // In the future, we should handle all DEFAULTs here..
    if (col.name() == primary_key_) {
      // std::cout << "AUTO INCREMENT value " << autoincrement_ << std::endl;
      auto value = Value::make(static_cast<int32_t>(autoincrement_));
      ++autoincrement_;
      values.push_back(value);
    }
  }

  assert(cols.size() == values.size());

  return values;
}

const string TableSchema::to_string() const {
  std::ostringstream os;

  os <<
    "TableSchema[" <<
    "NumColumns:" << column_count() << ", " <<
    "IsInlined:" << all_tuples_inlined_ << ", " <<
    "TupleLength:" << tuple_length_ <<
    "]";

  os << " :: (\n";
  for (size_t i = 0; i < column_count(); i++) {
    // TODO: Is there a better way to interleave these strings with commas?
    if (i > 0) {
      os << ", \n";
    }
    os << columns_[i].to_string();
  }
  os << "\n)\n";

  return os.str();
}
