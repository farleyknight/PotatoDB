#pragma once

#include "plans/update_plan.hpp"
#include "execs/base_exec.hpp"

class UpdateExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  UpdateExec(MRef<ExecCtx> exec_ctx,
             MovePtr<UpdatePlan> plan,
             MovePtr<BaseExec> child);

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
                            MovePtr<UpdatePlan> plan,
                            MovePtr<BaseExec> child);

  /**********************************************
   * Instance methods
   **********************************************/

  Ref<Schema> schema() override;
  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  Tuple updated_tuple(Ref<Tuple> old_tuple);

  Ptr<UpdatePlan> plan_;
  Ref<TableMeta> meta_;
  Ptr<BaseExec> child_;
};
