#pragma once

#include "plans/update_plan.hpp"
#include "execs/base_exec.hpp"

class UpdateExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  UpdateExec(ExecCtx& exec_ctx,
             table_oid_t table_oid,
             MovePtr<UpdatePlan> plan,
             MovePtr<BaseExec> child);

  static Ptr<BaseExec> make(ExecCtx& exec_ctx,
                            table_oid_t table_oid,
                            MovePtr<UpdatePlan> plan,
                            MovePtr<BaseExec> child);


  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  Tuple updated_tuple(CRef<Tuple> old_tuple);

  Ptr<UpdatePlan> plan_;
  table_oid_t table_oid_;
  Ptr<BaseExec> child_;
};
