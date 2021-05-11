#pragma once

#include "exprs/base_expr.hpp"

class QueryConst : public BaseQuery {
public:
  explicit QueryConst(Value value)
    : BaseQuery (QueryNodeType::CONST, value.type_id()),
      value_    (value) {}

  virtual Value eval(UNUSED const Tuple& tuple,
                     UNUSED const QuerySchema& schema) const override
  {
    return value_;
  }

  virtual Value eval_join(UNUSED const Tuple& lt,
                          UNUSED const QuerySchema& ls,
                          UNUSED const Tuple& rt,
                          UNUSED const QuerySchema& rs) const override
  {
    return value_;
  }

  virtual Value eval_agg(UNUSED const QuerySchema& schema,
                         UNUSED const vector<Value>& group_bys,
                         UNUSED const vector<Value>& aggs) const override
  {
    return value_;
  }

private:
  Value value_;
};
