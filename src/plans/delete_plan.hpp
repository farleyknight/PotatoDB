#pragma once

class DeletePlan : public BasePlan {
public:
  DeletePlan(SchemaRef schema,
             ptr<BasePlan>&& child)
    : BasePlan   (schema),
      child_     (move(child)),
      table_oid_ (schema.table_oid())
  {}

  PlanType type()           const { return PlanType::DELETE; }
  table_oid_t table_oid()   const { return table_oid_; }
  ptr<BasePlan>&& child()       { return move(child_); }

private:
  ptr<BasePlan> child_;
  table_oid_t table_oid_;
};
