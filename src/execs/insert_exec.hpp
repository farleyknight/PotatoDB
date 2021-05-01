#pragma once

class InsertExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  InsertExec(ExecCtx& exec_ctx,
             MovePtr<InsertPlan> plan,
             MovePtr<BaseExec> child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child))
  {}

  void init() override {
    child_->init();
  }

  bool has_next() override {
    return child_->has_next();
  }

  Tuple next() override {
    auto &heap = exec_ctx_.table_mgr().table_heap_for(plan_->table_oid());
    auto tuple = child_->next();

    heap.insert_tuple(tuple, txn());

    return tuple;
  }

private:
  Ptr<InsertPlan> plan_;
  Ptr<BaseExec> child_;
};
