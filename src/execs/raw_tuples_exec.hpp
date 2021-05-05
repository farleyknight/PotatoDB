#pragma once

#include "plans/raw_tuples_plan.hpp"
#include "plans/raw_tuples.hpp"

class RawTuplesExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  RawTuplesExec(ExecCtx& exec_ctx,
                ptr<RawTuplesPlan>&& plan)
    : BaseExec     (exec_ctx),
      plan_        (move(plan)),
      iter_        (plan_->raw_tuples().begin())
  {}

  static ptr<BaseExec> make(ExecCtx& exec_ctx,
                            ptr<RawTuplesPlan>&& plan) {
    return make_unique<RawTuplesExec>(exec_ctx, move(plan));
  }

  /**********************************************
   * Instance methods
   **********************************************/

  void init() override {
    // NOTE: Taken care of in constructor
  }

  bool has_next() override {
    return iter_ != plan_->raw_tuples().end();
  }

  Tuple next() override {
    auto &schema =
      exec_ctx_.catalog().find_query_schema(plan_->schema_ref());

    auto tuple = Tuple(iter_.values(), schema);
    ++iter_;
    return tuple;
  }

private:
  ptr<RawTuplesPlan> plan_;
  RawTuples::Iterator iter_;
};
