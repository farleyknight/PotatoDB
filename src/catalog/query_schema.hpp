#pragma once

#include "catalog/base_schema.hpp"
#include "query/query_column.hpp"

class TableSchema;

class QuerySchema : public BaseSchema<QueryColumn> {
public:
  QuerySchema(vector<QueryColumn> cols, vector<string> names);

  // No copy
  QuerySchema(CRef<QuerySchema>) = delete;
  // Nocopy-assign
  MRef<QuerySchema> operator=(CRef<QuerySchema>) = delete;
  // Default destructor
  ~QuerySchema() = default;

  static QuerySchema empty();

  static QuerySchema make(vector<QueryColumn> cols);

  static QuerySchema copy(CRef<TableSchema> original);
  static QuerySchema copy(CRef<QuerySchema> original);

  static QuerySchema slice(CRef<QuerySchema> from,
                           CRef<vector<column_oid_t>> oids);

  static QuerySchema slice(CRef<QuerySchema> from,
                           CRef<vector<string>> names);

  static QuerySchema slice(CRef<TableSchema> from,
                           CRef<vector<string>> names);

  static QuerySchema merge(CRef<QuerySchema> left,
                           CRef<QuerySchema> right);

  string to_string() const;

  CRef<vector<string>> names() const {
    return names_;
  }
private:
  vector<string> names_;
};
