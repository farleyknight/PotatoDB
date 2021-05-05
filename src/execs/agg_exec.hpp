#pragma once

#include "plans/agg_plan.hpp"

#include "execs/agg_ht.hpp"
#include "execs/base_exec.hpp"

class AggExec : public BaseExec {
public:
  /**********************************************
   * Constructor and destructor
   **********************************************/

  AggExec(ExecCtx& exec_ctx,
          MovePtr<AggPlan> plan,
          MovePtr<BaseExec> child)
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

private:
  MutPtr<AggPlan> plan_;
  MutPtr<BaseExec> child_;
  AggHT table_;
  AggHT::Iterator table_iter_;
};
