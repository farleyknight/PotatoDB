#pragma once

#include "plans/agg_plan.hpp"
#include "tuple/value_factory.hpp"

#include "execs/agg_ht.hpp"
#include "execs/base_exec.hpp"

/**
 * AggExec executes an aggregation operation
 * (e.g. COUNT, SUM, MIN, MAX) on the tuples of a child executor.
 */
class AggExec : public BaseExec {
public:
  /**********************************************
   * Constructor and destructor
   **********************************************/

  AggExec(MRef<ExecCtx> exec_ctx,
          AggPlan plan,
          BaseExec child)
    : BaseExec    (exec_ctx),
      plan_       (plan),
      child_      (child),
      table_      (plan),
      table_iter_ (table_.begin()) {}

  Ref<BaseExec> child() const {
    return child_;
  }

  void init() override;

  bool has_next() override;
  Tuple next() override;

  bool at_the_end() const;
  bool match_found();

  AggKey make_key(Ref<Tuple> tuple);
  AggValue make_val(Ref<Tuple> tuple);

private:
  AggPlan plan_;
  BaseExec child_;
  AggHT table_;
  AggHT::Iterator table_iter_;
};
