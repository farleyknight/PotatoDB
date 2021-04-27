#pragma once

#include "catalog/base_schema.hpp"
#include "exprs/base_expr.hpp"

class TableSchema;

class QuerySchema : public BaseSchema<BaseExpr> {
public:
  QuerySchema(Vec<BaseExpr> exprs, Vec<String> names);

  // No copy
  QuerySchema(CRef<QuerySchema>) = delete;
  // Nocopy-assign
  MRef<QuerySchema> operator=(CRef<QuerySchema>) = delete;
  // Default destructor
  ~QuerySchema() = default;

  static QuerySchema empty();

  static QuerySchema make(Vec<BaseExpr> exprs);

  static QuerySchema copy(CRef<TableSchema> original);
  static QuerySchema copy(CRef<QuerySchema> original);

  static QuerySchema slice(CRef<QuerySchema> from,
                           CRef<Vec<column_oid_t>> oids);
  static QuerySchema slice(CRef<QuerySchema> from,
                           CRef<Vec<String>> names);

  static QuerySchema slice(CRef<TableSchema> from,
                           CRef<Vec<String>> names);

  static QuerySchema merge(CRef<QuerySchema> left,
                           CRef<QuerySchema> right);

  String to_string() const;

  CRef<MutVec<String>> names() const {
    return names_;
  }
private:
  MutVec<String> names_;
};
