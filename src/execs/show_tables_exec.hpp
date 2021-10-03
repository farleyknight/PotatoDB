#pragma once

class ShowTablesExec : public BaseExec {
public:
  ShowTablesExec(ExecCtx& exec_ctx,
                 ptr<ShowTablesPlan>&& plan)
    : BaseExec (exec_ctx),
      plan_    (move(plan))
  {}

  void
  init() override {
    table_names_ = exec_ctx_.schema_mgr().table_names();
    table_names_iter_ = table_names_.begin();
  }

  bool
  has_next() override {
    return table_names_iter_ != table_names_.end();
  }

  Tuple
  next_tuple() override {
    return plan_->schema().layout().make(next_value_map(), exec_ctx().txn());
  }

  ValueMap
  next_value_map() override {
    table_name_t table_name = *table_names_iter_;
    table_names_iter_++;
    ValueMap value_map(1);
    value_map.emplace(TABLE_NAME_COLUMN_OID,
                      Value::make(table_name));
    return value_map;
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Showing " + std::to_string(result_count) + " table(s)";
  }

private:
  ptr<ShowTablesPlan> plan_;
  vector<table_name_t> table_names_;
  vector<table_name_t>::iterator table_names_iter_;
};
