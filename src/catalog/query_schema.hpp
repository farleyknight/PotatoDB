#pragma once

#include "catalog/base_schema.hpp"
#include "query/query_column.hpp"
#include "query/query_join.hpp"

class TableSchema;

class QuerySchema : public BaseSchema<QueryColumn> {
public:
  QuerySchema(vector<QueryColumn> cols, vector<string> names)
    : BaseSchema (cols, names)
  {}

  // Allow copy
  QuerySchema(CRef<QuerySchema>) = default;
  // Allow copy-assign
  QuerySchema& operator=(CRef<QuerySchema>) = default;
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

  CRef<vector<QueryJoin>> joins() const {
    return joins_;
  }

private:
  vector<string> names_;
  vector<QueryJoin> joins_; // TODO: Need to populate this
};

