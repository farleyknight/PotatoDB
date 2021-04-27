#pragma once

class CreateTableExec : public BaseExec {
public:
  void init() override {
    auto schema = plan_->schema();
    auto table_name = plan_->table_name();

    // TODO: Do we need to put any latches around the catalog while we are adding
    // a new table?

    exec_ctx.catalog().create_table(exec_ctx().txn(),
                                    table_name,
                                    schema);
  }

  bool has_next() override {
    return false;
  }

  Tuple next() {
    throw NotImplementedException("next is not implemented for CreateTableExec!");
  }
private:
  Ptr<CreateTablePlan> plan_;
};
