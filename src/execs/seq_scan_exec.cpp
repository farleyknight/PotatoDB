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

    logger->debug("Result from match attempt: " + std::to_string(result));
    return result;
  } else {
    return true;
  }
}

bool SeqScanExec::at_the_end() {
  return table_iter_->stop_iterating();
}

bool SeqScanExec::has_next() {
  logger->debug("Checking if we have a tuple");
  if (!table_iter_->has_tuple()) {
    logger->debug("NO TUPLE! :( :( :(");
    return false;
  }

  logger->debug("We have a tuple! :)");

  while (!at_the_end()) {
    logger->debug("Got schema: " + schema().to_string());
    logger->debug("%%%%%%%%%%%%%%%% Checking Tuple: " +
                  table_iter_->tuple().to_string(table_schema()));

    if (match_found(table_iter_->tuple())) {

      logger->debug("MATCH FOUND! :) :) :)");
      return true;
    }
    ++(*table_iter_);
  }

  logger->debug("NO MATCH WAS FOUND! :( :( :(");
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

const QuerySchema& SeqScanExec::schema() {
  return plan_->schema();
}

const TableSchema& SeqScanExec::table_schema() {
  auto table_oid = plan_->table_oid();
  return exec_ctx_.catalog().table_schema_for(table_oid);
}
