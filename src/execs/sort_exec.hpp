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

  void
  init() override {
    child_->init();

    while (child_->has_next()){
      auto value_map = child_->next_value_map();
      auto layout = child_schema().layout();
      logger->debug("Adding tuple to SortHT: " +
                    layout.to_string(value_map));

      auto sort_key = make_key(value_map);

      logger->debug("SortKey: " + sort_key.to_string());
      // NOTE: Multiple tuples might generate the same sort_key
      // Because of this, we are not sorting tuples but instead
      // sorting buckets of tuples, and the sort_key identifies
      // the buckets.
      table_.insert_into_bucket(sort_key, value_map);
    }

    logger->debug("SortHT size: " + std::to_string(table_.size()));

    table_.merge_sort(sort_dir());

    if (sort_asc()) {
      table_iter_ = table_.begin();
    } else if (sort_desc()) {
      table_riter_ = table_.rbegin();
    }
  }

  const string
  sort_dir() const {
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
  next_tuple() override {
    if (sort_asc()) {
      auto value_map = table_iter_.value_map();
      ++table_iter_;
      return child_schema().layout().make(value_map, txn());
    } else {
      auto value_map = table_riter_.value_map();
      ++table_riter_;
      return child_schema().layout().make(value_map, txn());
    }
  }

  ValueMap
  next_value_map() override {
    if (sort_asc()) {
      auto value_map = table_iter_.value_map();
      ++table_iter_;
      return value_map;
    } else {
      auto value_map = table_riter_.value_map();
      ++table_riter_;
      return value_map;
    }
  }

  SortKey
  make_key(const Tuple& tuple) {
    auto oid = plan_->order_by().column().oid();
    auto layout = child_schema().layout();
    auto value = layout.value_by_oid(tuple, oid);
    return SortKey(value);
  }

  SortKey
  make_key(const ValueMap& value_map) {
    auto oid = plan_->order_by().column().oid();
    auto value = value_map.at(oid);
    return SortKey(value);
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Sorted " + std::to_string(result_count) + " record(s)";
  }

  const QuerySchema&
  child_schema() const {
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
