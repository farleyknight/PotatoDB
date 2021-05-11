#include "execs/seq_scan_exec.hpp"

SeqScanExec::SeqScanExec(ExecCtx& exec_ctx,
                         ptr<SeqScanPlan>&& plan)
  : BaseExec     (exec_ctx),
    plan_        (move(plan))
{}

bool SeqScanExec::match_found(const Tuple& tuple) {
  std::cout << "Do we have a predicate? " <<
    (plan_->has_pred() ? "true" : "false") << std::endl;

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
  if (!table_iter_->has_tuple()) {
    return false;
  }

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
}

const QuerySchema& SeqScanExec::schema()  {
  return plan_->schema();
}
