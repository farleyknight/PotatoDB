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
  /**********************************************
   * Constructors & destructor
   **********************************************/

  QueryComp(BaseQuery left,
            CompType type,
            BaseQuery right)
    : BaseQuery (TypeId::BOOLEAN),
      left_     (left),
      type_     (type),
      right_    (right) {}

  /**********************************************
   * Instance methods
   **********************************************/

  Value eval(CRef<Tuple> tuple, CRef<QuerySchema> schema) const {
    Value lhs = left_.eval(tuple, schema);
    Value rhs = right_.eval(tuple, schema);
    return Value::make(compare(lhs, rhs));
  }

  Value eval_join(CRef<Tuple> lt, CRef<QuerySchema> ls,
                  CRef<Tuple> rt, CRef<QuerySchema> rs) const {
    Value lhs = left_.eval_join(lt, ls, rt, rs);
    Value rhs = right_.eval_join(lt, ls, rt, rs);
    return Value::make(compare(lhs, rhs));
  }

  Value eval_agg(CRef<QuerySchema> schema,
                 CRef<Vec<Value>> group_bys,
                 CRef<Vec<Value>> aggregates) const {
    Value lhs = left_.eval_agg(schema, group_bys, aggregates);
    Value rhs = right_.eval_agg(schema, group_bys, aggregates);
    return Value::make(compare(lhs, rhs));
  }

private:
  bool compare(CRef<Value> lhs, CRef<Value> rhs) const {
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
