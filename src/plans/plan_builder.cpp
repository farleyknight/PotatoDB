#include "plans/base_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/update_plan.hpp"
#include "plans/raw_tuples_plan.hpp"
#include "plans/seq_scan_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"
#include "plans/create_table_plan.hpp"

#include "plans/plan_builder.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/insert_expr.hpp"

#include "server/system_catalog.hpp"

PlanBuilder& PlanBuilder::select(vector<QueryColumn> columns) {
  if (plan_type_ == PlanType::INVALID) {
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
                             QueryColumn right)
{
  // TODO: The schema needs to be updated somehow?
  // I recall we added a vector to QuerySchema called `joins`
  // The left & right join tables should be added to the
  // QuerySchema somehow in this method.

  auto left_col = QueryJoin::make_left(left);
  auto right_col = QueryJoin::make_right(right);

  auto comp = make_unique<QueryComp>(move(left_col),
                                     CompareType::EQ,
                                     move(right_col));

  join_clause_ = make_unique<QueryWhere>(move(comp));
  return *this;
}

PlanBuilder& PlanBuilder::insert_into(QueryTable table) {
  insert_table_ = make_unique<QueryTable>(table);
  plan_type_ = PlanType::INSERT;
  return *this;
}

PlanBuilder& PlanBuilder::update(QueryTable table) {
  update_table_ = make_unique<QueryTable>(table);
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

PlanBuilder& PlanBuilder::where(ptr<QueryComp>&& comp) {
  where_clause_ = make_unique<QueryWhere>(move(comp));
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

PlanBuilder& PlanBuilder::set(QueryColumn column, Value value) {
  update_columns_.push_back(column);
  update_values_.push_back(value);
  return *this;
}

ptr<BasePlan> PlanBuilder::build_update(ptr<BasePlan>&& scan_plan) {
  MutMap<column_oid_t, UpdateInfo> update_attrs;

  for (index_t i = 0; i < update_columns_.size(); ++i) {
    update_attrs.emplace(update_columns_[i].column_oid(),
                         UpdateInfo(UpdateType::SET, update_values_[i]));
  }

  return make_unique<UpdatePlan>(update_table_schema(),
                                 update_table_->table_oid(),
                                 move(scan_plan),
                                 move(update_attrs));
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

  // TODO We should be adding the two join columns here!
  // Check the `QuerySchema::on` method.
  // TODO: Rename `QuerySchema::merge` to `QuerySchema::join`
  auto join_schema = QuerySchema::merge(left_schema, right_schema);

  // return make_unique<NestedLoopJoinPlan>(move(join_schema),
  return make_unique<NestedLoopJoinPlan>(from_table_schema(),
                                         move(left_scan),
                                         move(right_scan),
                                         move(join_clause_));
}


ptr<BasePlan> PlanBuilder::build_left_scan() {
  vector<QueryColumn> cols;
  for (const auto &col : select_columns_) {
    if (col.table_oid() == left_table_->table_oid()) {
      cols.push_back(col);
    }
  }

  auto scan_schema = QuerySchema(cols);
  return make_unique<SeqScanPlan>(scan_schema,
                                  left_table_->table_oid(),
                                  move(where_clause_));
}

ptr<BasePlan> PlanBuilder::build_right_scan() {
  vector<QueryColumn> cols;
  for (const auto &col : select_columns_) {
    if (col.table_oid() == right_table_->table_oid()) {
      cols.push_back(col);
    }
  }

  auto scan_schema = QuerySchema(cols);
  return make_unique<SeqScanPlan>(scan_schema,
                                  right_table_->table_oid(),
                                  move(where_clause_));
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
