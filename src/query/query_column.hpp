#pragma once

#include "query/base_query.hpp"
#include "query/query_comp.hpp"
#include "query/query_const.hpp"

class TableSchema;
class QuerySchema;
class TableColumn;

// NOTE: Kind of weird, but I've decided to use negative numbers to
// refer some types of query columns that come up, such as splats, but
// also SHOW TABLES (which has a synthetic `table_name` column) and
// DESCRIBE TABLE `foobar` (which has lots of other synthetics, such as
// the type of the column, whether it is nullable, etc)

// * and COUNT(*) start at -10
const column_oid_t SPLAT_COLUMN_OID         = -10;
const column_oid_t COUNT_SPLAT_COLUMN_OID   = -11;

// SHOW TABLES start at -20
const column_oid_t TABLE_NAME_COLUMN_OID    = -20;

// DESCRIBE_TABLES start at -30
const column_oid_t COLUMN_NAME_COLUMN_OID   = -30;
const column_oid_t COLUMN_TYPE_COLUMN_OID   = -31;
const column_oid_t NULLABLE_COLUMN_OID      = -32;
const column_oid_t PRIMARY_KEY_COLUMN_OID   = -33;
const column_oid_t DEFAULT_VALUE_COLUMN_OID = -34;
const column_oid_t EXTRA_COLUMN_OID         = -35;

class QueryColumn : public BaseQuery {
public:
  explicit
  QueryColumn(column_oid_t oid,
              TypeId type_id,
              column_name_t name)
    : BaseQuery   (QueryNodeType::COLUMN, type_id),
      table_oid_  (INVALID_TABLE_OID),
      column_oid_ (oid),
      name_       (name)
  {}

  explicit
  QueryColumn(column_oid_t oid,
              column_name_t name)
    : BaseQuery   (QueryNodeType::COLUMN, TypeId::INVALID),
      table_oid_  (INVALID_TABLE_OID),
      column_oid_ (oid),
      name_       (name)
  {}

  explicit
  QueryColumn(TypeId type_id,
              table_oid_t table_oid,
              column_oid_t column_oid,
              column_name_t name)
    : BaseQuery   (QueryNodeType::COLUMN, type_id),
      table_oid_  (table_oid),
      column_oid_ (column_oid),
      name_       (name)
  {}

  // Allow copy
  QueryColumn(const QueryColumn&) = default;
  // Allow copy assign
  QueryColumn& operator=(const QueryColumn&) = default;
  // Default destructor
  ~QueryColumn() = default;

  static const QueryColumn
  splat() {
    return QueryColumn(SPLAT_COLUMN_OID, "*");
  }

  static const QueryColumn
  count_splat() {
    return QueryColumn(COUNT_SPLAT_COLUMN_OID, TypeId::INTEGER, "COUNT(*)");
  }

  static const QueryColumn
  table_name() {
    return QueryColumn(TABLE_NAME_COLUMN_OID, TypeId::VARCHAR, "table_name");
  }

  static const QueryColumn
  column_name() {
    return QueryColumn(COLUMN_NAME_COLUMN_OID, TypeId::VARCHAR, "column_name");
  }

  static const QueryColumn
  column_type() {
    return QueryColumn(COLUMN_TYPE_COLUMN_OID, TypeId::VARCHAR, "column_type");
  }

  static const QueryColumn
  nullable() {
    return QueryColumn(NULLABLE_COLUMN_OID, TypeId::VARCHAR, "nullable");
  }

  static const QueryColumn
  primary_key() {
    return QueryColumn(PRIMARY_KEY_COLUMN_OID, TypeId::VARCHAR, "primary_key");
  }

  static const QueryColumn
  default_value() {
    return QueryColumn(DEFAULT_VALUE_COLUMN_OID, TypeId::VARCHAR, "default_value");
  }

  static const QueryColumn
  extra() {
    return QueryColumn(EXTRA_COLUMN_OID, TypeId::VARCHAR, "extra");
  }

  bool is_splat() const {
    return (name_ == "*");
  }

  bool is_count_splat() const {
    return (name_ == "COUNT(*)");
  }

  static QueryColumn
  from(const TableColumn& col);

  Value eval(const Tuple& tuple,
             const QuerySchema& schema) const override;

  Value eval_join(const Tuple& lt,
                  const QuerySchema& ls,
                  const Tuple& rt,
                  const QuerySchema& rs) const override;

  Value eval_agg(const QuerySchema& schema,
                 const vector<Value>& group_bys,
                 const vector<Value>& aggs) const override;

  const string name() const {
    return name_;
  }

  bool is_inlined() const {
    return type_id_ != TypeId::VARCHAR;
  }

  value_length_t
  fixed_length() const;

  value_length_t
  variable_length() const {
    return 0; // TODO!
  }

  ptr<QueryComp>
  lt(Value constant);


  ptr<QueryComp>
  gt(Value constant);

  bool operator==(const QueryColumn& other) const {
    return name_ == other.name_;
  }

  bool operator!=(const QueryColumn& other) const {
    return name_ != other.name_;
  }

  column_oid_t
  oid() const {
    return column_oid_;
  }

  table_oid_t
  table_oid() const {
    return table_oid_;
  }

  const string to_string() const;

private:
  table_oid_t table_oid_   = INVALID_TABLE_OID;
  column_oid_t column_oid_ = INVALID_COLUMN_OID;
  column_name_t name_;
};
