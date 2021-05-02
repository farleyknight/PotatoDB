#include "catalog/query_schema.hpp"
#include "catalog/table_schema.hpp"
#include "query/query_column.hpp"

/************************************************
 * QuerySchema - A schema in the
 * context of a query.
 *
 * This is in contrast to QuerySchema
 * which represents a table as seen by
 * the DB's catalog.
 *
 * QuerySchema objects are often built
 * from or connected to QuerySchemas
 ************************************************/

UNUSED QuerySchema QuerySchema::merge(CRef<QuerySchema> left,
                                      CRef<QuerySchema> right)
{
  vector<QueryColumn> cols;
  cols.insert(cols.end(), left.all().begin(), left.all().end());
  cols.insert(cols.end(), right.all().begin(), right.all().end());

  vector<string> names(left.column_count() + right.column_count());
  for (auto const& name : left.names()) {
    names.push_back(name);
  }
  for (auto const& name : right.names()) {
    names.push_back(name);
  }
  return QuerySchema(cols, names);
}


QuerySchema QuerySchema::slice(CRef<TableSchema> from,
                               CRef<vector<string>> names)
{
  vector<QueryColumn> cols;
  for (auto const& name : names) {
    auto col = from.by_name(name);
    auto query_col = QueryColumn(col.type_id(),
                                 // col.table_oid(),
                                 // col.oid(),
                                 col.name());
    cols.push_back(query_col);
  }
  return QuerySchema(cols, names);
}

QuerySchema QuerySchema::slice(CRef<QuerySchema> from,
                               CRef<vector<string>> names)
{
  vector<QueryColumn> cols;
  for (auto const& name : names) {
    cols.push_back(from.by_name(name));
  }
  return QuerySchema(cols, names);
}

QuerySchema QuerySchema::copy(CRef<TableSchema> original) {
  vector<QueryColumn> cols;
  vector<string> names(original.column_count());
  for (auto const& col : original.all()) {
    auto query_col = QueryColumn(col.type_id(),
                                 // col.table_oid(),
                                 // col.oid(),
                                 col.name());
    cols.push_back(query_col);
    names.push_back(col.name());
  }
  return QuerySchema(cols, names);
}

string QuerySchema::to_string() const {
  std::ostringstream os;

  os << "QuerySchema[" <<
    "NumColumns:" << column_count() << ", " <<
    "IsInlined:" << all_tuples_inlined_ << ", " <<
    "TupleLength:" << tuple_length_ << "]";

  bool first = true;
  os << " :: (\n";
  for (size_t i = 0; i < column_count(); i++) {
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
