#pragma once

#include "execs/base_exec.hpp"
#include "execs/has_child_exec.hpp"

class ProjectionExec : public BaseExec,
                       public HasChildExec
{
public:
  ProjectionExec(ExecCtx& exec_ctx,
                 ptr<ProjectionPlan>&& plan,
                 ptr<BaseExec>&& child)
    : BaseExec     (exec_ctx),
      HasChildExec (move(child)),
      plan_        (move(plan))
  {}

  ~ProjectionExec() = default;

  void init() override {
    child_->init();
  }

  bool
  has_next() override {
    return child_->has_next();
  }

  Tuple
  next_tuple() override {
    auto tuple = child_->next_tuple();
    map<column_oid_t, Value> value_map;
    auto old_schema = dynamic_cast<SeqScanExec*>(child_.get())->schema();
    auto new_schema = plan_->schema();

    for (const auto &col : new_schema.all()) {
      auto value = old_schema.layout().value_by_oid(tuple, col.oid());
      value_map.emplace(col.oid(), value);
    }

    return new_schema.layout().make(value_map, exec_ctx().txn());
  }

  const string message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<ProjectionPlan> plan_;
};

