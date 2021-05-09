#include "catalog/query_schema.hpp"
#include "catalog/table_schema.hpp"
#include "query/query_column.hpp"

UNUSED QuerySchema QuerySchema::merge(const QuerySchema& left,
                                      const QuerySchema& right)
{
  vector<QueryColumn> cols;
  cols.insert(cols.end(), left.all().begin(), left.all().end());
  cols.insert(cols.end(), right.all().begin(), right.all().end());

  return QuerySchema(cols);
}


QuerySchema QuerySchema::slice(const TableSchema& schema,
                               const vector<string>& names)
{
  vector<QueryColumn> cols;
  for (auto const& name : names) {
    cols.push_back(QueryColumn::from(schema.by_name(name)));
  }
  return QuerySchema(cols);
}

QuerySchema QuerySchema::slice(const QuerySchema& from,
                               const vector<string>& names)
{
  vector<QueryColumn> cols;
  for (auto const& name : names) {
    cols.push_back(from.by_name(name));
  }
  return QuerySchema(cols);
}

QuerySchema QuerySchema::copy(const TableSchema& original) {
  vector<QueryColumn> cols;
  for (auto const& col : original.all()) {
    cols.push_back(QueryColumn::from(col));
  }
  return QuerySchema(cols);
}

QuerySchema QuerySchema::empty() {
  return QuerySchema(vector<QueryColumn>());
}

const string QuerySchema::to_string() const {
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
