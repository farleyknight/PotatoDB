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
#include "catalog/schema_mgr.hpp"

#include "query/query_column.hpp"

class TableSchema : public BaseSchema {
public:
  // TODO: Let's deprecate all usage of column_offset_t in favor of
  // column_oid_t
  using column_offset_t = int32_t;

  TableSchema(vector<column_oid_t> oids,
              const table_name_t& table_name,
              table_oid_t table_oid,
              SchemaMgr& schema_mgr);

  // NO copy
  TableSchema(const TableSchema&) = delete;
  // NO copy assign
  TableSchema& operator=(const TableSchema&) = delete;
  // Default destructor
  ~TableSchema() = default;

  const string
  to_string() const;

  QueryColumn
  operator[](const column_name_t& name) const;

  const ValueMap
  defaults();

  table_oid_t
  table_oid() const {
    return table_oid_;
  }

  // TODO: Put this in the Catalog
  QuerySchema
  to_query_schema(const ColumnMgr& col_mgr) const {
    return QuerySchema(column_oids_, col_mgr);
  }

  const string
  table_name() const {
    return table_name_;
  }

private:
  // NOTE!
  // We do NOT need multiple autoincrement values!
  // MySQL does NOT support them:
  // https://stackoverflow.com/questions/22824439/how-to-create-two-auto-increment-columns-in-mysql

  column_oid_t autoincrement_oid_ = INVALID_COLUMN_OID;
  // TODO: MySQL supports updating this value via SQL. We should try and match that.
  atomic<int64_t> autoincrement_value_ = 0;

  // TODO: Add a mutex around this.
  vector<column_oid_t> primary_keys_;

  table_oid_t table_oid_;
  table_name_t table_name_;

  ValueMap defaults_;
};
