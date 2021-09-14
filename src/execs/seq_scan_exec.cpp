#include "execs/seq_scan_exec.hpp"


// In my head I'm imaging that we
// have a vector of ptr<BaseOper>
//
// These BaseOper things are operators that can be
// applied o tuples.
//
// Basically a BaseOper is just a Plan + Exec
//
// Because I don't see why we separated them?
//
// Anyways, this vector of ptr<BaseOper> has
// a way of communicating between BaseOper
//
// Each BaseOper has a vector<plan_index_t>
// where plan_index_t is just the index of
// the plan in the main vector<ptr<BaseOper>>
//
// These operators can communicate with one
// another, knowing that:
//
// 1) The first element in vector<ptr<BaseOper>>
//    should always be a "source".
// 1b) A "source" is an operator that can produce
//     tuples, given some metadata, like a table_oid
//     or index_oid
// 2) That first operator will produce a new tuple.
// 3) That first tuple is then forwarded to the
//    second operator in the vector.
// 4) The second operator will process the tuple and
//    forward it to the third, and so on.
// 5) We continue this way until we get to the end of
//    the vector of operators.
// 6) At the end, we place the tuple we have into a
//    running "result set".
// 7) We then start all over again, back at the beginning
//    with the first operator, which will produce
//    a new tuple. The process starts all over again...
//

// This is a very "baby" VM but this might be the start
// of the PotatoDB OvenVM ! :) :) :)

// While it is fun to think about, keep in mind that this
// is a rather limited design. We would have to think about
// whether it actually makes sense to forward every tuple
// along. Also, how would you represent joins?
//
// Perhaps joins
// You can't
// think of them in terms of 

SeqScanExec::SeqScanExec(ExecCtx& exec_ctx,
                         ptr<SeqScanPlan>&& plan)
  : BaseExec     (exec_ctx),
    plan_        (move(plan))
{}

bool SeqScanExec::match_found(const Tuple& tuple) {
  if (plan_->has_pred()) {
    auto result = plan_->pred().
      eval(tuple, schema()).as<bool>();

    logger->debug("[SeqScanExec] Result from match attempt: " + std::to_string(result));
    return result;
  } else {
    return true;
  }
}

bool SeqScanExec::at_the_end() {
  return table_iter_->stop_iterating();
}

bool SeqScanExec::has_next() {
  logger->debug("[SeqScanExec] Checking if we have a tuple");
  if (!table_iter_->has_tuple()) {
    logger->debug("[SeqScanExec] NO TUPLE! :( :( :(");
    return false;
  }

  logger->debug("[SeqScanExec] We have a tuple! :)");

  while (!at_the_end()) {
    // logger->debug("[SeqScanExec] Got schema: " + schema().to_string());
    logger->debug("[SeqScanExec] Checking Tuple: " +
                  table_iter_->tuple().to_string(table_schema()));

    if (match_found(table_iter_->tuple())) {

      logger->debug("[SeqScanExec] MATCH FOUND! :) :) :)");
      return true;
    }
    ++(*table_iter_);
  }

  logger->debug("[SeqScanExec] NO MATCH WAS FOUND! :( :( :(");
  return false;
}

Tuple SeqScanExec::next() {
  auto tuple = table_iter_->tuple();
  ++(*table_iter_);
  return tuple;
}

TableHeap& SeqScanExec::table_heap() {
  auto table_oid = plan_->table_oid();
  return exec_ctx_.catalog().table_heap_for(table_oid);
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
