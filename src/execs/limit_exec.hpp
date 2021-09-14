#pragma once

#include "plans/limit_plan.hpp"

class LimitExec : public BaseExec {
 public:

  LimitExec(ExecCtx& exec_ctx,
            ptr<LimitPlan>&& plan,
            ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child))
  {}

  void init() override {
    child_->init();
    // TODO
  }

  bool has_next() override {
    return false;
  }

  Tuple next() override {
    // TODO
    return Tuple();
  }

  const string message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<LimitPlan> plan_;
  ptr<BaseExec> child_;
};
