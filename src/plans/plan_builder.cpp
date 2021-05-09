#include "plans/base_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/raw_tuples_plan.hpp"
#include "plans/seq_scan_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"

#include "plans/plan_builder.hpp"

PlanBuilder& PlanBuilder::select(vector<QueryColumn> columns) {
  if (!plan_type_) {
    plan_type_ = PlanType::TABLE_SCAN;
  }

  select_columns_ = columns;
  return *this;
}

PlanBuilder& PlanBuilder::from(QueryTable from_table) {
  from_table_ = make_unique<QueryTable>(from_table);
  return *this;
}

PlanBuilder& PlanBuilder::loop_join(QueryTable right_table) {
  plan_type_ = PlanType::LOOP_JOIN;
  apply_join(right_table);
  return *this;
}

PlanBuilder& PlanBuilder::hash_join(QueryTable right_table) {
  plan_type_ = PlanType::HASH_JOIN;
  apply_join(right_table);
  return *this;
}

void PlanBuilder::apply_join(QueryTable right_table) {
  left_table_  = move(from_table_);
  right_table_ = make_unique<QueryTable>(right_table);
}


PlanBuilder& PlanBuilder::on(QueryColumn left,
                             string op,
                             QueryColumn right)
{
  auto left_col = QueryJoin::make_left(left);
  auto right_col = QueryJoin::make_right(right);

  join_clause_ = make_unique<QueryComp>(move(left_col),
                                        to_comp_type(op),
                                        move(right_col));

  return *this;
}

PlanBuilder& PlanBuilder::insert_into(QueryTable insert_table) {
  insert_table_ = make_unique<QueryTable>(insert_table);
  plan_type_ = PlanType::INSERT;
  return *this;
}

PlanBuilder& PlanBuilder::update(QueryTable update_table) {
  update_table_ = update_table;
  plan_type_ = PlanType::UPDATE;
  return *this;
}

PlanBuilder& PlanBuilder::tuples(RawTuples&& tuples) {
  tuples_ = move(tuples);
  return *this;
}

PlanBuilder& PlanBuilder::delete_from(QueryTable from_table) {
  plan_type_  = PlanType::DELETE;
  from_table_ = make_unique<QueryTable>(from_table);
  return *this;
}

PlanBuilder& PlanBuilder::where(QueryComp clause) {
  where_clause_ = make_unique<QueryComp>(clause);
  return *this;
}

ptr<BasePlan> PlanBuilder::to_plan() {
  switch (plan_type_) {
  case PlanType::TABLE_SCAN:
    return build_scan();
  case PlanType::LOOP_JOIN:
    return build_loop_join();
  case PlanType::UPDATE:
    return build_update(build_scan());
  case PlanType::INSERT:
    if (tuples_.empty()) {
      return build_insert(build_scan());
    } else {
      return build_insert(build_tuples());
    }
  case PlanType::DELETE:
    return build_delete(build_scan());
  default:
    throw Exception("Unimplemented! Need to handle this type in to_plan()");
  }
}

ptr<BasePlan> PlanBuilder::build_tuples() {
  return make_unique<RawTuplesPlan>(insert_table_schema(),
                                    tuples_);
}

PlanBuilder& PlanBuilder::set(QueryColumn column, QueryConst value) {
  update_column_ = column;
  update_value_  = value;
  return *this;
}

ptr<BasePlan> PlanBuilder::build_update(ptr<BasePlan>&& scan_plan) {
  MutMap<column_oid_t, UpdateInfo> update_attrs = {
    {
      update_column_.column_oid(),
      UpdateInfo(UpdateType::SET, update_value_)
    }
  };

  return make_unique<UpdatePlan>(update_table_schema(),
                                 move(scan_plan),
                                 update_table_.table_oid(),
                                 update_attrs);
}

ptr<BasePlan> PlanBuilder::build_insert(ptr<BasePlan>&& scan_plan) {
  return make_unique<InsertPlan>(insert_table_schema(),
                                 insert_table_->table_oid(),
                                 move(scan_plan));
}

ptr<BasePlan> PlanBuilder::build_delete(ptr<BasePlan>&& scan_plan) {
  return make_unique<DeletePlan>(from_table_->table_oid(),
                                 move(scan_plan));
}

ptr<BasePlan> PlanBuilder::build_scan() {
  return make_unique<SeqScanPlan>(from_table_schema(),
                                  from_table_->table_oid(),
                                  move(where_clause_));
}

ptr<BasePlan> PlanBuilder::build_loop_join() {
  auto left_scan = build_left_scan();
  auto right_scan = build_right_scan();

  auto left_schema
    = dynamic_cast<SchemaPlan*>(left_scan.get())->schema();
  auto right_schema
    = dynamic_cast<SchemaPlan*>(right_scan.get())->schema();

  auto join_schema = QuerySchema::merge(left_schema, right_schema);

  // return make_unique<NestedLoopJoinPlan>(move(join_schema),
  return make_unique<NestedLoopJoinPlan>(from_table_schema(),
                                         move(left_scan),
                                         move(right_scan),
                                         move(join_clause_));
}


ptr<BasePlan> PlanBuilder::build_left_scan() {
  vector<string> col_names;
  for (const auto &col : select_columns_) {
    if (col.name().rfind(left_table_name_) == 0) {
      col_names.push_back(col.name());
    }
  }

  auto scan_schema = QuerySchema::slice(left_table_schema(),
                                        col_names);
  return make_unique<SeqScanPlan>(from_table_schema(),
                                  left_table_->table_oid(),
                                  move(where_clause_));
}

ptr<BasePlan> PlanBuilder::build_right_scan() {
  vector<string> col_names;
  for (const auto &col : select_columns_) {
    if (col.name().rfind(right_table_name_) == 0) {
      col_names.push_back(col.name());
    }
  }

  auto scan_schema = QuerySchema::slice(right_table_schema(),
                                        col_names);
  return make_unique<SeqScanPlan>(from_table_schema(),
                                  right_table_->table_oid(),
                                  move(where_clause_));
}

CompType PlanBuilder::to_comp_type(string op) {
  if (op == "<") {
    return CompType::LT;
  } else if (op == ">") {
    return CompType::GT;
  } else if (op == "==") {
    return CompType::EQ;
  }

  // NOTE: Default is equals
  return CompType::EQ;
}

const QuerySchema PlanBuilder::update_table_schema() {
  return catalog_.query_schema_for(update_table_->table_oid());
}

const QuerySchema PlanBuilder::insert_table_schema() {
  return catalog_.query_schema_for(insert_table_->table_oid());
}

const QuerySchema PlanBuilder::from_table_schema() {
  return catalog_.query_schema_for(from_table_->table_oid());
}

const QuerySchema PlanBuilder::right_table_schema() {
  return catalog_.query_schema_for(right_table_->table_oid());
}

const QuerySchema PlanBuilder::left_table_schema() {
  return catalog_.query_schema_for(left_table_->table_oid());
}
