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
              const column_name_t name)
    : BaseQuery (type_id),
      name_     (name)
  {}

  // Allow copy
  QueryColumn(const QueryColumn&) = default;
  // Allow copy assign
  QueryColumn& operator=(const QueryColumn&) = default;
  // Default destructor
  ~QueryColumn() = default;

  Value eval(UNUSED const Tuple& tuple,
             UNUSED const QuerySchema& schema) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

  Value eval_join(UNUSED const Tuple& lt,
                  UNUSED const QuerySchema& ls,
                  UNUSED const Tuple& rt,
                  UNUSED const QuerySchema& rs) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

  Value eval_agg(UNUSED const QuerySchema& schema,
                 UNUSED const vector<Value>& group_bys,
                 UNUSED const vector<Value>& aggs) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

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

  QueryComp lt(QueryConst constant) {
    return QueryComp(*this, CompType::LT, constant);
  }

  QueryComp gt(QueryConst constant) {
    return QueryComp(*this, CompType::GT, constant);
  }

  bool operator==(const QueryColumn& other) const {
    return name_ == other.name_;
  }

  bool operator!=(const QueryColumn& other) const {
    return name_ != other.name_;
  }

private:
  column_name_t name_;
};
