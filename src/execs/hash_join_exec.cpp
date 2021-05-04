
#include "execs/hash_join_exec.hpp"
#include "execs/exec_ctx.hpp"
#include "plans/hash_join_plan.hpp"

HashJoinExec::HashJoinExec(ExecCtx& exec_ctx,
                           MovePtr<HashJoinPlan> plan,
                           MovePtr<BaseExec> left,
                           MovePtr<BaseExec> right)
  : BaseExec (exec_ctx),
    plan_    (move(plan)),
    left_    (move(left)),
    right_   (move(right)) {}

// https://github.com/Mrhaha666/15-445_2019fall/blob/42536d7fa034277bf60f78d5124bc0bdc4d69b82/lab3_backup/src/execution/hash_join_executor.cpp#L28

hash_t HashJoinExec::compute_hash(CRef<Tuple> tuple,
                                  CRef<QuerySchema> schema,
                                  Vec<BaseQuery> nodes)
{
  hash_t curr_hash = 0;
  // For every expression,
  for (const auto &node : nodes) {
    // We evaluate the tuple on the expression and schema.
    Value val = node.eval(tuple, schema);
    // If this produces a value,
    if (!val.is_null()) {
      // We combine the hash of that value into our current hash.
      curr_hash = HashUtil::combine_hashes(curr_hash,
                                           HashUtil::hash_value(val));
    }
  }
  return curr_hash;
}

void HashJoinExec::init() {
  left_->init();
  right_->init();

  // First, add all left tuples to the HT.
  while (left_->has_next()) {
    auto left_tuple = left_->next();
    hash_t hash_value = compute_hash(left_tuple, left_schema(),
                                     plan_->left_keys());
    join_ht_.insert(hash_value, left_tuple);
  }

  // Next, do a hash lookup for each right tuple.
  // For every left tuple that matches a right tuple,
  // combine the left & right tuples to make the
  // final output tuple.
  size_t col_total = schema().column_count();
  while (right_->has_next()) {
    auto right_tuple = right_->next();
    hash_t hash_value = compute_hash(right_tuple, right_schema(),
                                     plan_->right_keys());

    // This double for-loop SHOULD be only over a small number of elements.
    // 1. We should usually only match 1 left tuple with 1 right tuple.
    // 2. We should have a small number of columns to combine from the
    //    left and right schemas to produce the final output tuple.
    Vec<Tuple> left_tuples = join_ht_.find_values(hash_value);
    for (auto &left_tuple : left_tuples) {
      if (match_found(left_tuple, right_tuple)) {
        MutVec<Value> values;
        for (size_t col_index = 0; col_index < col_total; ++col_index) {
          values.push_back(make_value_at(col_index,
                                         left_tuple, right_tuple));
        }
        output_tuples_.emplace_back(values, schema());
      }
    }
  }
}

bool HashJoinExec::has_next() {
  return !output_tuples_.empty();
}

Value HashJoinExec::make_value_at(size_t offset,
                                  CRef<Tuple> left,
                                  CRef<Tuple> right)
{
  return schema().by_offset(offset).eval_join(left,  left_schema(),
                                              right, right_schema());
}

bool HashJoinExec::match_found(CRef<Tuple> left, CRef<Tuple> right) {
  auto result = plan_->pred().eval_join(left, left_schema(),
                                        right, right_schema());
  return result.as<bool>();
}

Tuple HashJoinExec::next() {
  auto tuple = output_tuples_.back();
  output_tuples_.pop_back();
  return tuple;
}

CRef<QuerySchema> HashJoinExec::schema() {
  return find_schema(plan_->schema_ref());
}

CRef<QuerySchema> HashJoinExec::left_schema()  {
  return find_schema(left_->schema_ref());
}

CRef<QuerySchema> HashJoinExec::right_schema() {
  return find_schema(right_->schema_ref());
}
