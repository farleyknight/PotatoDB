#pragma once

#include "common/types.hpp"
#include "common/hash_util.hpp"

#include "execs/base_exec.hpp"
#include "plans/hash_join_plan.hpp"
#include "hash/vector_based_hash_table.hpp"

// https://github.com/AlexPeng0829/bustub/blob/88094726d5f34d5baff7e4a777ac135c6bc8fe61/src/execution/hash_join_executor.cpp

class HashJoinExec : public BaseExec {
public:
  HashJoinExec(ExecCtx& exec_ctx,
               MovePtr<HashJoinPlan> plan,
               MovePtr<BaseExec> left,
               MovePtr<BaseExec> right);

  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  hash_t compute_hash(CRef<Tuple> tuple,
                      CRef<QuerySchema> schema,
                      Vec<BaseQuery> nodes);

  bool match_found(CRef<Tuple> left, CRef<Tuple> right);
  Value make_value_at(size_t offset,
                      CRef<Tuple> left,
                      CRef<Tuple> right);

  CRef<QuerySchema> left_schema();
  CRef<QuerySchema> right_schema();
  CRef<QuerySchema> schema();

  vector<Tuple> output_tuples_;

  Ptr<HashJoinPlan> plan_;
  Ptr<BaseExec> left_, right_;
  VectorBasedHT<hash_t, Tuple> join_ht_ {32};
};
