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

  bool has_next() override {
    return child_->has_next();
  }

  Tuple next() override {
    auto tuple = child_->next();
    vector<Value> vals;
    auto old_schema = dynamic_cast<SeqScanExec*>(child_.get())->schema();
    auto new_schema = plan_->schema();

    for (const auto &col : new_schema.all()) {
      // TODO: Let's eliminate `value_by_name` completely from
      // the codebase. I want to discourage using strings to
      // identify things, moving towards a global table of
      // OID objects for the entire database.
      //
      // It could be a bitch to debug in some cases, but we can
      // create tooling around that, as needed.
      vals.push_back(tuple.value_by_name(old_schema,
                                         col.name()));
    }

    return Tuple(vals, new_schema);
  }

  const string message_on_completion(size_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<ProjectionPlan> plan_;
};

