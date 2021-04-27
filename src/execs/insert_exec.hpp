#pragma once

class InsertExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  InsertExec(MRef<ExecCtx> exec_ctx,
             InsertPlan plan,
             BaseExec child)
    : BaseExec (exec_ctx),
      plan_    (plan),
      child_   (child) {}

  void init() override {
    child_.init();
  }

  bool has_next() override {
    return child_.has_next();
  }

  Tuple next() override {
    auto &heap = exec_ctx_.table_mgr().find_table_heap(plan_.table_oid());
    auto tuple = child_.next();
    auto dummy_rid = RID();

    auto inserted = heap.insert_tuple(tuple, dummy_rid, txn());
    if (!inserted) {
      // TODO: Insert txn has failed!
      // Return empty tuple!
    }

    return tuple;
  }

private:
  InsertPlan plan_;
  BaseExec child_;
};
