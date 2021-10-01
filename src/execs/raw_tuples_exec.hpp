#pragma once

#include "plans/raw_tuples_plan.hpp"
#include "plans/raw_tuples.hpp"

class RawTuplesExec : public BaseExec {
public:
  RawTuplesExec(ExecCtx& exec_ctx,
                ptr<RawTuplesPlan>&& plan)
    : BaseExec     (exec_ctx),
      plan_        (move(plan)),
      iter_        (plan_->raw_tuples().begin())
  {}

  // TODO: Delete this
  static ptr<BaseExec> make(ExecCtx& exec_ctx,
                            ptr<RawTuplesPlan>&& plan) {
    return make_unique<RawTuplesExec>(exec_ctx, move(plan));
  }

  void init() override {
    // NOTE: Taken care of in constructor
  }

  bool
  has_next() override {
    return iter_ != plan_->raw_tuples().end();
  }

  Tuple
  next_tuple() override {
    auto value_map = next_value_map();
    auto tuple = plan_->schema().layout().make(value_map, exec_ctx().txn());
    return tuple;
  }

  ValueMap
  next_value_map() override {
    auto value_map = iter_.value_map();
    ++iter_;
    return value_map;
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Inserted " + std::to_string(result_count) + " record(s)";
  }
private:
  ptr<RawTuplesPlan> plan_;
  RawTuples::Iterator iter_;
};
