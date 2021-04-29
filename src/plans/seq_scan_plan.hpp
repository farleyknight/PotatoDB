#pragma once

#include <optional>

#include "common/config.hpp"
#include "exprs/const_expr.hpp"
#include "plans/base_plan.hpp"

class SeqScanPlan : public BasePlan {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  SeqScanPlan(MovePtr<Schema> output,
              table_oid_t table_oid)
    : BasePlan   (move(output)),
      table_oid_ (table_oid) {}

  SeqScanPlan(MovePtr<Schema> output,
              MovePtr<BaseExpr> pred,
              table_oid_t table_oid)
    : BasePlan   (move(output)),
      pred_      (move(pred)),
      table_oid_ (table_oid) {}

  /**********************************************
   * Instance methods
   **********************************************/

  bool has_pred() {
    return pred_ != nullptr;
  }

  Ref<BaseExpr> pred() {
    assert(pred_);
    return *pred_;
  }

  PlanType type()         const override { return PlanType::SEQ_SCAN; }
  table_oid_t table_oid() const          { return table_oid_; }

private:
  Option<BaseExpr> pred_;
  table_oid_t table_oid_;
};
