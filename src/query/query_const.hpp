#pragma once

#include "exprs/base_expr.hpp"

class QueryConst : public BaseQuery {
public:
  explicit QueryConst(Value value)
    : BaseQuery (value.type_id()),
      value_    (value) {}

  Value eval(UNUSED const Tuple& tuple,
             UNUSED const QuerySchema& schema) const {
    return value_;
  }

  Value eval_join(UNUSED const Tuple& lt,
                  UNUSED const QuerySchema& ls,
                  UNUSED const Tuple& rt,
                  UNUSED const QuerySchema& rs) const
  {
    return value_;
  }

  Value eval_agg(UNUSED const vector<Value>& group_bys,
                 UNUSED const vector<Value>& aggs) const
  {
    return value_;
  }

private:
  Value value_;
};
