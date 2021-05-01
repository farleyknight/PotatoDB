#pragma once

class DeletePlan : public BasePlan {
public:
  DeletePlan(SchemaRef schema,
             MovePtr<BasePlan> child)
    : BasePlan   (schema),
      child_     (move(child)),
      table_oid_ (schema.table_oid())
  {}

  PlanType type()           const { return PlanType::DELETE; }
  table_oid_t table_oid()   const { return table_oid_; }
  MovePtr<BasePlan> child()       { return move(child_); }

private:
  MutPtr<BasePlan> child_;
  table_oid_t table_oid_;
};
