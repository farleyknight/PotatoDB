#pragma once

#include "catalog/table_column.hpp"
#include "query/base_query.hpp"
#include "query/query_comp.hpp"
#include "query/query_const.hpp"

class TableSchema;
class QuerySchema;

class QueryColumn : public BaseQuery {
public:
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

  static QueryColumn from(TableColumn col) {
    return QueryColumn(col.type_id(),
                       col.table_oid(),
                       col.oid(),
                       col.name());
  }

  Value eval(UNUSED const Tuple& tuple,
             UNUSED const QuerySchema& schema) const override;

  Value eval_join(UNUSED const Tuple& lt,
                  UNUSED const QuerySchema& ls,
                  UNUSED const Tuple& rt,
                  UNUSED const QuerySchema& rs) const override;

  Value eval_agg(UNUSED const QuerySchema& schema,
                 UNUSED const vector<Value>& group_bys,
                 UNUSED const vector<Value>& aggs) const override;

  string name() const {
    return name_;
  }

  bool is_inlined() const {
    return false; // TODO!
  }

  bool fixed_length() {
    return 0; // TODO!
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

private:
  table_oid_t table_oid_;
  column_oid_t column_oid_;
  column_name_t name_;
};
