#pragma once

#include "plans/limit_plan.hpp"

class LimitExec : public BaseExec {
 public:

  LimitExec(MRef<ExecCtx> exec_ctx,
            MovePtr<LimitPlan> plan,
            MovePtr<BaseExec> child)
    : BaseExec (exec_ctx),
      plan_    (std::move(plan)),
      child_   (std::move(child)) {}

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
                            MovePtr<LimitPlan> plan,
                            MovePtr<BaseExec> child)
  {
    return make_unique<LimitExec>(exec_ctx,
                                  move(plan),
                                  move(child));
  }

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
  /** The limit plan node to be executed. */
  Ptr<LimitPlan> plan_;
  Ptr<BaseExec> child_;
};
