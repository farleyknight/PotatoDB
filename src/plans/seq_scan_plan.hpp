#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"

class SeqScanPlan : public BasePlan {
public:
  SeqScanPlan(SchemaRef schema_ref)
    : BasePlan   (schema_ref),
      table_oid_ (schema_ref.table_oid()) {}

  SeqScanPlan(SchemaRef schema_ref,
              MovePtr<BaseQuery> pred)
    : BasePlan   (schema_ref),
      pred_      (move(pred)),
      table_oid_ (schema_ref.table_oid()) {}

  bool has_pred() {
    return pred_ != nullptr;
  }

  const BaseQuery& pred() {
    assert(pred_);
    return *pred_;
  }

  PlanType type()         const { return PlanType::TABLE_SCAN; }
  table_oid_t table_oid() const { return table_oid_; }

private:
  Ptr<BaseQuery> pred_;
  table_oid_t table_oid_;
};
