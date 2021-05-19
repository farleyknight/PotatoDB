#pragma once

#include "query/query_where.hpp"

class MaybePredPlan {
public:
  MaybePredPlan() {}

  MaybePredPlan(ptr<QueryWhere>&& pred)
    : pred_ (move(pred))
  {}

  bool has_pred() {
    return pred_ != nullptr;
  }

  const QueryWhere& pred() {
    assert(pred_);
    return *pred_;
  }

private:
  ptr<QueryWhere> pred_;
};
