#pragma once

class DescribeTableExec : public BaseExec {
public:
  DescribeTableExec(ExecCtx& exec_ctx,
                    ptr<DescribeTablePlan>&& plan)
    : BaseExec       (exec_ctx),
      plan_          (move(plan)),
      table_columns_ (load_table_columns())
  {}

  void
  init() override {
    table_columns_iter_ = table_columns_.cbegin();
  }

  Tuple
  next() override {
    auto table_column = *table_columns_iter_;
    table_columns_iter_++;
    return build_tuple_from(table_column);
  }

  bool has_next() override {
    return table_columns_iter_ != table_columns_.cend();
  }

  Tuple
  build_tuple_from(TableColumn column) {
    vector<Value> values;

    // Field Name
    values.push_back(Value::make(column.name()));

    // Type (varchar, int, smallint, etc)
    values.push_back(Value::make(Type::as_string(column.type_id())));

    // Nullable "YES" / "NO"
    values.push_back(Value::make(column.is_nullable() ? "YES" : "NO"));

    // Is Primary Key?
    values.push_back(Value::make(column.is_primary_key() ? "YES" : ""));

    // Default
    values.push_back(Value::make(""));

    // Extra - Includes autoincrement
    values.push_back(Value::make(column.is_autoincrement() ? "AUTOINCREMENT" : ""));

    return Tuple(move(values), plan_->schema());
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Showing " + std::to_string(result_count) + " column(s) for table " + table_name();
  }


  const string&
  table_name() const {
    return plan_->table_name();
  }

private:

  vector<TableColumn>&
  load_table_columns() {
    return exec_ctx_.catalog().table_columns_for(table_name());
  }

  const vector<TableColumn>&
  load_table_columns() const {
    return exec_ctx_.catalog().table_columns_for(table_name());
  }

  ptr<DescribeTablePlan> plan_;
  const vector<TableColumn>& table_columns_;
  vector<TableColumn>::const_iterator table_columns_iter_;
};
