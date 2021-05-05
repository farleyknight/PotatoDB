#pragma once

#include "exprs/base_expr.hpp"

class QueryConst : public BaseQuery {
public:
  explicit QueryConst(Value value)
    : BaseQuery (value.type_id()),
      value_    (value) {}

  explicit QueryConst(int8_t integer)
    : BaseQuery (TypeId::SMALLINT),
      value_    (Value::make<int8_t>(integer)) {}

  explicit QueryConst(bool boolean)
    : BaseQuery (TypeId::BOOLEAN),
      value_    (Value::make<bool>(boolean)) {}

  template<typename T>
  static ptr<QueryConst> make(T data) {
    auto value = Value::make<T>(data);
    return make_unique<QueryConst>(move(value));
  }

  static ptr<QueryConst> make(TypeId type_id, int integer) {
    auto value = Value(type_id, integer);
    return make_unique<QueryConst>(move(value));
  }

  static ptr<QueryConst> make(Move<Value> value) {
    return make_unique<QueryConst>(move(value));
  }

  /**********************************************
   * Instance methods
   **********************************************/

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
