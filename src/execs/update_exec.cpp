#include "execs/update_exec.hpp"

UpdateExec::UpdateExec(ExecCtx& exec_ctx,
                       ptr<UpdatePlan>&& plan,
                       ptr<BaseExec>&& child)
  : BaseExec (exec_ctx),
    plan_    (move(plan)),
    child_   (move(child))
{}

const QuerySchema&
UpdateExec::schema() {
  return plan_->schema();
}

void
UpdateExec::init() {
  child_->init();
}

bool
UpdateExec::has_next() {
  return child_->has_next();
}

Tuple
UpdateExec::next() {
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

Tuple
UpdateExec::updated_tuple(const Tuple& old_tuple)
{
  const auto table_oid      = plan_->table_oid();
  const auto &update_values = plan_->update_values();
  const auto &query_schema  =
    exec_ctx_.schema_mgr().query_schema_for(table_oid);

  vector<Value> values;
  for (const auto oid : schema().column_oids()) {
    if (update_values.contains(oid)) {
      Value new_value =
        update_values.at(oid)->eval(old_tuple, query_schema);
      values.emplace_back(new_value);
    } else {
      Value new_value =
        old_tuple.value_by_oid(query_schema, oid);
      values.emplace_back(new_value);
    }
  }

  auto &layout = schema().layout();

  return Tuple(values, layout, exec_ctx().txn());
}
