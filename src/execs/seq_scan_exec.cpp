#include "execs/seq_scan_exec.hpp"

SeqScanExec::SeqScanExec(ExecCtx& exec_ctx,
                         MovePtr<SeqScanPlan> plan)
  : BaseExec     (exec_ctx),
    plan_        (move(plan))
{}

bool SeqScanExec::match_found(CRef<Tuple> tuple) {
  if (plan_->has_pred()) {
    auto result = plan_->pred().
      eval(tuple, schema()).as<bool>();
    return result;
  }

  return true;
}

bool SeqScanExec::at_the_end() {
  return *table_iter_ == table_heap().end(txn());
}

bool SeqScanExec::has_next()  {
  while (!at_the_end()) {
    if (match_found(table_iter_->tuple())) {
      return true;
    }
    ++(*table_iter_);
  }
  return false;
}

Tuple SeqScanExec::next() {
  auto tuple = table_iter_->tuple();
  ++(*table_iter_);
  return tuple;
}

TableHeap& SeqScanExec::table_heap() {
  return exec_ctx_.table_mgr().table_heap_for(plan_->table_oid());
}

void SeqScanExec::init() {
  table_iter_ = make_unique<TableIterator>(table_heap().begin(txn()));
  // TODO: This might fail for empty tables?
  // Maybe we should check if the table is empty
  // befor doing a scan?
  assert(table_iter_->has_tuple());
  // NOTE: Iter object created in constructor
  // TODO: Maybe do a reset here?
}

CRef<QuerySchema> SeqScanExec::schema()  {
  return find_schema(plan_->schema_ref());
}
