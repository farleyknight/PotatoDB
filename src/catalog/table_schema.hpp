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
  /*******************************************************
   * TableSchema : Represents an actual table schema in the
   * database. Can be created, modified, or deleted using
   * the DDL portion of SQL.
   *******************************************************/

  TableSchema(vector<TableColumn> columns,
              vector<string> names,
              string table_name,
              table_oid_t table_oid);
  // No copy
  TableSchema(const TableSchema&) = delete;
  // No copy assign
  TableSchema& operator=(const TableSchema&) = delete;
  // Default destructor
  ~TableSchema() = default;

  string to_string() const;

  QueryColumn operator[](string col_name) const;

  table_oid_t table_oid() const {
    return table_oid_;
  }

private:
  table_oid_t table_oid_;
  string table_name_;
};
