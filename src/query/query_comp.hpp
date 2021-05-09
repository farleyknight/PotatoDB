#pragma once

#include "common/config.hpp"
#include "query/base_query.hpp"

enum class CompType {
  // INVALID = 0,
  EQ  = 1, // equal
  NE  = 2, // not equal
  LT  = 3, // less than (<)
  LTE = 4, // less than or equals (<=)
  GT  = 5, // greater than (>)
  GTE = 6  // greater than or equals (>=)
};

class QueryComp : public BaseQuery {
public:

  QueryComp(BaseQuery left,
            CompType type,
            BaseQuery right)
    : BaseQuery (TypeId::BOOLEAN),
      left_     (left),
      type_     (type),
      right_    (right) {}

  Value eval(const Tuple& tuple,
             const QuerySchema& schema) const {
    auto lhs = left_.eval(tuple, schema);
    auto rhs = right_.eval(tuple, schema);
    return Value::make(compare(lhs, rhs));
  }

  Value eval_join(const Tuple& lt,
                  const QuerySchema& ls,
                  const Tuple& rt,
                  const QuerySchema& rs) const
  {
    auto lhs = left_.eval_join(lt, ls, rt, rs);
    auto rhs = right_.eval_join(lt, ls, rt, rs);
    return Value::make(compare(lhs, rhs));
  }

  Value eval_agg(const QuerySchema& schema,
                 const vector<Value>& group_bys,
                 const vector<Value>& aggregates) const {
    auto lhs = left_.eval_agg(schema, group_bys, aggregates);
    auto rhs = right_.eval_agg(schema, group_bys, aggregates);
    return Value::make(compare(lhs, rhs));
  }

private:
  bool compare(const Value& lhs,
               const Value& rhs) const
  {
    switch (type_) {
    case CompType::EQ:
      return lhs.eq(rhs);
    case CompType::NE:
      return lhs.ne(rhs);
    case CompType::LT:
      return lhs.lt(rhs);
    case CompType::LTE:
      return lhs.lte(rhs);
    case CompType::GT:
      return lhs.gt(rhs);
    case CompType::GTE:
      return lhs.gte(rhs);
    default:
      throw NotImplementedException("Unsupported comparison type.");
    }
  }

  BaseQuery left_;
  CompType type_;
  BaseQuery right_;
};
