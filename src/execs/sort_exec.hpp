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

  const TableSchema&
  table_schema() const {
    auto table_oid = child_schema().table_oid();
    return exec_ctx_.schema_mgr().table_schema_for(table_oid);
  }

  void init() override {
    child_->init();

    while (child_->has_next()){
      auto tuple = child_->next();
      logger->debug("Adding tuple to SortHT: " +
                    tuple.to_string(table_schema()));

      auto sort_key = make_key(tuple);

      logger->debug("SortKey: " + sort_key.to_string());
      // NOTE: Multiple tuples might generate the same sort_key
      // Because of this, we are not sorting tuples but instead
      // sorting buckets of tuples, and the sort_key identifies
      // the buckets.
      table_.insert_into_bucket(sort_key, tuple);
    }

    logger->debug("SortHT size: " + std::to_string(table_.size()));

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
      return !table_iter_.has_next();
    } else {
      return !table_riter_.has_next();
    }
  }

  bool has_next() override {
    return !at_the_end();
  }

  Tuple
  next() override {
    if (sort_asc()) {
      auto tuple = table_iter_.tuple();
      ++table_iter_;
      return tuple;
    } else {
      auto tuple = table_riter_.tuple();
      ++table_riter_;
      return tuple;
    }
  }

  SortKey make_key(const Tuple& tuple) {
    auto col = plan_->order_by().column();
    auto value = tuple.value_by_name(child_schema(), col.name());
    return SortKey(value);
  }

  const string message_on_completion(int32_t result_count) const override {
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
