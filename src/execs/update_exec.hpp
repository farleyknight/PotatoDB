#pragma once

#include "plans/update_plan.hpp"
#include "execs/base_exec.hpp"

class UpdateExec : public BaseExec {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  UpdateExec(ExecCtx& exec_ctx,
             MovePtr<UpdatePlan> plan,
             MovePtr<BaseExec> child);

  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  Tuple updated_tuple(const Tuple& old_tuple);
  TableHeap& table_heap();

  const QuerySchema& schema();
  Ptr<UpdatePlan> plan_;
  Ptr<BaseExec> child_;
};
