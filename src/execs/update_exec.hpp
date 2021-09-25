#pragma once

#include "plans/update_plan.hpp"
#include "execs/base_exec.hpp"

class UpdateExec : public BaseExec {
public:
  UpdateExec(ExecCtx& exec_ctx,
             ptr<UpdatePlan>&& plan,
             ptr<BaseExec>&& child);

  void init() override;
  bool has_next() override;
  Tuple next() override;

  const string message_on_completion(int32_t result_count) const override {
    return "Updated " + std::to_string(result_count) + " record(s)";
  }

private:
  Tuple updated_tuple(const Tuple& old_tuple);
  TableHeap& table_heap();

  const QuerySchema&
  schema();
  ptr<UpdatePlan> plan_;
  ptr<BaseExec> child_;
};
