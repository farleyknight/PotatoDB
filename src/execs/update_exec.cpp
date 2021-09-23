
#include "execs/update_exec.hpp"

UpdateExec::UpdateExec(ExecCtx& exec_ctx,
                       ptr<UpdatePlan>&& plan,
                       ptr<BaseExec>&& child)
  : BaseExec (exec_ctx),
    plan_    (move(plan)),
    child_   (move(child))
{}


const QuerySchema& UpdateExec::schema() {
  return plan_->schema();
}

void UpdateExec::init() {
  child_->init();
}

bool UpdateExec::has_next() {
  return child_->has_next();
}

Tuple UpdateExec::next() {
  auto tuple = child_->next();
  auto rid   = tuple.rid();

  logger->debug("[UpdateExec] Preparing to update our next tuple: " +
                tuple.to_string(schema()));

  auto new_tuple = updated_tuple(tuple);

  logger->debug("[UpdateExec] Our tuple has been updated to now be: " +
                new_tuple.to_string(schema()));

  table_heap().update_tuple(new_tuple,
                            rid,
                            exec_ctx_.txn());

  return new_tuple;
}

TableHeap&
UpdateExec::table_heap() {
  auto table_oid = plan_->table_oid();
  return exec_ctx_.schema_mgr().table_heap_for(table_oid);
}

Tuple UpdateExec::updated_tuple(const Tuple& old_tuple) {
  auto &update_values = plan_->update_values();
  int32_t col_count = schema().column_count();
  vector<Value> values;
  for (int32_t index = 0; index < col_count; ++index) {
    std::cout << "Index: " << index << std::endl;

    if (update_values.find(index) == update_values.end()) {
      values.emplace_back(old_tuple.value(schema(), index));
    } else {
      Value new_value = update_values.at(index)->eval(old_tuple, schema());
      values.emplace_back(new_value);
    }
  }

  return Tuple(values, schema());
}
