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

    // TODO: Do we need to put any latches around the catalog while we are adding
    // a new table?

    exec_ctx_.catalog().create_table(exec_ctx().txn(),
                                     table_name,
                                     plan_->column_list());
  }

  bool has_next() override {
    return false;
  }

  Tuple next() override {
    throw NotImplementedException("next is not implemented for CreateTableExec!");
  }

private:
  ptr<CreateTablePlan> plan_;
};
