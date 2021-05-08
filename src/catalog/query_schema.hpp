#pragma once

#include "catalog/base_schema.hpp"
#include "query/query_column.hpp"
#include "query/query_join.hpp"

class TableSchema;

class QuerySchema : public BaseSchema<QueryColumn> {
public:
  QuerySchema(vector<QueryColumn> cols)
    : BaseSchema (cols)
  {}

  // Allow copy
  QuerySchema(const QuerySchema&) = default;
  // Allow copy-assign
  QuerySchema& operator=(const QuerySchema&) = default;
  // Default destructor
  ~QuerySchema() = default;

  static QuerySchema empty();

  static QuerySchema make(vector<QueryColumn> cols);

  static QuerySchema copy(const TableSchema& original);
  static QuerySchema copy(const QuerySchema& original);

  static QuerySchema slice(const QuerySchema& from,
                           const vector<column_oid_t>& oids);

  static QuerySchema slice(const QuerySchema& from,
                           const vector<string>& names);

  static QuerySchema slice(const TableSchema& from,
                           const vector<string>& names);

  static QuerySchema merge(const QuerySchema& left,
                           const QuerySchema& right);

  const string to_string() const;

  const vector<string>& names() const {
    return names_;
  }

  const vector<QueryJoin>& joins() const {
    return joins_;
  }

private:
  vector<string> names_;
  vector<QueryJoin> joins_; // TODO: Need to populate this
};

