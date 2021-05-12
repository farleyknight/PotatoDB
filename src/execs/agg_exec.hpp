#pragma once

#include "plans/agg_plan.hpp"

#include "execs/agg_ht.hpp"
#include "execs/base_exec.hpp"
#include "plans/schema_plan.hpp"

class AggExec : public BaseExec {
public:
  /**********************************************
   * Constructor and destructor
   **********************************************/

  AggExec(ExecCtx& exec_ctx,
          ptr<AggPlan>&& plan,
          ptr<BaseExec>&& child)
    : BaseExec    (exec_ctx),
      plan_       (move(plan)),
      child_      (move(child)),
      table_      (*plan),
      table_iter_ (table_.begin()) {}

  const BaseExec& child() {
    return *child_;
  }

  void init() override;

  bool has_next() override;
  Tuple next() override;

  bool at_the_end() const;
  bool match_found();

  AggKey make_key(const Tuple& tuple);
  AggValue make_val(const Tuple& tuple);

  const QuerySchema& schema() const {
    return dynamic_cast<SchemaPlan*>(plan_->child().get())->schema();
  }

  const string message_on_completion(size_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<AggPlan> plan_;
  ptr<BaseExec> child_;
  AggHT table_;
  AggHT::Iterator table_iter_;
};
