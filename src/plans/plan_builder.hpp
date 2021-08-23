#pragma once

#include "common/config.hpp"

#include "catalog/catalog.hpp"
#include "catalog/query_table.hpp"

#include "query/query_where.hpp"
#include "query/query_column.hpp"
#include "query/query_const.hpp"

#include "plans/base_plan.hpp"
#include "plans/raw_tuples_plan.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/show_tables_expr.hpp"

// TODO: This whole class is deprecated!
class PlanBuilder {
public:
  PlanBuilder(const Catalog& catalog)
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

  PlanBuilder& update(QueryTable table);
  PlanBuilder& set(QueryColumn column, Value value);

  PlanBuilder& delete_from(QueryTable table);

  PlanBuilder& where(ptr<QueryComp>&& comp);

  ptr<BasePlan> to_plan();

private:
  ptr<BasePlan> build_tuples();
  ptr<BasePlan> build_insert(ptr<BasePlan>&& scan_plan);
  ptr<BasePlan> build_delete(ptr<BasePlan>&& scan_plan);
  ptr<BasePlan> build_update(ptr<BasePlan>&& scan_plan);
  ptr<BasePlan> build_scan();
  ptr<BasePlan> build_loop_join();
  ptr<BasePlan> build_left_scan();
  ptr<BasePlan> build_right_scan();

  PlanBuilder& loop_join(QueryTable right_table);
  PlanBuilder& hash_join(QueryTable right_table);

  PlanBuilder& on(QueryColumn left,
                  QueryColumn right);

  void apply_join(QueryTable right_table);


  vector<QueryColumn> select_columns_;
  vector<QueryColumn> insert_columns_;

  // TODO: The syntax allows for multiple set pairs:
  //
  // UPDATE table_name
  // SET column1 = value1, column2 = value2, ...
  // WHERE condition;
  //
  // Therefore we get both of these vectors:
  vector<QueryColumn> update_columns_;
  vector<Value>  update_values_;

  // TODO: Instead of having 5 of these things,
  // let's just make a MutMap<PlanType, QueryTable>
  //
  // That way we can handle each plan type we need,
  // which should usually be a small number.
  ptr<QueryTable> from_table_;
  ptr<QueryTable> insert_table_;
  ptr<QueryTable> left_table_;
  ptr<QueryTable> right_table_;
  ptr<QueryTable> update_table_;

  const QuerySchema update_table_schema();
  const QuerySchema insert_table_schema();
  const QuerySchema from_table_schema();
  const QuerySchema right_table_schema();
  const QuerySchema left_table_schema();

  PlanType plan_type_ = PlanType::INVALID;

  ptr<QueryWhere> where_clause_;
  ptr<QueryWhere> join_clause_;

  const Catalog& catalog_;
  RawTuples tuples_;
};
