#pragma once

class CreateTableExec : public BaseExec {
public:
  CreateTableExec(ExecCtx& exec_ctx,
                  ptr<CreateTablePlan>&& plan)
    : BaseExec (exec_ctx),
      plan_    (move(plan))
  {}

  void init() override {
    assert(plan_ != nullptr);

    auto table_name = plan_->table_name();
    auto primary_key = plan_->primary_key();

    assert(table_name.size() > 0);

    // TODO: Do we need to put any latches around the catalog
    // while we are adding a new table?

    // TODO: This logic can get moved into `create_table`
    if (exec_ctx_.schema_mgr().has_table_named(table_name)) {
      if (plan_->if_not_exists()) {
        throw Exception("Just a WARNING");
      } else {
        throw Exception("Full-blown ERROR!");
      }
    }

    // TODO: Handle possible ABORT if txn fails
    exec_ctx_.schema_mgr().
      create_table(plan_->expr(), exec_ctx_.txn());
  }

  bool
  has_next() override {
    return false;
  }

  Tuple
  next_tuple() override {
    auto message = "next_tuple is not implemented for CreateTableExec!";
    throw NotImplementedException(message);
  }

  ValueMap
  next_value_map() override {
    auto message = "next_value_map is not implemented for CreateTableExec!";
    throw NotImplementedException(message);
  }

  const string
  message_on_completion(UNUSED int32_t result_count) const override
  {
    return "Created table " + plan_->table_name();
  }

private:
  ptr<CreateTablePlan> plan_;
};
