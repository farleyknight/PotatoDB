#pragma once

#include "exprs/base_expr.hpp"

class QueryConst : public BaseQuery {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  explicit QueryConst(Move<Value> value)
    : BaseQuery (value.type_id()),
      value_    (std::move(value)) {}

  explicit QueryConst(int8_t integer)
    : BaseQuery (TypeId::SMALLINT),
      value_    (Value::make<int8_t>(integer)) {}

  explicit QueryConst(bool boolean)
    : BaseQuery (TypeId::BOOLEAN),
      value_    (Value::make<bool>(boolean)) {}

  template<typename T>
  static MutPtr<QueryConst> make(T data) {
    auto value = Value::make<T>(data);
    return make_unique<QueryConst>(std::move(value));
  }

  static MutPtr<QueryConst> make(TypeId type_id, int integer) {
    auto value = Value(type_id, integer);
    return make_unique<QueryConst>(std::move(value));
  }

  static MutPtr<QueryConst> make(Move<Value> value) {
    return make_unique<QueryConst>(std::move(value));
  }

  /**********************************************
   * Instance methods
   **********************************************/

  Value eval(UNUSED CRef<Tuple> tuple,
             UNUSED CRef<QuerySchema> schema) const {
    return value_;
  }

  Value eval_join(UNUSED CRef<Tuple> lt,
                  UNUSED CRef<QuerySchema> ls,
                  UNUSED CRef<Tuple> rt,
                  UNUSED CRef<QuerySchema> rs) const
  {
    return value_;
  }

  Value eval_agg(UNUSED CRef<Vec<Value>> group_bys,
                 UNUSED CRef<Vec<Value>> aggs) const
  {
    return value_;
  }

private:
  Value value_;
};
