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
    auto &heap = exec_ctx_.table_mgr().table_heap_for(plan_.table_oid());
    auto tuple = child_.next();

    heap.insert_tuple(tuple, txn());

    return tuple;
  }

private:
  InsertPlan plan_;
  BaseExec child_;
};
