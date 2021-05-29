#pragma once

class CreateTableExec : public BaseExec {
public:
  CreateTableExec(ExecCtx& exec_ctx,
                  ptr<CreateTablePlan>&& plan)
    : BaseExec (exec_ctx),
      plan_    (move(plan))
  {}

  void init() override {
    auto table_name = plan_->table_name();
    auto primary_key = plan_->primary_key();

    if (exec_ctx_.catalog().has_table_named(table_name)) {
      if (plan_->if_not_exists()) {
        throw Exception("Just a WARNING");
      } else {
        throw Exception("Full-blown ERROR!");
      }
    }

    // TODO: Do we need to put any latches around the catalog
    // while we are adding a new table?

    auto table_oid = exec_ctx_.catalog().
      create_table(exec_ctx_.txn(),
                   table_name,
                   primary_key,
                   plan_->column_list());

    exec_ctx_.table_mgr().
      create_table(table_name,
                   table_oid,
                   exec_ctx_.txn());
  }

  bool has_next() override {
    return false;
  }

  Tuple next() override {
    throw NotImplementedException("next is not implemented for CreateTableExec!");
  }

  const string message_on_completion(UNUSED size_t result_count) const override {
    return "Created table " + plan_->table_name();
  }

private:
  ptr<CreateTablePlan> plan_;
};
