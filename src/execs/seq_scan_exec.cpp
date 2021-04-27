
#include "execs/seq_scan_exec.hpp"

SeqScanExec::SeqScanExec(MRef<ExecCtx> exec_ctx,
                         MovePtr<SeqScanPlan> plan)
  : BaseExec     (exec_ctx),
    plan_        (move(plan)),
    table_oid_   (plan_->table_oid()),
    table_heap_  (catalog().table(table_oid_).table_heap()),
    table_iter_  (table_heap_.begin(txn())) {}

bool SeqScanExec::match_found(Ref<Tuple> tuple) {
  if (plan_->has_pred()) {
    auto result = plan_->pred().
      eval(tuple, schema()).get_as<bool>();
    return result;
  }
  return true;
}

bool SeqScanExec::at_the_end() {
  return table_iter_ == table_heap_.end(txn());
}

bool SeqScanExec::has_next()  {
  while (!at_the_end()) {
    if (match_found(table_iter_.tuple())) {
      return true;
    }
    ++table_iter_;
  }
  return false;
}

Tuple SeqScanExec::next()  {
  auto tuple = table_iter_.tuple();
  ++table_iter_;
  return tuple;
}

Ref<Schema> SeqScanExec::schema()  {
  return plan_->schema();
}
