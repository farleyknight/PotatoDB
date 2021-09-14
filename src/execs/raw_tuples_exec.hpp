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

  bool has_next() override {
    return iter_ != plan_->raw_tuples().end();
  }

  Tuple next() override {
    auto values = iter_.values();

    // for (const auto &value : values) {
    //  std::cout << "Building new tuple with value " << value.to_string() << std::endl;
    // }

    auto tuple = Tuple(iter_.values(), plan_->schema());
    // std::cout << "Next Tuple " << tuple.to_string(plan_->schema()) << std::endl;

    ++iter_;
    return tuple;
  }

  const string message_on_completion(int32_t result_count) const override {
    return "Inserted " + std::to_string(result_count) + " record(s)";
  }
private:
  ptr<RawTuplesPlan> plan_;
  RawTuples::Iterator iter_;
};
