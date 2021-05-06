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
  PlanBuilder(const PlanBuilder&) = delete;
  // No copy assign
  PlanBuilder operator=(const PlanBuilder&) = delete;
  ~PlanBuilder() = default;


  PlanBuilder& insert_into(string name);
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

  ptr<BasePlan> to_plan();

private:
  /**********************************************
   * Private Instance Methods
   **********************************************/

  ptr<BasePlan> build_tuples();
  ptr<BasePlan> build_insert(ptr<BasePlan>&& scan_plan);
  ptr<BasePlan> build_delete(ptr<BasePlan>&& scan_plan);
  // TODO: Need to add build_update in here.
  ptr<BasePlan> build_scan();
  ptr<BasePlan> build_loop_join();
  ptr<BasePlan> build_left_scan();
  ptr<BasePlan> build_right_scan();

  PlanBuilder& loop_join(string right_table);
  PlanBuilder& hash_join(string right_table);

  PlanBuilder& on(QueryColumn left,
                  string op,
                  QueryColumn right);

  void apply_join(string right_table_name);

  const QuerySchema& insert_table_schema();
  const QuerySchema& from_table_schema();
  const QuerySchema& right_table_schema();
  const QuerySchema& left_table_schema();

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

  optional<PlanType> plan_type_;
  ptr<QueryComp> where_clause_;
  ptr<QueryComp> join_clause_;

  Catalog& catalog_;
  RawTuples tuples_;
};
