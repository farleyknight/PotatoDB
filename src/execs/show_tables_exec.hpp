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
  next() override {
    table_name_t table_name = *table_names_iter_;
    table_names_iter_++;
    vector<Value> values;
    values.push_back(Value::make(table_name));
    return Tuple(move(values), plan_->schema());
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
