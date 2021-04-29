#pragma once

#include "common/config.hpp"

#include "catalog/catalog.hpp"

#include "exprs/comp_expr.hpp"
#include "exprs/column_expr.hpp"
#include "exprs/const_expr.hpp"

#include "plans/base_plan.hpp"
#include "plans/raw_values_plan.hpp"

class PlanBuilder {
public:
  using Self = MutRef<PlanBuilder>;

  /**********************************************
   * PB : Constructors & destructor
   * - DSL for building queries
   **********************************************/

  PB(MutRef<Catalog> catalog)
    : catalog_(catalog) {}

  // No copy
  PlanBuilder(Ref<PlanBuilder>) = delete;
  // No copy assign
  Self operator=(Ref<PlanBuilder>) = delete;
  ~PB() = default;

  static Ptr<PlanBuilder> make(MutRef<Catalog> catalog) {
    return make_unique<PB>(catalog);
  }

  /**********************************************
   * DSL Methods
   **********************************************/

  Self insert_into(String name);
  Self values(Move<RawValueSet> values);

  Self select(Vec<String> names);
  Self from(String name);
  Self join(String name);
  Self on(String left_name,
          String op,
          String right_name);

  Self delete_from(String name);

  Self where(Move<String> name,
             String op,
             int val);
  Self where(Move<String> name,
             String operation,
             Move<Value> val);

  MutPtr<BasePlan> to_plan();

private:
  /**********************************************
   * Private Instance Methods
   **********************************************/

  MutPtr<BasePlan> build_values();
  MutPtr<BasePlan> build_insert(MovePtr<BasePlan> scan_plan);
  MutPtr<BasePlan> build_delete(MovePtr<BasePlan> scan_plan);
  // TODO: Need to add build_update in here.
  MutPtr<BasePlan> build_scan();
  MutPtr<BasePlan> build_loop_join();
  MutPtr<BasePlan> build_loop_join();
  MutPtr<BasePlan> build_left_scan();
  MutPtr<BasePlan> build_right_scan();

  void apply_join(QueryTable right_table);

  Ref<Schema> insert_table_schema();

  Ref<Schema> from_table_schema();

  Ref<Schema> right_table_schema();
  Ref<Schema> left_table_schema();

  CompType to_comp_type(String op);

  MutVec<ColumnExpr> select_column_names_;
  MutVec<ColumnExpr> insert_column_names_;

  MutString from_table_name_;
  MutString insert_table_name_;

  table_oid_t from_table_oid_   = INVALID_TABLE_OID;
  table_oid_t insert_table_oid_ = INVALID_TABLE_OID;

  MutString left_table_name_;
  MutString right_table_name_;

  table_oid_t left_table_oid_  = INVALID_TABLE_OID;
  table_oid_t right_table_oid_ = INVALID_TABLE_OID;

  MutOption<PlanType> plan_type_;
  MutPtr<CompExpr> where_clause_;
  MutPtr<CompExpr> join_clause_;

  MutRef<Catalog> catalog_;
  RawValueSet values_;
};
