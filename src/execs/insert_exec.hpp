#pragma once

class InsertExec : public BaseExec {
public:
  InsertExec(ExecCtx& exec_ctx,
             ptr<InsertPlan>&& plan,
             ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child))
  {}

  void init() override {
    child_->init();
  }

  bool has_next() override {
    return child_->has_next();
  }

  Tuple next() override {
    auto &heap = exec_ctx_.table_mgr().table_heap_for(plan_->table_oid());
    auto tuple = child_->next();

    auto schema = exec_ctx_.catalog().query_schema_for(plan_->table_oid());

    std::cout << "Tuple to be inserted " << tuple.to_string(schema) << std::endl;

    heap.insert_tuple(tuple, txn());

    return tuple;
  }

  const string message_on_completion(size_t result_count) const override {
    return "Inserted " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<InsertPlan> plan_;
  ptr<BaseExec> child_;
};
