#include "plans/base_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/raw_tuples_plan.hpp"
#include "plans/seq_scan_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"

#include "plans/plan_builder.hpp"

PlanBuilder& PlanBuilder::select(vector<string> names) {
  if (!plan_type_) {
    plan_type_ = PlanType::TABLE_SCAN;
  }

  select_column_names_ = names;
  return *this;
}

PlanBuilder& PlanBuilder::from(string from_table) {
  from_table_name_ = from_table;
  return *this;
}

PlanBuilder& PlanBuilder::loop_join(string right_table) {
  plan_type_ = PlanType::LOOP_JOIN;
  apply_join(right_table);
  return *this;
}

PlanBuilder& PlanBuilder::hash_join(string right_table) {
  plan_type_ = PlanType::HASH_JOIN;
  apply_join(right_table);
  return *this;
}

void PlanBuilder::apply_join(string right_table_name) {
  left_table_name_  = from_table_name_;
  // left_table_oid_  = left_table.oid();

  right_table_name_ = right_table_name;
  // right_table_oid_ = right_table.oid();
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

PlanBuilder& PlanBuilder::insert_into(string name) {
  insert_table_name_ = name;
  insert_table_oid_ = catalog_.table_oid_for(name);
  plan_type_ = PlanType::INSERT;
  return *this;
}

PlanBuilder& PlanBuilder::tuples(Move<RawTuples> tuples) {
  tuples_ = move(tuples);
  return *this;
}

PlanBuilder& PlanBuilder::delete_from(string name) {
  plan_type_ = PlanType::DELETE;
  from_table_name_ = name;
  from_table_oid_  = catalog_.table_oid_for(name);
  return *this;
}

PlanBuilder& PlanBuilder::where(string name,
                                string op,
                                int val) {
  auto const_val = Value::make<int>(val);
  return where(move(name), op, move(const_val));
}

PlanBuilder& PlanBuilder::where(string column_name,
                                string op,
                                Value value) {

  auto &query_schema = from_table_schema();
  auto column        = query_schema.by_name(column_name);

  auto constant = QueryConst(value);
  auto clause   = make_unique<QueryComp>(column,
                                         to_comp_type(op),
                                         constant);

  where_clause_ = move(clause);

  return *this;
}

ptr<BasePlan> PlanBuilder::to_plan() {
  if (plan_type_ == PlanType::TABLE_SCAN) {
    return build_scan();
  } else if (plan_type_ == PlanType::LOOP_JOIN) {
    return build_loop_join();
  } else if (plan_type_ == PlanType::INSERT) {
    if (tuples_.empty()) {
      return build_insert(build_scan());
    } else {
      return build_insert(build_tuples());
    }
  } else if (plan_type_ == PlanType::DELETE) {
    return build_delete(build_scan());
  } else {
    throw Exception("Unimplemented! Need to handle this type in to_plan()");
  }
}

ptr<BasePlan> PlanBuilder::build_tuples() {
  return make_unique<RawTuplesPlan>(insert_table_schema(),
                                    tuples_);
}

ptr<BasePlan> PlanBuilder::build_insert(ptr<BasePlan>&& scan_plan) {
  return make_unique<InsertPlan>(insert_table_schema(),
                                 insert_table_oid_,
                                 move(scan_plan));
}

ptr<BasePlan> PlanBuilder::build_delete(ptr<BasePlan>&& scan_plan) {
  return make_unique<DeletePlan>(from_table_oid_,
                                 move(scan_plan));
}

ptr<BasePlan> PlanBuilder::build_scan() {
  if (where_clause_) {
    return make_unique<SeqScanPlan>(from_table_schema(),
                                    from_table_oid_,
                                    move(where_clause_)
                                    );
  } else {
    return make_unique<SeqScanPlan>(from_table_schema(),
                                    from_table_oid_
                                    );
  }
}

ptr<BasePlan> PlanBuilder::build_loop_join() {
  auto left_scan = build_left_scan();
  auto right_scan = build_right_scan();

  auto left_schema  = dynamic_cast<SchemaPlan*>(left_scan.get())->schema();
  auto right_schema = dynamic_cast<SchemaPlan*>(right_scan.get())->schema();

  auto join_schema = QuerySchema::merge(left_schema, right_schema);

  // return make_unique<NestedLoopJoinPlan>(move(join_schema),
  return make_unique<NestedLoopJoinPlan>(from_table_schema(),
                                         move(left_scan),
                                         move(right_scan),
                                         move(join_clause_));
}


ptr<BasePlan> PlanBuilder::build_left_scan() {
  vector<string> col_names;
  for (auto name : select_column_names_) {
    if (name.rfind(left_table_name_) == 0) {
      col_names.push_back(name);
    }
  }

  auto scan_schema = QuerySchema::slice(left_table_schema(),
                                        col_names);
  return make_unique<SeqScanPlan>(from_table_schema(),
                                  left_table_oid_
                                  );
}

ptr<BasePlan> PlanBuilder::build_right_scan() {
  vector<string> col_names;
  for (auto name : select_column_names_) {
    if (name.rfind(right_table_name_) == 0) {
      col_names.push_back(name);
    }
  }

  auto scan_schema = QuerySchema::slice(right_table_schema(),
                                        col_names);
  return make_unique<SeqScanPlan>(from_table_schema(),
                                  right_table_oid_
                                  );
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

const QuerySchema& PlanBuilder::insert_table_schema() {
  return catalog_.find_query_schema(insert_table_oid_);
}

const QuerySchema& PlanBuilder::from_table_schema() {
  return catalog_.find_query_schema(from_table_oid_);
}

const QuerySchema& PlanBuilder::right_table_schema() {
  return catalog_.find_query_schema(right_table_oid_);
}

const QuerySchema& PlanBuilder::left_table_schema() {
  return catalog_.find_query_schema(left_table_oid_);
}
