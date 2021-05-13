#pragma once

#include "query/query_comp.hpp"

class MaybePredPlan {
public:
  MaybePredPlan() {}

  MaybePredPlan(ptr<QueryComp>&& pred)
    : pred_ (move(pred))
  {}

  bool has_pred() {
    return pred_ != nullptr;
  }

  const QueryComp& pred() {
    assert(pred_);
    return *pred_;
  }

private:
  ptr<QueryComp> pred_;
};
