#pragma once

#include "plans/base_plan.hpp"

class HashJoinPlan : public BasePlan {
public:
  HashJoinPlan(SchemaRef schema,
               MovePtr<BaseQuery> pred,
               MoveVec<BaseQuery> left_hash_keys,
               MoveVec<BaseQuery> right_hash_keys)
    : BasePlan         (schema),
      pred_            (move(pred)),
      // TODO: Instead of providing a Vec<BaseQuery> maybe provice a key schema?
      // A key schema might need to reference the parent schema?
      left_hash_keys_  (move(left_hash_keys)),
      right_hash_keys_ (move(right_hash_keys))
  {
    assert(left_hash_keys_.size() == right_hash_keys_.size());
  }

  PlanType type() const  { return PlanType::HASH_JOIN; }
  const BaseQuery& pred() {
    assert(pred_);
    return *pred_;
  }

  // NOTE: These arrays are used to create the key schemas.
  const Vec<BaseQuery>& left_keys()  { return left_hash_keys_; }
  const Vec<BaseQuery>& right_keys() { return right_hash_keys_; }

private:
  Ptr<BaseQuery> pred_;
  Vec<BaseQuery> left_hash_keys_, right_hash_keys_;
};
