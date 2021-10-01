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

  void
  init() override {
    child_->init();
  }

  bool
  has_next() override {
    return child_->has_next();
  }

  Tuple
  next_tuple() override {
    auto tuple = child_->next_tuple();
    auto rid   = tuple.rid();

    table_heap().mark_delete(rid, exec_ctx_.txn());

    return tuple;
  }

  ValueMap
  next_value_map() override {
    auto value_map = child_->next_value_map();
    auto rid       = value_map.rid();

    table_heap().mark_delete(rid, exec_ctx_.txn());

    return value_map;
  }

  TableHeap&
  table_heap() {
    auto table_oid = plan_->table_oid();
    return exec_ctx_.schema_mgr().table_heap_for(table_oid);
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Deleted " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<DeletePlan> plan_;
  ptr<BaseExec> child_;
};
