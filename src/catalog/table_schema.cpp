#include <sstream>
#include <vector>

#include "common/config.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/query_schema.hpp"

#include "query/query_column.hpp"

TableSchema::TableSchema(vector<column_oid_t> columns,
                         const table_name_t& table_name,
                         table_oid_t table_oid,
                         SchemaMgr& schema_mgr)
  : BaseSchema   (columns, schema_mgr),
    defaults_    (columns.size()),
    table_oid_   (table_oid),
    table_name_  (table_name)
{
  for (const auto &oid : oids) {
    const auto &col = schema_mgr.column_for(column_oid);
    if (col.is_primary_key()) {
      primary_keys_.push_back(oid);
    }

    if (col.is_autoincrement()) {
      auto name = col.name();
      autoincrement_oid_ = oid;
      logger->debug("[TableSchema] Found AUTOINCREMENT during construction: {}", name);
    }

    if (col.has_default()) {
      auto default_value = col.default_value();
      logger->debug("[TableSchema] Found column w/ default value: {}",
                    default_value.to_string());
      defaults_.emplace(oid, default_value);
    }
  }
}

QueryColumn
TableSchema::operator[](const column_name_t& name) const
{
  if (!has_column(col_name)) {
    throw Exception("No such column " + name + " + on table " + table_name_);
  }

  auto column = by_name(name);

  return QueryColumn(column.type_id(),
                     table_oid_,
                     column.oid(),
                     name);
}

// TODO!
// We do NOT need multiple auto-increment values!
// MySQL does NOT support them:
// https://stackoverflow.com/questions/22824439/how-to-create-two-auto-increment-columns-in-mysql


// TODO:
// Each TableSchema should have a ValueMap object that holds defaults for each of the columns
// The method `defaults` should actually produce a new ValueMap each time its called. The new
// ValueMap will have the auto-increment field filled in.

ValueMap
TableSchema::defaults() {
  auto default_tuple = ValueMap(defaults_);

  if (autoincrement_oid_ != INVALID_COLUMN_OID) {
    auto next_value = autoincrement_value_++;
    default_tuple[autoincrement_oid_] = Value::make(next_value);
  }

  return default_tuple;
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
