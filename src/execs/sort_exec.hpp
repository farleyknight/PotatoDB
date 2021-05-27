#pragma once

#include "execs/base_exec.hpp"
#include "execs/sort_ht.hpp"

class SortExec : public BaseExec {
 public:
  SortExec(ExecCtx& exec_ctx,
           ptr<SortPlan>&& plan,
           ptr<BaseExec>&& child)
    : BaseExec    (exec_ctx),
      plan_       (move(plan)),
      child_      (move(child)),
      table_iter_ (table_.begin())
  {}

  void init() override {
    child_->init();

    while (child_->has_next()){
      auto tuple = child_->next();
      auto sort_key = make_key(tuple);
      // NOTE: Multiple tuples might generate the same sort_key
      // Because of this, we are not sorting tuples but instead
      // sorting buckets of tuples, and the sort_key identifies
      // the buckets.
      table_.insert_into_bucket(sort_key, tuple);
    }

    table_.merge_sort(sort_dir());

    if (sort_asc()) {
      table_iter_ = table_.begin();
    } else if (sort_desc()) {
      table_iter_ = table_.end();
    }
  }

  const string sort_dir() const {
    return plan_->order_by().direction();
  }

  bool sort_asc() const {
    return "asc" == sort_dir();
  }

  bool sort_desc() const {
    return "desc" == sort_dir();
  }

  bool at_the_end() {
    auto end = table_.end();
    return table_iter_ == end;
  }

  bool at_the_beginning() {
    auto begin = table_.begin();
    return table_iter_ == begin;
  }

  bool has_next() override {
    if (sort_asc()) {
      while (!at_the_end()) {
        return true;
      }
    } else if (sort_desc()) {
      while (!at_the_beginning()) {
        return true;
      }
    }
    return false;
  }

  Tuple next() override {
    auto tuple = table_iter_.tuple();
    std::cout << "0000000000000 sort_dir() = " << sort_dir() << std::endl;
    if (sort_asc()) {
      ++table_iter_;
    } else if (sort_desc()){
      --table_iter_;
    }
    return tuple;
  }

  SortKey make_key(const Tuple& tuple) {
    auto col = plan_->order_by().column();
    auto value = tuple.value_by_name(child_schema(), col.name());
    return SortKey(value);
  }

  const string message_on_completion(size_t result_count) const override {
    return "Sorted " + std::to_string(result_count) + " record(s)";
  }

  const QuerySchema& child_schema() const {
    auto child_exec = dynamic_cast<SeqScanExec*>(child_.get());
    return child_exec->schema();
  }

private:
  ptr<SortPlan> plan_;
  ptr<BaseExec> child_;
  SortHT table_;
  SortHT::Iterator table_iter_;
};
