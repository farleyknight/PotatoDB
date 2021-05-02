#pragma once

#include "query/base_query.hpp"

class QueryGroupBy : public BaseQuery {
public:
  QueryGroupBy(string column_name);

  QueryGroupBy(TypeId type_id,
               string column_name);

  // Allow copy
  QueryGroupBy(CRef<QueryGroupBy>) = default;
  // Allow copy assign
  QueryGroupBy& operator=(CRef<QueryGroupBy>) = default;
  // Default destructor
  ~QueryGroupBy() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  Value eval(UNUSED CRef<Tuple> tuple,
             UNUSED CRef<QuerySchema> schema) const {
    throw NotImplementedException("eval not implemented");
  }

  Value eval_join(UNUSED CRef<Tuple> lt,
                  UNUSED CRef<QuerySchema> ls,
                  UNUSED CRef<Tuple> rt,
                  UNUSED CRef<QuerySchema> rs) const
  {
    throw NotImplementedException("eval_join not implemented");
  }

  Value eval_agg(CRef<QuerySchema> schema,
                 CRef<Vec<Value>> group_bys,
                 CRef<Vec<Value>>) const;

private:
  BaseQuery node_;
  string column_name_;
};
