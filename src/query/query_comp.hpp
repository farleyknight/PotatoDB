#pragma once

#include "common/config.hpp"
#include "query/base_query.hpp"
#include "query/comp_type.hpp"

class QueryComp : public BaseQuery {
public:
  QueryComp(ptr<BaseQuery>&& left,
            CompType type,
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

  ptr<BaseQuery> left_;
  CompType type_;
  ptr<BaseQuery> right_;
};
