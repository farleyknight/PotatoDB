#pragma once

#include <optional>

#include "common/config.hpp"
#include "plans/base_plan.hpp"

class SeqScanPlan : public BasePlan {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  SeqScanPlan(SchemaRef schema_ref,
              table_oid_t table_oid)
    : BasePlan   (schema_ref),
      table_oid_ (table_oid) {}

  SeqScanPlan(SchemaRef schema_ref,
              MovePtr<BaseQuery> pred,
              table_oid_t table_oid)
    : BasePlan   (schema_ref),
      pred_      (move(pred)),
      table_oid_ (table_oid) {}

  /**********************************************
   * Instance methods
   **********************************************/

  bool has_pred() {
    return pred_ != nullptr;
  }

  CRef<BaseQuery> pred() {
    assert(pred_);
    return *pred_;
  }

  PlanType type()         const { return PlanType::TABLE_SCAN; }
  table_oid_t table_oid() const { return table_oid_; }

private:
  Ptr<BaseQuery> pred_;
  table_oid_t table_oid_;
};
