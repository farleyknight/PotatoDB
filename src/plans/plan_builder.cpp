#include "plans/base_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/raw_values_plan.hpp"
#include "plans/seq_scan_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"

#include "plans/plan_builder.hpp"

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::select(Vec<ColumnExpr> cols) {
  if (!plan_type_) {
    plan_type_ = PlanType::SEQ_SCAN;
  }

  select_cols_ = cols;
  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::from(QueryTable from_table) {
  from_table_     = from_table;
  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::loop_join(QueryTable right_table) {
  plan_type_ = PlanType::LOOP_JOIN;
  apply_join(right_table);
  return *this;
}

MutRef<PB> PB::hash_join(QueryTable right_table) {
  plan_type_ = PlanType::HASH_JOIN;
  apply_join(right_table);
  return *this;
}

void PB::apply_join(QueryTable right_table) {
  left_table_      = from_table_;
  left_table_oid_  = left_table.oid();

  right_table_     = right_table;
  right_table_oid_ = right_table.oid();
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::on(ColumnExpr left, String op, ColumnExpr right) {
  auto left_col = JoinExpr::make_left(left);
  auto right_col = JoinExpr::make_right(right);

  auto clause = CompExpr::make(move(left_col),
                               to_comp_type(op),
                               move(right_col));

  join_clause_ = clause;

  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::insert_into(String name) {
  insert_table_name_ = name;
  insert_table_oid_ = catalog_.table_oid_for(name);
  plan_type_ = PlanType::INSERT;
  return *this;
}

/**********************************************
 * values - Provide raw values for an INSERT
 **********************************************/

MutRef<PB> PB::values(Move<RawValueSet> values) {
  values_ = move(values);
  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::delete_from(String name) {
  plan_type_ = PlanType::DELETE;
  from_table_name_ = name;
  from_table_oid_  = catalog_.table_oid_for(name);
  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutRef<PB> PB::where(Move<String> name, String op, int val) {
  auto const_val = Value::make<int>(val);
  return where(move(name), op, move(const_val));
}

MutRef<PB> PB::where(Move<String> column_name, String op, Move<Value> val) {
  auto column_expr = ColumnExpr::make(from_table_schema(),
                                      move(column_name));
  auto const_expr  = ConstExpr::make(move(val));
  auto clause      = CompExpr::make(move(column_expr),
                                    to_comp_type(op),
                                    move(const_expr));

  // where_clause_.reset(clause.release());
  where_clause_ = move(clause);

  return *this;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::to_plan() {
  if (plan_type_ == PlanType::SEQ_SCAN) {
    return build_scan();
  } else if (plan_type_ == PlanType::LOOP_JOIN) {
    return build_join();
  } else if (plan_type_ == PlanType::INSERT) {
    if (values_.empty()) {
      return build_insert(move(build_scan()));
    } else {
      return build_insert(move(build_values()));
    }
  } else if (plan_type_ == PlanType::DELETE) {
    return build_delete(build_scan());
  } else {
    throw Exception("Unimplemented! Need to handle this type in to_plan()");
  }
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_values() {
  auto values_schema = Schema::copy(insert_table_schema());
  auto values_plan = RawValuesPlan::make(move(values_schema),
                                         move(values_));
  return values_plan;
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_insert(MovePtr<BasePlan> scan_plan) {
  auto insert_schema = Schema::slice(insert_table_schema(),
                                     insert_column_names_);
  return InsertPlan::make(move(insert_schema),
                          move(scan_plan),
                          insert_table_oid_);
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_delete(MovePtr<BasePlan> scan_plan) {
  auto delete_schema = Schema::copy(from_table_schema());
  return DeletePlan::make(move(delete_schema),
                          move(scan_plan),
                          from_table_oid_);
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_scan() {
  auto scan_schema = Schema::slice(from_table_schema(),
                                   select_column_names_);
  if (where_clause_) {
    return SeqScanPlan::make(move(scan_schema),
                             move(where_clause_),
                             from_table_oid_);
  } else {
    return SeqScanPlan::make(move(scan_schema),
                             from_table_oid_);
  }
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_loop_join() {
  auto left_scan = build_left_scan();
  auto right_scan = build_right_scan();
  auto join_schema = Schema::merge(left_scan->schema(),
                                   right_scan->schema());

  return NestedLoopJoinPlan::make(move(join_schema),
                                  move(left_scan),
                                  move(right_scan),
                                  move(join_clause_));
}


/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_left_scan() {
  MutVec<String> col_names;
  for (Ref<String> name : select_column_names_) {
    if (name.rfind(left_table_name_) == 0) {
      col_names.push_back(name);
    }
  }

  // NOTE: Why do I have to do this? Can't the C++ compiler
  // infer how to convert a vec of mut strings to const strings?
  // MutVec<String> const_col_names = std::copy(col_names);

  auto scan_schema = Schema::slice(left_table_schema(),
                                   col_names);
  return SeqScanPlan::make(move(scan_schema),
                           left_table_oid_);
}

/**********************************************
 * TODO: Document me
 **********************************************/

MutPtr<BasePlan> PB::build_right_scan() {
  MutVec<String> col_names;
  for (Ref<String> name : select_column_names_) {
    if (name.rfind(right_table_name_) == 0) {
      col_names.push_back(name);
    }
  }

  auto scan_schema = Schema::slice(right_table_schema(),
                                   col_names);
  return SeqScanPlan::make(move(scan_schema),
                           right_table_oid_);
}

/**********************************************
 * TODO: Document me
 **********************************************/

CompType PB::to_comp_type(String op) {
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

Ref<TableSchema> PB::insert_table_schema() {
  return catalog_.table_schema_for(insert_table_oid_);
}

Ref<Schema> PB::from_table_schema() {
  return catalog_.table_schema_for(from_table_oid_);
}

Ref<TableSchema> PB::right_table_schema() {
  return catalog_.table_schema_for(right_table_oid_);
}

Ref<TableSchema> PB::left_table_schema() {
  return catalog_.table_schema_for(left_table_oid_);
}
