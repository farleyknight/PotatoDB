#include "execs/insert_exec.hpp"

ValueMap
InsertExec::next_value_map() {
  auto &heap        = exec_ctx_.schema_mgr().table_heap_for(plan_->table_oid());
  auto value_map    = child_->next_value_map();

  auto layout       = plan_->schema().layout();
  auto table_schema =
    exec_ctx_.schema_mgr().table_schema_for(plan_->table_oid());

  layout.add_defaults(value_map,
                      table_schema.defaults(),
                      txn());
  return value_map;
}

Tuple
InsertExec::next_tuple() {
  auto layout    = plan_->schema().layout();
  auto value_map = next_value_map();
  auto new_tuple = layout.make(value_map, txn());

  heap.insert_tuple(new_tuple, txn());

  return new_tuple;
}
