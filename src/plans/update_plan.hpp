#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"

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

  UpdateType type()   const { return type_; }
  CRef<Value> value() const { return value_; }

private:
  UpdateType type_;
  Value value_;
};


/**********************************************
 * UpdatePlan
 **********************************************/

class UpdatePlan : public BasePlan {
public:
  UpdatePlan(BasePlan child,
             table_oid_t table_oid,
             Move<MutMap<uint32_t, UpdateInfo>> update_attrs)
    : BasePlan      (SchemaRef::from_table_oid(table_oid)),
      table_oid_    (table_oid),
      child_        (child),
      // NOTE: The update attrs vector could be huge!
      // TODO: Write performance tests where this parameter is huge
      update_attrs_ (update_attrs) {}

  /**********************************************
   * Instance methods
   **********************************************/

  PlanType type()                const { return PlanType::UPDATE; }
  table_oid_t table_oid()        const { return table_oid_; }

  CRef<Map<uint32_t, UpdateInfo>> update_attrs() const {
    return update_attrs_;
  }

private:
  table_oid_t table_oid_;
  BasePlan child_;
  Map<uint32_t, UpdateInfo> update_attrs_;
};
