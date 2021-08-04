#pragma once

#include <sstream>
#include <vector>
#include <memory>
#include <utility>

#include "common/config.hpp"
#include "common/exceptions.hpp"

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"
#include "catalog/query_schema.hpp"

#include "query/query_column.hpp"

class TableSchema : public BaseSchema<TableColumn> {
public:
  using column_offset_t = int32_t;

  TableSchema(vector<TableColumn> columns,
              const table_name_t& table_name,
              table_oid_t table_oid);

  // Allow copy
  TableSchema(const TableSchema&) = default;
  // Allow copy assign
  TableSchema& operator=(const TableSchema&) = default;
  // Default destructor
  ~TableSchema() = default;

  const string to_string() const;

  QueryColumn operator[](const column_name_t& name) const;

  vector<TableColumn> missing_columns(const QuerySchema& query_schema) const;
  deque<Value> defaults(const vector<TableColumn>& cols);

  table_oid_t table_oid() const {
    return table_oid_;
  }

  QuerySchema to_query_schema() const {
    vector<QueryColumn> cols;
    for (const auto &table_col : columns_) {
      cols.push_back(QueryColumn::from(table_col));
    }
    return QuerySchema(cols);
  }

private:
  // TODO: This should be a mapping from the column offset to the actual autoincrement value
  // TODO: Add a mutex around this.
  map<column_offset_t, int32_t> autoincrement_values_;

  // TODO: This is a list of column offsets. If a column offset exists here, it should be
  // considered a primary key.
  // TODO: Add a mutex around this.
  vector<column_offset_t> primary_keys_;

  // TODO: This is a list of column offsets. If a column offset exists here, it should always
  // be updating the corresponding autoincrement value.
  // TODO: Add a mutex around this.
  vector<column_offset_t> autoincrements_;

  table_oid_t table_oid_;
  table_name_t table_name_;
};
