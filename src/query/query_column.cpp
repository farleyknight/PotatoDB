#include "query/query_column.hpp"
#include "tuple/tuple.hpp"

Value QueryColumn::eval(UNUSED const Tuple& tuple,
                        UNUSED const QuerySchema& schema) const
{
  return tuple.value_by_name(schema, name_);
}

Value QueryColumn::eval_join(UNUSED const Tuple& lt,
                             UNUSED const QuerySchema& ls,
                             UNUSED const Tuple& rt,
                             UNUSED const QuerySchema& rs) const
{
  throw NotImplementedException("eval_agg not implemented!");
}

Value QueryColumn::eval_agg(UNUSED const QuerySchema& schema,
                            UNUSED const vector<Value>& group_bys,
                            UNUSED const vector<Value>& aggs) const
{
  throw NotImplementedException("eval_agg not implemented!");
}

ptr<QueryComp> QueryColumn::lt(Value constant) {
  auto self = make_unique<QueryColumn>(*this);
  auto value = make_unique<QueryConst>(constant);
  return make_unique<QueryComp>(move(self), CompType::LT, move(value));
}

ptr<QueryComp> QueryColumn::gt(Value constant) {
  auto self = make_unique<QueryColumn>(*this);
  auto value = make_unique<QueryConst>(constant);
  return make_unique<QueryComp>(move(self), CompType::GT, move(value));
}

