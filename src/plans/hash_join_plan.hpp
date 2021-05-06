#pragma once

#include "plans/base_plan.hpp"
#include "plans/schema_plan.hpp"
#include "plans/maybe_pred_plan.hpp"

class HashJoinPlan : public BasePlan, public SchemaPlan, public MaybePredPlan {
public:
  HashJoinPlan(QuerySchema schema,
               ptr<BaseQuery>&& pred,
               MoveVec<BaseQuery> left_hash_keys,
               MoveVec<BaseQuery> right_hash_keys)
    : BasePlan         (PlanType::HASH_JOIN),
      SchemaPlan       (schema),
      MaybePredPlan    (move(pred)),
      // TODO: Instead of providing a Vec<BaseQuery> maybe provice a key schema?
      // A key schema might need to reference the parent schema?
      left_hash_keys_  (move(left_hash_keys)),
      right_hash_keys_ (move(right_hash_keys))
  {
    assert(left_hash_keys_.size() == right_hash_keys_.size());
  }

  // NOTE: These arrays are used to create the key schemas.
  const Vec<BaseQuery>& left_keys()  { return left_hash_keys_; }
  const Vec<BaseQuery>& right_keys() { return right_hash_keys_; }

private:
  Vec<BaseQuery> left_hash_keys_, right_hash_keys_;
};
