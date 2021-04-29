#pragma once

class DeletePlan : public BasePlan {
public:
  DeletePlan(BasePlan child,
             table_oid_t table_oid)
    : BasePlan   (SchemaRef::from_table_oid(table_oid)),
      table_oid_ (table_oid),
      child_     (child)
  {}

  PlanType type()           const { return PlanType::DELETE; }
  table_oid_t table_oid()   const { return table_oid_; }

private:
  table_oid_t table_oid_;
  BasePlan child_;
};
