
#include "query/query_comp.hpp"

// TODO: Stick this in BaseQuery
const string query_node_to_string(QueryNodeType type)  {
  switch (type) {
  case QueryNodeType::BASE:
    return "BASE";
  case QueryNodeType::COLUMN:
    return "COLUMN";
  case QueryNodeType::CONST:
    return "CONST";
  case QueryNodeType::COMP:
    return "COMP";
  default:
    return "TODO";
  }
}

Value QueryComp::eval(const Tuple& tuple,
                      const QuerySchema& schema) const
{
  auto lhs = left_->eval(tuple, schema);
  auto rhs = right_->eval(tuple, schema);

  return Value::make(compare(lhs, rhs));
}

Value QueryComp::eval_join(const Tuple& lt,
                           const QuerySchema& ls,
                           const Tuple& rt,
                           const QuerySchema& rs) const
{
  auto lhs = left_->eval_join(lt, ls, rt, rs);
  auto rhs = right_->eval_join(lt, ls, rt, rs);
  return Value::make(compare(lhs, rhs));
}

Value QueryComp::eval_agg(const QuerySchema& schema,
                          const vector<Value>& group_bys,
                          const vector<Value>& aggregates) const
{
  auto lhs = left_->eval_agg(schema, group_bys, aggregates);
  auto rhs = right_->eval_agg(schema, group_bys, aggregates);
  return Value::make(compare(lhs, rhs));
}
