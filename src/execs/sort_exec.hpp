#pragma once

class SortExec : public BaseExec {
 public:
  /**
   * Creates a new sort executor.
   * @param exec_ctx the executor context
   * @param plan the sort plan to be executed
   * @param child the child executor that produces tuple
   */
  SortExec(MRef<ExecCtx> exec_ctx,
           MovePtr<SortPlan> plan,
           MovePtr<BaseExec> child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child)) {}

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
                            MovePtr<SortPlan> plan,
                            MovePtr<BaseExec> child)
  {
    return make_unique<SortExec>(exec_ctx,
                                 move(plan),
                                 move(child));
  }

  void init() override {
    child_->init();

    // TODO: Load everything into memory and sort it!
    // Make sure you use external merge-sort here..
  }

  bool has_next() override {
    // TODO
    return false;
  }

  Tuple next() override {
    // TODO
    return Tuple();
  }

private:
  /** The sort plan node to be executed. */
  Ptr<SortPlan> plan_;
  Ptr<BaseExec> child_;
};
