#include "execs/seq_scan_exec.hpp"

SeqScanExec::SeqScanExec(ExecCtx& exec_ctx,
                         ptr<SeqScanPlan>&& plan)
  : BaseExec     (exec_ctx),
    plan_        (move(plan))
{}

bool SeqScanExec::match_found(const Tuple& tuple) {
  if (plan_->has_pred()) {
    auto result = plan_->pred().
      eval(tuple, schema()).as<bool>();

    std::cout << "Result from match attempt: " << std::to_string(result) << std::endl;
    return result;
  } else {
    return true;
  }
}

bool SeqScanExec::at_the_end() {
  return table_iter_->stop_iterating();
}

bool SeqScanExec::has_next() {
  std::cout << "Checking if we have a tuple" << std::endl;
  if (!table_iter_->has_tuple()) {
    std::cout << "NO TUPLE! :( :( :(" << std::endl;
    return false;
  }

  while (!at_the_end()) {
    std::cout << "%%%%%%%%%%%%%%%% Checking Tuple: " << table_iter_->tuple().to_string(schema()) << std::endl;

    if (match_found(table_iter_->tuple())) {
      std::cout << "MATCH FOUND! :) :) :)" << std::endl;
      return true;
    }
    ++(*table_iter_);
  }

  std::cout << "NO MATCH WAS FOUND! :( :( :(" << std::endl;
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
