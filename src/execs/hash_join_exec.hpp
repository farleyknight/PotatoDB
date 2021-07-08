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
               ptr<HashJoinPlan>&& plan,
               ptr<BaseExec>&& left,
               ptr<BaseExec>&& right);

  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  hash_t compute_hash(const Tuple& tuple,
                      const QuerySchema& schema,
                      Vec<BaseQuery> nodes);

  bool match_found(const Tuple& left,
                   const Tuple& right);
  Value make_value_at(column_index_t index,
                      const Tuple& left,
                      const Tuple& right);

  const QuerySchema& left_schema();
  const QuerySchema& right_schema();
  const QuerySchema& schema();

  vector<Tuple> output_tuples_;

  ptr<HashJoinPlan> plan_;
  ptr<BaseExec> left_, right_;
  VectorBasedHT<hash_t, Tuple> join_ht_ {32};
};
