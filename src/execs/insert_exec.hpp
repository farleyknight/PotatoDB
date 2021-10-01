#pragma once

#include "plans/insert_plan.hpp"
#include "execs/base_exec.hpp"

class InsertExec : public BaseExec {
public:
  InsertExec(ExecCtx& exec_ctx,
             ptr<InsertPlan>&& plan,
             ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child))
  {}

  void init() override {
    child_->init();
  }

  bool has_next() override {
    return child_->has_next();
  }

  Tuple
  next_tuple() override;

  ValueMap
  next_value_map() override;

  const string message_on_completion(int32_t result_count) const override {
    return "Inserted " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<InsertPlan> plan_;
  ptr<BaseExec> child_;
};
