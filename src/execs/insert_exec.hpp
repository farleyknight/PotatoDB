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

    auto &table_schema = exec_ctx_.catalog().table_schema_for(plan_->table_oid());
    auto query_schema  = plan_->schema();

    // std::cout << "Query Schema : " << query_schema.to_string() << std::endl;

    auto missing_columns = table_schema.missing_columns(query_schema);
    auto defaults        = table_schema.defaults(missing_columns);

    if (defaults.size() != missing_columns.size()) {
      std::cout << "Defaults size: " << defaults.size() << std::endl;
      std::cout << "Missing columns size: " << missing_columns.size() << std::endl;
    }
    assert(defaults.size() == missing_columns.size());

    auto new_tuple = tuple.add_defaults(defaults,
                                        table_schema,
                                        query_schema);

    // NOTE: At this point, the tuple should include all columns from the table schema
    // Hence we need to pass in the table schema.

    std::cout << "+++++ New tuple to be inserted " <<
      new_tuple.to_string(table_schema.to_query_schema()) << std::endl;

    heap.insert_tuple(new_tuple, txn());

    return tuple;
  }

  const string message_on_completion(size_t result_count) const override {
    return "Inserted " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<InsertPlan> plan_;
  ptr<BaseExec> child_;
};
