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
  const Value& value() const { return value_; }

private:
  UpdateType type_;
  Value value_;
};


/**********************************************
 * UpdatePlan
 **********************************************/

class UpdatePlan : public BasePlan {
public:
  UpdatePlan(SchemaRef schema_ref,
             ptr<BasePlan>&& child,
             Move<MutMap<uint32_t, UpdateInfo>> update_attrs)
    : BasePlan      (schema_ref),
      table_oid_    (schema_ref.table_oid()),
      child_        (move(child)),
      // NOTE: The update attrs vector could be huge!
      // TODO: Write performance tests where this parameter is huge
      update_attrs_ (update_attrs) {}

  /**********************************************
   * Instance methods
   **********************************************/

  PlanType type()         const { return PlanType::UPDATE; }
  table_oid_t table_oid() const { return table_oid_; }
  ptr<BasePlan>&& child()     { return move(child_); }

  const Map<uint32_t, UpdateInfo>& update_attrs() const {
    return update_attrs_;
  }

private:
  table_oid_t table_oid_;
  ptr<BasePlan> child_;
  Map<uint32_t, UpdateInfo> update_attrs_;
};
