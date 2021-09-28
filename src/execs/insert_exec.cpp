#include "execs/insert_exec.hpp"

Tuple
InsertExec::next() {
  auto &heap = exec_ctx_.schema_mgr().table_heap_for(plan_->table_oid());
  auto tuple = child_->next();

  auto &query_schema = plan_->schema();
  auto table_schema  =
    exec_ctx_.schema_mgr().table_schema_for(plan_->table_oid());

  // TODO: Refactor this at some point?
  auto missing_columns = table_schema.missing_columns(query_schema);
  auto defaults        = table_schema.defaults(missing_columns);

  assert(defaults.size() == missing_columns.size());

  auto new_tuple = tuple.add_defaults(defaults,
                                      table_schema,
                                      query_schema,
                                      exec_ctx().txn());

  std::cout << "New INSERT Tuple : " << new_tuple.to_string(table_schema) << std::endl;

  // NOTE: At this point, the tuple should include all columns from
  // the table schema.
  //
  // Hence we need to pass in the table schema.

  auto table_name = exec_ctx_.schema_mgr().table_name_for(plan_->table_oid());
  logger->debug("Inserting tuple into table: " + table_name);
  heap.insert_tuple(new_tuple, txn());

  return tuple;
}

