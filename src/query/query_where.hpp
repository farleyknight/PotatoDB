#pragma once

#include "query/base_query.hpp"

enum class LogicalType {
  NONE = 0,
  NOT  = 1,
  AND  = 2,
  OR   = 3
};

class QueryWhere : public BaseQuery {
public:
  QueryWhere(ptr<BaseQuery>&& left)
    : BaseQuery (QueryNodeType::WHERE, TypeId::BOOLEAN),
      left_     (move(left))
  {}

  QueryWhere(ptr<BaseQuery>&& left, LogicalType combine, ptr<BaseQuery>&& right)
    : BaseQuery (QueryNodeType::WHERE, TypeId::BOOLEAN),
      left_     (move(left)),
      right_    (move(right)),
      combine_  (combine)
  {}

  Value eval(const Tuple& tuple,
             const QuerySchema& schema) const override
  {
    auto lhs = left_->eval(tuple, schema);
    if (right_ != nullptr) {
      auto rhs = right_->eval(tuple, schema);
      return Value::make(combine(lhs, rhs));
    } else {
      // TODO: Check for NONE/NOT type
      return lhs;
    }
  }

  Value eval_join(const Tuple& lt,
                  const QuerySchema& ls,
                  const Tuple& rt,
                  const QuerySchema& rs) const override
  {
    auto lhs = left_->eval_join(lt, ls, rt, rs);
    if (right_ != nullptr) {
      auto rhs = right_->eval_join(lt, ls, rt, rs);
      return Value::make(combine(lhs, rhs));
    } else {
      // TODO: Check for NONE/NOT type
      return lhs;
    }
  }

  Value eval_agg(const QuerySchema& schema,
                 const vector<Value>& group_bys,
                 const vector<Value>& aggregates) const override
  {
    auto lhs = left_->eval_agg(schema, group_bys, aggregates);
    if (right_ != nullptr) {
      auto rhs = right_->eval_agg(schema, group_bys, aggregates);
      return Value::make(combine(lhs, rhs));
    } else {
      // TODO: Check for NONE/NOT type
      return lhs;
    }
  }

protected:
  bool combine(const Value& left, const Value& right) const {
    std::cout << "Combining left: " << left.to_string() << " and right: " << right.to_string() << std::endl;

    switch (combine_) {
    case LogicalType::AND:
      return
        left.cast_as(TypeId::BOOLEAN).as<bool>() &&
        right.cast_as(TypeId::BOOLEAN).as<bool>();
    case LogicalType::OR:
      return
        left.cast_as(TypeId::BOOLEAN).as<bool>() ||
        right.cast_as(TypeId::BOOLEAN).as<bool>();
    default:
      throw Exception("other logical types should be supported differently!");
    }
  }

  ptr<BaseQuery> left_, right_;
  LogicalType combine_;
};
