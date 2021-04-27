#pragma once

#include "plans/raw_values_plan.hpp"

class RawValuesExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  RawValuesExec(MRef<ExecCtx> exec_ctx,
                MovePtr<RawValuesPlan> plan)
    : BaseExec     (exec_ctx),
      plan_        (move(plan)),
      iter_        (plan_->raw_value_set().begin())
  {}

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
                            MovePtr<RawValuesPlan> plan) {
    return make_unique<RawValuesExec>(exec_ctx, move(plan));
  }

  /**********************************************
   * Instance methods
   **********************************************/

  void init() override {
    // NOTE: Taken care of in constructor
  }

  bool has_next() override {
    return iter_ != plan_->raw_value_set().end();
  }

  Tuple next() override {
    auto tuple = Tuple(iter_.values(),
                       plan_->schema());
    ++iter_;
    return tuple;
  }

private:
  Ptr<RawValuesPlan> plan_;
  RawValueSet::Iterator iter_;
};
