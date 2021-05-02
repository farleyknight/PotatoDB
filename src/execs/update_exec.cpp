
#include "execs/update_exec.hpp"

UpdateExec::UpdateExec(ExecCtx& exec_ctx,
                       MovePtr<UpdatePlan> plan,
                       MovePtr<BaseExec> child)
  : BaseExec (exec_ctx),
    plan_    (move(plan)),
    child_   (move(child))
{}


CRef<QuerySchema> UpdateExec::schema() {
  return find_schema(plan_->schema_ref());
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

  auto new_tuple = updated_tuple(tuple);

  bool updated = table_heap().update_tuple(new_tuple,
                                           rid,
                                           exec_ctx_.txn());

  return new_tuple;
}

TableHeap& UpdateExec::table_heap() {
  return exec_ctx_.table_mgr().table_heap_for(plan_->table_oid());
}

Tuple UpdateExec::updated_tuple(CRef<Tuple> old_tuple) {
  auto update_attrs = plan_->update_attrs();
  uint32_t col_count = schema().column_count();
  MutVec<Value> values;
  for (uint32_t index = 0; index < col_count; index++) {
    if (update_attrs.find(index) == update_attrs.end()) {
      values.emplace_back(old_tuple.value(schema(), index));
    } else {
      UpdateInfo info = update_attrs.at(index);
      Value val = old_tuple.value(schema(), index);
      switch (info.type()) {
      case UpdateType::ADD:
        values.emplace_back(val.add(info.value()));
        break;

      case UpdateType::SET:
        values.emplace_back(info.value());
        break;
      }
    }
  }

  return Tuple(values, schema());
}
