#pragma once

#include "query/base_query.hpp"

class QueryGroupBy : public BaseQuery {
public:
  QueryGroupBy(string column_name);

  QueryGroupBy(TypeId type_id,
               string column_name);

  // Allow copy
  QueryGroupBy(const QueryGroupBy&) = default;
  // Allow copy assign
  QueryGroupBy& operator=(const QueryGroupBy&) = default;
  // Default destructor
  ~QueryGroupBy() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  Value eval(UNUSED const Tuple& tuple,
             UNUSED const QuerySchema& schema) const {
    throw NotImplementedException("eval not implemented");
  }

  Value eval_join(UNUSED const Tuple& lt,
                  UNUSED const QuerySchema& ls,
                  UNUSED const Tuple& rt,
                  UNUSED const QuerySchema& rs) const
  {
    throw NotImplementedException("eval_join not implemented");
  }

  Value eval_agg(const QuerySchema& schema,
                 const Vec<Value>& group_bys,
                 const Vec<Value>&) const;

private:
  BaseQuery node_;
  string column_name_;
};
