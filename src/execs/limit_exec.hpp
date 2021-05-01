#pragma once

#include "plans/limit_plan.hpp"

class LimitExec : public BaseExec {
 public:

  LimitExec(ExecCtx& exec_ctx,
            MovePtr<LimitPlan> plan,
            MovePtr<BaseExec> child)
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

private:
  Ptr<LimitPlan> plan_;
  Ptr<BaseExec> child_;
};
