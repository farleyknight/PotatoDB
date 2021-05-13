#pragma once

#include <sstream>
#include <vector>
#include <memory>
#include <utility>

#include "common/config.hpp"
#include "common/exceptions.hpp"

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"

#include "query/query_column.hpp"

class TableSchema : public BaseSchema<TableColumn> {
public:
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

  table_oid_t table_oid() const {
    return table_oid_;
  }

private:
  table_oid_t table_oid_;
  table_name_t table_name_;
};
