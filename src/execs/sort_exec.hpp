#pragma once

class SortExec : public BaseExec {
 public:
  /**
   * Creates a new sort executor.
   * @param exec_ctx the executor context
   * @param plan the sort plan to be executed
   * @param child the child executor that produces tuple
   */
  SortExec(ExecCtx& exec_ctx,
           ptr<SortPlan>&& plan,
           ptr<BaseExec>&& child)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      child_   (move(child)) {}

  static ptr<BaseExec> make(ExecCtx& exec_ctx,
                            ptr<SortPlan>&& plan,
                            ptr<BaseExec>&& child)
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
  ptr<SortPlan> plan_;
  ptr<BaseExec> child_;
};
