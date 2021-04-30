#pragma once

#include <memory>

// TODO: Find a way to bundle up all of these files?
#include "plans/base_plan.hpp"
#include "plans/agg_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/update_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/limit_plan.hpp"
#include "plans/raw_tuples_plan.hpp"
#include "plans/sort_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"

// TODO: Find a way to bundle up all of these files?
#include "execs/base_exec.hpp"
#include "execs/agg_exec.hpp"
#include "execs/delete_exec.hpp"
#include "execs/insert_exec.hpp"
#include "execs/limit_exec.hpp"
#include "execs/sort_exec.hpp"
#include "execs/nested_loop_join_exec.hpp"
#include "execs/raw_tuples_exec.hpp"
#include "execs/seq_scan_exec.hpp"
#include "execs/update_exec.hpp"
#include "execs/exec_ctx.hpp"

class ExecFactory {
public:

  template <class DerivedPlan>
  static Ptr<DerivedPlan> cast(MRef<MutPtr<BasePlan>> plan) {
    return unique_ptr<DerivedPlan>(static_cast<DerivedPlan*>(plan.release()));
  }

  /**********************************************
   * Class methods
   **********************************************/

  static Ptr<BaseExec> create(ExecCtx& exec_ctx,
                              MovePtr<BasePlan> plan) {
    switch (plan->type()) {
    case PlanType::TABLE_SCAN: {
      auto scan_plan = cast<SeqScanPlan>(plan);
      return SeqScanExec::make(exec_ctx,
                               move(scan_plan));
    }

    case PlanType::RAW_TUPLES: {
      auto values_plan = cast<RawValuesPlan>(plan);
      return RawValuesExec::make(exec_ctx,
                                 move(values_plan));
    }

    case PlanType::INSERT: {
      auto insert_plan = cast<InsertPlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(insert_plan->child_plan()));
      return InsertExec::make(exec_ctx,
                              move(insert_plan),
                              move(child_exec));
    }

    case PlanType::UPDATE: {
      auto update_plan = cast<UpdatePlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(update_plan->child_plan()));
      return UpdateExec::make(exec_ctx,
                              move(update_plan),
                              move(child_exec));
    }

    case PlanType::DELETE: {
      auto delete_plan = cast<DeletePlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(delete_plan->child_plan()));
      return DeleteExec::make(exec_ctx,
                              move(delete_plan),
                              move(child_exec));
    }

    case PlanType::LIMIT: {
      auto limit_plan = cast<LimitPlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(limit_plan->child_plan()));
      return LimitExec::make(exec_ctx,
                             move(limit_plan),
                             move(child_exec));
    }

    case PlanType::SORT: {
      auto sort_plan = cast<SortPlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(sort_plan->child_plan()));
      return SortExec::make(exec_ctx,
                            move(sort_plan),
                            move(child_exec));
    }

    case PlanType::AGG: {
      auto agg_plan = cast<AggPlan>(plan);
      auto child_exec = ExecFactory::create(exec_ctx,
                                            move(agg_plan->child_plan()));
      return AggExec::make(exec_ctx,
                           move(agg_plan),
                           move(child_exec));
    }

    case PlanType::LOOP_JOIN: {
      auto nlj_plan = cast<NestedLoopJoinPlan>(plan);

      auto left = ExecFactory::create(exec_ctx,
                                      move(nlj_plan->left_plan()));

      auto right = ExecFactory::create(exec_ctx,
                                       move(nlj_plan->right_plan()));

      return NestedLoopJoinExec::make(exec_ctx,
                                      move(nlj_plan),
                                      move(left),
                                      move(right));
    }

    default:
      throw NotImplementedException("Unsupported plan type.");
    }
  }
};
