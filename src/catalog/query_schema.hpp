#pragma once

#include "catalog/base_schema.hpp"
#include "query/query_column.hpp"
#include "query/query_join.hpp"

class TableSchema;

class QuerySchema : public BaseSchema {
public:
  QuerySchema(vector<column_oid_t> cols,
              const ColumnMgr& col_mgr)
    : BaseSchema (cols, col_mgr)
  {}

  // NO copy
  QuerySchema(const QuerySchema&) = delete;
  // NO copy-assign
  QuerySchema& operator=(const QuerySchema&) = delete;
  // Default destructor
  ~QuerySchema() = default;

  const string to_string() const;

  const vector<QueryJoin>& joins() const {
    return joins_;
  }

private:

  vector<column_name_t> names_;
  vector<table_oid_t> tables_;
  vector<QueryJoin> joins_; // TODO: Need to populate this
};
