#pragma once

#include "query/base_query.hpp"
#include "catalog/query_schema.hpp"
#include "query/agg_type.hpp"

class QueryAgg : public BaseQuery {
public:
  QueryAgg(QueryColumn node, AggType agg_type);

  // Allow copy
  QueryAgg(const QueryAgg&) = default;
  // Allow copy assign
  QueryAgg& operator=(const QueryAgg&) = default;
  // Default destructor
  ~QueryAgg() = default;

  Value eval(const Tuple& tuple, const QuerySchema& schema) const;

  Value eval_join(const Tuple& lt,
                  const QuerySchema& ls,
                  const Tuple& rt,
                  const QuerySchema& rs) const;

  Value eval_agg(const QuerySchema& schema,
                 const vector<Value>& group_bys,
                 const vector<Value>& aggregates) const;

  AggType agg_type() const {
    return agg_type_;
  }

  TypeId type_id() const {
    return col_.type_id();
  }

  const string to_string() const;
  const QueryColumn to_query_column() const;
  const string agg_type_string() const;

private:
  QueryColumn col_;
  AggType agg_type_;
};
