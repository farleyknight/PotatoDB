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

  QueryColumn
  operator[](const column_name_t& name) const;

  vector<TableColumn>
  missing_columns(const QuerySchema& query_schema) const;

  const map<column_oid_t, Value>
  defaults(const vector<TableColumn>& cols);

  table_oid_t table_oid() const {
    return table_oid_;
  }

  // TODO: Put this in the Catalog
  QuerySchema
  to_query_schema() const {
    vector<QueryColumn> cols;
    for (const auto &table_col : columns_) {
      cols.push_back(QueryColumn::from(table_col));
    }
    return QuerySchema(cols);
  }

  const string
  table_name() const {
    return table_name_;
  }

private:
  // TODO!
  // We do NOT need multiple auto-increment values!
  // MySQL does NOT support them:
  // https://stackoverflow.com/questions/22824439/how-to-create-two-auto-increment-columns-in-mysql
  map<column_oid_t, int32_t> autoincrement_values_;

  // TODO: This is a list of column offsets. If a column offset exists here, it should be
  // considered a primary key.
  // TODO: Add a mutex around this.
  vector<column_offset_t> primary_keys_;

  table_oid_t table_oid_;
  table_name_t table_name_;
};
