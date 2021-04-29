#pragma once

#include "plans/base_plan.hpp"

class HashJoinPlan : public BasePlan {
public:
  HashJoinPlan(MovePtr<Schema> schema,
               Ref<BaseExpr> pred,
               MoveVec<BaseExpr> left_hash_keys,
               MoveVec<BaseExpr> right_hash_keys)
    : BasePlan         (move(schema)),
      pred_            (pred),
      // TODO: Instead of providing a Vec<BaseExpr> maybe provice a key schema?
      // A key schema might need to reference the parent schema?
      left_hash_keys_  (move(left_hash_keys)),
      right_hash_keys_ (move(right_hash_keys))
  {
    assert(left_hash_keys_.size() == right_hash_keys_.size());
  }

  PlanType type() const override { return PlanType::HASH_JOIN; }
  Ref<BaseExpr> pred()           { return pred_; }

  // NOTE: These arrays are used to create the key schemas.
  Ref<Vec<BaseExpr>> left_keys()  { return left_hash_keys_; }
  Ref<Vec<BaseExpr>> right_keys() { return right_hash_keys_; }

private:
  Ref<BaseExpr> pred_;
  Vec<BaseExpr> left_hash_keys_, right_hash_keys_;
};
