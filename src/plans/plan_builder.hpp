#pragma once

#include "common/config.hpp"

#include "catalog/catalog.hpp"

#include "query/query_comp.hpp"
#include "query/query_column.hpp"
#include "query/query_const.hpp"
#include "query/query_table.hpp"

#include "plans/base_plan.hpp"
#include "plans/raw_tuples_plan.hpp"

class PlanBuilder {
public:
  PlanBuilder(Catalog& catalog)
    : catalog_(catalog) {}

  // No copy
  PlanBuilder(CRef<PlanBuilder>) = delete;
  // No copy assign
  PlanBuilder operator=(CRef<PlanBuilder>) = delete;
  ~PlanBuilder() = default;


  PlanBuilder& insert_into(String name);
  PlanBuilder& tuples(Move<RawTuples> tuples);

  PlanBuilder& select(vector<string> names);
  PlanBuilder& from(string name);
  PlanBuilder& join(string name);
  PlanBuilder& on(string left_name,
                  string op,
                  string right_name);

  PlanBuilder& delete_from(string name);

  PlanBuilder& where(string name,
                     string op,
                     int val);
  PlanBuilder& where(string name,
                     string operation,
                     Value val);

  MutPtr<BasePlan> to_plan();

private:
  /**********************************************
   * Private Instance Methods
   **********************************************/

  MutPtr<BasePlan> build_tuples();
  MutPtr<BasePlan> build_insert(MovePtr<BasePlan> scan_plan);
  MutPtr<BasePlan> build_delete(MovePtr<BasePlan> scan_plan);
  // TODO: Need to add build_update in here.
  MutPtr<BasePlan> build_scan();
  MutPtr<BasePlan> build_loop_join();
  MutPtr<BasePlan> build_left_scan();
  MutPtr<BasePlan> build_right_scan();

  PlanBuilder& loop_join(string right_table);
  PlanBuilder& hash_join(string right_table);

  PlanBuilder& on(QueryColumn left,
                  string op,
                  QueryColumn right);

  void apply_join(string right_table_name);

  SchemaRef insert_table_schema_ref();
  CRef<QuerySchema> insert_table_schema();

  SchemaRef from_table_schema_ref();
  CRef<QuerySchema> from_table_schema();
  CRef<QuerySchema> right_table_schema();
  CRef<QuerySchema> left_table_schema();

  CompType to_comp_type(string op);

  vector<string> select_column_names_;
  vector<string> insert_column_names_;

  string from_table_name_;
  string insert_table_name_;

  table_oid_t from_table_oid_   = INVALID_TABLE_OID;
  table_oid_t insert_table_oid_ = INVALID_TABLE_OID;

  string left_table_name_;
  string right_table_name_;

  table_oid_t left_table_oid_  = INVALID_TABLE_OID;
  table_oid_t right_table_oid_ = INVALID_TABLE_OID;

  MutOption<PlanType> plan_type_;
  MutPtr<QueryComp> where_clause_;
  MutPtr<QueryComp> join_clause_;

  Catalog& catalog_;
  RawTuples tuples_;
};
