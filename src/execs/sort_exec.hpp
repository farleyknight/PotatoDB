#pragma once

#include "execs/base_exec.hpp"
#include "execs/sort_ht.hpp"

class SortExec : public BaseExec {
public:
  SortExec(ExecCtx& exec_ctx,
           ptr<SortPlan>&& plan,
           ptr<BaseExec>&& child)
    : BaseExec     (exec_ctx),
      plan_        (move(plan)),
      child_       (move(child)),
      table_iter_  (table_.begin()),
      table_riter_ (table_.rbegin())
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
      table_riter_ = table_.rbegin();
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
    if (sort_asc()) {
      auto end = table_.end();
      return table_iter_ == end;
    } else {
      auto end = table_.rend();
      return table_riter_ == end;
    }
  }

  bool has_next() override {
    return !at_the_end();
  }

  Tuple next() override {
    if (sort_asc()) {
      auto tuple = table_iter_.tuple();
      std::cout << "0000000000000 sort_dir() = " << sort_dir() << std::endl;
      ++table_iter_;
      return tuple;
    } else {
      auto tuple = table_riter_.tuple();
      std::cout << "0000000000000 sort_dir() = " << sort_dir() << std::endl;
      ++table_riter_;
      return tuple;
    }
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
  SortHT::RIterator table_riter_;
};
