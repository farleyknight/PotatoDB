#pragma once

#include "query/base_query.hpp"

class MaybePredPlan {
public:
  MaybePredPlan()
  {}

  MaybePredPlan(ptr<BaseQuery>&& pred)
    : pred_ (move(pred))
  {}

  bool has_pred() {
    return pred_ != nullptr;
  }

  const BaseQuery& pred() {
    assert(pred_);
    return *pred_;
  }

private:
  ptr<BaseQuery> pred_;
};
