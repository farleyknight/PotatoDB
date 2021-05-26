#pragma once

#include "execs/base_exec.hpp"
#include "execs/sort_ht.hpp"

class SortExec : public BaseExec {
 public:
  SortExec(ExecCtx& exec_ctx,
           ptr<SortPlan>&& plan,
           ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child)) {}

  static ptr<BaseExec> make(ExecCtx& exec_ctx,
                            ptr<SortPlan>&& plan,
                            ptr<BaseExec>&& child)
  {
    return make_unique<SortExec>(exec_ctx,
                                 move(plan),
                                 move(child));
  }

  void init() override {
    child_->init();

    // TODO: Load everything into memory and sort it!
    // Make sure you use external merge-sort here..
    // TODO: Look at AggExec for an example

    table_.init(plan_);
    table_.generate();

    while (child_->has_next()){
      auto tuple = child_->next();
      auto sort_key = make_key(tuple);
      // NOTE: Multiple tuples might generate the same sort_key
      // Because of this, we are not sorting tuples but instead
      // sorting buckets of tuples, and the sort_key identifies
      // the buckets.
      table_.insert_into_bucket(sort_key, tuple);
    }
    table_.merge_sort();
    table_iter_ = table_.begin();
  }

  bool has_next() override {
    // TODO
    return false;
  }

  Tuple next() override {
    // TODO
    return Tuple();
  }

  const string message_on_completion(size_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<SortPlan> plan_;
  ptr<BaseExec> child_;
  SortHT table_;
  SortHT::Iterator table_iter_;
};
