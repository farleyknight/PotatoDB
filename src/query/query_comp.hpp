#pragma once

#include "common/config.hpp"
#include "query/base_query.hpp"
#include "query/compare_type.hpp"

class QueryComp : public BaseQuery {
public:
  QueryComp(ptr<BaseQuery>&& left,
            CompareType type,
            ptr<BaseQuery>&& right)
    : BaseQuery (QueryNodeType::COMP, TypeId::BOOLEAN),
      left_     (move(left)),
      type_     (type),
      right_    (move(right)) {}

  Value eval(const Tuple& tuple,
             const QuerySchema& schema) const override;

  Value eval_join(const Tuple& lt,
                  const QuerySchema& ls,
                  const Tuple& rt,
                  const QuerySchema& rs) const override;

  Value eval_agg(const QuerySchema& schema,
                 const vector<Value>& group_bys,
                 const vector<Value>& aggregates) const override;

private:
  bool compare(const Value& left,
               const Value& right) const
  {
    logger->debug("Comparing left: " + left.to_string() + " and right: " + right.to_string());

    switch (type_) {
    case CompareType::EQ:
      return left.eq(right);
    case CompareType::NE:
      return left.ne(right);
    case CompareType::LT:
      return left.lt(right);
    case CompareType::LTE:
      return left.lte(right);
    case CompareType::GT:
      return left.gt(right);
    case CompareType::GTE:
      return left.gte(right);
    default:
      throw NotImplementedException("Unsupported comparison type.");
    }
  }

  ptr<BaseQuery> left_;
  CompareType type_;
  ptr<BaseQuery> right_;
};
