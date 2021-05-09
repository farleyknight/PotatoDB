#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/schema_plan.hpp"
#include "plans/has_child_plan.hpp"

/**********************************************
 * UpdateType
 **********************************************/

enum class UpdateType {
  ADD = 1,
  SET = 2
};

/**********************************************
 * UpdateInfo
 **********************************************/

class UpdateInfo {
public:
  UpdateInfo(UpdateType type, Value value)
    : type_  (type),
      value_ (value) {}

  UpdateType type()    const { return type_; }
  const Value& value() const { return value_; }

private:
  UpdateType type_;
  Value value_;
};

/**********************************************
 * UpdatePlan
 **********************************************/

class UpdatePlan : public BasePlan,
                   public TablePlan,
                   public SchemaPlan,
                   public HasChildPlan
{
public:
  UpdatePlan(QuerySchema schema,
             table_oid_t table_oid,
             ptr<BasePlan>&& child,
             map<column_oid_t, UpdateInfo>&& update_attrs)
    : BasePlan      (PlanType::UPDATE),
      TablePlan     (table_oid),
      SchemaPlan    (schema),
      HasChildPlan  (move(child)),
      update_attrs_ (move(update_attrs))
  {}

  const map<column_oid_t, UpdateInfo>& update_attrs() const {
    return update_attrs_;
  }

private:
  map<column_oid_t, UpdateInfo> update_attrs_;
};
