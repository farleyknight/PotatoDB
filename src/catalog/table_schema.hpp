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
              string table_name,
              table_oid_t table_oid);
  // No copy
  TableSchema(CRef<TableSchema>) = delete;
  // No copy assign
  TableSchema& operator=(CRef<TableSchema>) = delete;
  // Default destructor
  ~TableSchema() = default;

  string to_string() const;

  QueryColumn operator[](String col_name) const;

  table_oid_t table_oid() const {
    return table_oid_;
  }

private:
  table_oid_t table_oid_;
  MutString table_name_;
};
