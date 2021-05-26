#pragma once

#include "catalog/table_column.hpp"
#include "query/base_query.hpp"
#include "query/query_comp.hpp"
#include "query/query_const.hpp"

class TableSchema;
class QuerySchema;

class QueryColumn : public BaseQuery {
public:
  QueryColumn(TypeId type_id, column_name_t name)
    : BaseQuery   (QueryNodeType::COLUMN, type_id),
      table_oid_  (INVALID_TABLE_OID),
      column_oid_ (INVALID_COLUMN_OID),
      name_       (name)
  {}

  QueryColumn(column_name_t name)
    : BaseQuery   (QueryNodeType::COLUMN, TypeId::INVALID),
      table_oid_  (INVALID_TABLE_OID),
      column_oid_ (INVALID_COLUMN_OID),
      name_       (name)
  {}

  explicit QueryColumn(TypeId type_id,
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

  static QueryColumn splat() {
    return QueryColumn("*");
  }

  static QueryColumn count_splat() {
    return QueryColumn(TypeId::INTEGER, "COUNT(*)");
  }

  bool is_splat() const {
    return (name_ == "*");
  }

  bool is_count_splat() const {
    return (name_ == "COUNT(*)");
  }

  static QueryColumn from(TableColumn col) {
    return QueryColumn(col.type_id(),
                       col.table_oid(),
                       col.oid(),
                       col.name());
  }

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

  size_t fixed_length() {
    return Type::size_of(type_id_);
  }

  size_t variable_length() const {
    return 0; // TODO!
  }

  ptr<QueryComp> lt(Value constant);
  ptr<QueryComp> gt(Value constant);

  bool operator==(const QueryColumn& other) const {
    return name_ == other.name_;
  }

  bool operator!=(const QueryColumn& other) const {
    return name_ != other.name_;
  }

  column_oid_t column_oid() const {
    return column_oid_;
  }

  table_oid_t table_oid() const {
    return table_oid_;
  }

  const string to_string() const {
    stringstream os;
    os << "Name : " << name_ << std::endl;
    os << "Type : " << Type::as_string(type_id_) << std::endl;
    return os.str();
  }

private:
  table_oid_t table_oid_   = INVALID_TABLE_OID;
  column_oid_t column_oid_ = INVALID_COLUMN_OID;
  column_name_t name_;
};
