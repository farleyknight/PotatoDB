#pragma once

#include "common/config.hpp"

#include "catalog/catalog.hpp"
#include "catalog/query_table.hpp"

#include "query/query_comp.hpp"
#include "query/query_column.hpp"
#include "query/query_const.hpp"

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

  PlanBuilder& insert_into(QueryTable insert_table);
  PlanBuilder& tuples(RawTuples&& tuples);

  PlanBuilder& select(vector<QueryColumn> columns);
  PlanBuilder& from(QueryTable table);
  PlanBuilder& join(QueryTable table);
  PlanBuilder& on(string left_name,
                  string op,
                  string right_name);

  PlanBuilder& delete_from(QueryTable name);

  PlanBuilder& where(QueryComp comp);

  ptr<BasePlan> to_plan();

private:
  ptr<BasePlan> build_tuples();
  ptr<BasePlan> build_insert(ptr<BasePlan>&& scan_plan);
  ptr<BasePlan> build_delete(ptr<BasePlan>&& scan_plan);
  // TODO: Need to add build_update in here.
  ptr<BasePlan> build_scan();
  ptr<BasePlan> build_loop_join();
  ptr<BasePlan> build_left_scan();
  ptr<BasePlan> build_right_scan();

  PlanBuilder& loop_join(QueryTable right_table);
  PlanBuilder& hash_join(QueryTable right_table);

  PlanBuilder& on(QueryColumn left,
                  string op,
                  QueryColumn right);

  void apply_join(QueryTable right_table);

  const QuerySchema insert_table_schema();
  const QuerySchema from_table_schema();
  const QuerySchema right_table_schema();
  const QuerySchema left_table_schema();

  CompType to_comp_type(string op);

  vector<QueryColumn> select_columns_;
  vector<QueryColumn> insert_columns_;

  ptr<QueryTable> from_table_;
  ptr<QueryTable> insert_table_;
  ptr<QueryTable> left_table_;
  ptr<QueryTable> right_table_;

  optional<PlanType> plan_type_;

  ptr<QueryComp> where_clause_;
  ptr<QueryComp> join_clause_;

  Catalog& catalog_;
  RawTuples tuples_;
};
