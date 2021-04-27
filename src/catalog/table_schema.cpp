#include <sstream>
#include <vector>

#include "common/config.hpp"
#include "catalog/table_schema.hpp"

/**********************************************
 * TableSchema - A full schema of a DB table.
 **********************************************/

TableSchema::TableSchema(Vec<TableColumn> columns,
                         String table_name,
                         table_oid_t table_oid)
  : BaseSchema  (columns),
    table_name_ (table_name),
    table_oid_  (table_oid) {}

ColumnExpr TableSchema::operator[](String col_name) const {
  if (!has_column(col_name)) {
    throw Exception("No such column " + col_name + " + on table " + table_name_);
  }

  auto column = by_name(col_name);
  auto column_oid = column_oid_for(col_name);

  return ColumnExpr(column.type_id(),
                    table_oid_,
                    column_oid,
                    col_name);
}

String TableSchema::to_string() const {
  std::ostringstream os;

  os << "TableSchema[" <<
    "NumColumns:" << column_count() << ", " <<
    "IsInlined:" << all_tuples_inlined_ << ", " <<
    "TupleLength:" << tuple_length_ << "]";

  bool first = true;
  os << " :: (\n";
  for (int i = 0; i < column_count(); i++) {
    // TODO: Is there a better way to interleave these strings with commas?
    if (first) {
      first = false;
    } else {
      os << ", \n";
    }
    os << columns_[i].to_string();
  }
  os << "\n)\n";

  return os.str();
}
