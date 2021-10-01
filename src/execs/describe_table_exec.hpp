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

  bool has_next() override {
    return table_columns_iter_ != table_columns_.cend();
  }

  map<column_oid_t, Value>
  build_value_map(TableColumn column) {
    map<column_oid_t, Value> value_map;

    value_map.emplace(COLUMN_NAME_COLUMN_OID,
                      Value::make(column.name()));

    value_map.emplace(COLUMN_TYPE_COLUMN_OID,
                      Value::make(Type::as_string(column.type_id())));

    // Nullable "YES" / "NO"
    value_map.emplace(NULLABLE_COLUMN_OID,
                      Value::make(column.is_nullable() ? "YES" : "NO"));

    // Is Primary Key?
    value_map.emplace(PRIMARY_KEY_COLUMN_OID,
                      Value::make(column.is_primary_key() ? "YES" : ""));

    // Default
    value_map.emplace(DEFAULT_VALUE_COLUMN_OID,
                      Value::make(""));

    // Extra - Includes autoincrement
    value_map.emplace(EXTRA_COLUMN_OID,
                      Value::make(column.is_autoincrement() ? "AUTOINCREMENT" : ""));

    return value_map;
  }

  map<column_oid_t, Value>
  next_value_map() override {
    auto table_column = *table_columns_iter_;
    table_columns_iter_++;
    return build_value_map(table_column);
  }

  Tuple
  next_tuple() override {
    return plan_->schema().layout().make(next_value_map(), txn());
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
    return exec_ctx_.schema_mgr().table_columns_for(table_name());
  }

  const vector<TableColumn>&
  load_table_columns() const {
    return exec_ctx_.schema_mgr().table_columns_for(table_name());
  }

  ptr<DescribeTablePlan> plan_;
  const vector<TableColumn>& table_columns_;
  vector<TableColumn>::const_iterator table_columns_iter_;
};
