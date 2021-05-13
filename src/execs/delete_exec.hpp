#pragma once

#include <memory>

#include "execs/base_exec.hpp"
#include "execs/exec_ctx.hpp"
#include "plans/delete_plan.hpp"

class DeleteExec : public BaseExec {
public:
  DeleteExec(ExecCtx& exec_ctx,
             ptr<DeletePlan>&& plan,
             ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child)) {}

  void init() override {
    // TODO
    child_->init();
  }

  bool has_next() override {
    // TODO
    return false;
  }

  Tuple next() override {
    // TODO
    return Tuple();
  }

  const string message_on_completion(size_t result_count) const override {
    return "Deleted " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<DeletePlan> plan_;
  ptr<BaseExec> child_;
};
