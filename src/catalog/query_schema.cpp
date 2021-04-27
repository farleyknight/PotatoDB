#include "catalog/query_schema.hpp"
#include "catalog/table_schema.hpp"

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

QuerySchema::QuerySchema(Vec<BaseExpr> exprs,
                         Vec<String> names)
  : BaseSchema (exprs),
    names_     (names) {}

/**********************************************
 * TODO: Document me
 **********************************************/

static QuerySchema merge(Ref<QuerySchema> left, Ref<QuerySchema> right) {
  MutVec<BaseExpr> exprs(left.column_count() + right.column_count());
  exprs.insert(exprs.end(), left.all().begin(), left.all().end());
  exprs.insert(exprs.end(), right.all().begin(), right.all().end());

  MutVec<String> names(left.column_count() + right.column_count());
  for (auto const& name : left.names()) {
    names.push_back(name);
  }
  for (auto const& name : right.names()) {
    names.push_back(name);
  }
  return QuerySchema(exprs, names);
}

/**********************************************
 * TODO: Document me
 **********************************************/

QuerySchema QuerySchema::slice(Ref<TableSchema> from, Ref<Vec<String>> names) {
  MutVec<BaseExpr> exprs(names.size());
  for (auto const& name : names) {
    auto col = from.by_name(name);
    auto expr = ColumnExpr(col.type_id(),
                           col.table_oid(),
                           col.oid(),
                           col.name());
    exprs.push_back(expr);
  }
  return QuerySchema(exprs, names);
}

/**********************************************
 * TODO: Document me
 **********************************************/

QuerySchema QuerySchema::slice(Ref<QuerySchema> from, Ref<Vec<String>> names) {
  MutVec<BaseExpr> exprs(names.size());
  for (auto const& name : names) {
    exprs.push_back(from.by_name(name));
  }
  return QuerySchema(exprs, names);
}

/**********************************************
 * TODO: Document me
 **********************************************/

QuerySchema QuerySchema::copy(Ref<TableSchema> original) {
  MutVec<BaseExpr> exprs(original.column_count());
  MutVec<String> names(original.column_count());
  for (auto const& col : original.all()) {
    auto expr = ColumnExpr(col.type_id(),
                           col.table_oid(),
                           col.oid(),
                           col.name());
    exprs.push_back(expr);
    names.push_back(col.name());
  }
  return QuerySchema(exprs, names);
}

/**********************************************
 * TODO: Document me
 **********************************************/

String QuerySchema::to_string() const {
  std::ostringstream os;

  os << "QuerySchema[" <<
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
