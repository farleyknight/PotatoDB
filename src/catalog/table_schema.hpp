#pragma once

#include <sstream>
#include <vector>
#include <memory>
#include <utility>

#include "common/config.hpp"
#include "common/exception_type.hpp"

#include "catalog/table_column.hpp"
#include "catalog/base_schema.hpp"
#include "exprs/column_expr.hpp"

class TableSchema : public BaseSchema<TableColumn> {
public:
  /*******************************************************
   * TableSchema : Represents an actual table schema in the
   * database. Can be created, modified, or deleted using
   * the DDL portion of SQL.
   *******************************************************/

  TableSchema(Vec<TableColumn> columns,
              String table_name,
              table_oid_t table_oid);
  // No copy
  TableSchema(Ref<TableSchema>) = delete;
  // No copy assign
  MRef<TableSchema> operator=(Ref<TableSchema>) = delete;
  // Default destructor
  ~TableSchema() = default;

  String to_string() const;

  ColumnExpr operator[](String col_name) const;

  table_oid_t table_oid() const {
    return table_oid_;
  }

private:
  table_oid_t table_oid_;
  MutString table_name_;
};
