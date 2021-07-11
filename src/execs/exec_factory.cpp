
#include "execs/exec_factory.hpp"

// QUESTION QUESTION QUESTION QUESTION
//
// What value is this code giving us?
// It turns plans into execs, I know that
// But from the way it looks, plans & execs
// have the same structure?
//
// Does there need to be a separation at this point?
//
// I want to keep this project small, and managable
// for one person. In that case, this stuff might
// get chucked, if I can find a way to merge all of
// the Plan stuff w/ all of the Exec stuff.
//
// I think it's doable though.

ptr<BaseExec>
ExecFactory::create(ExecCtx& exec_ctx,
                    ptr<BasePlan>&& plan)
{
  assert(plan != nullptr);

  switch (plan->type()) {
  case PlanType::TABLE_SCAN: {
    auto scan_plan = cast<SeqScanPlan>(move(plan));
    return make_unique<SeqScanExec>(exec_ctx,
                                    move(scan_plan));
  }

  case PlanType::CREATE_TABLE: {
    auto create_plan = cast<CreateTablePlan>(move(plan));
    return make_unique<CreateTableExec>(exec_ctx, move(create_plan));
  }

  case PlanType::RAW_TUPLES: {
    auto tuples_plan = cast<RawTuplesPlan>(move(plan));
    return make_unique<RawTuplesExec>(exec_ctx,
                                      move(tuples_plan));
  }

  case PlanType::INSERT: {
    auto insert_plan = cast<InsertPlan>(move(plan));
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(insert_plan->child()));
    return make_unique<InsertExec>(exec_ctx,
                                   move(insert_plan),
                                   move(child_exec));
  }

  case PlanType::UPDATE: {
    auto update_plan = cast<UpdatePlan>(move(plan));
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(update_plan->child()));
    return make_unique<UpdateExec>(exec_ctx,
                                   move(update_plan),
                                   move(child_exec));
  }

  case PlanType::DELETE: {
    auto delete_plan = cast<DeletePlan>(move(plan));
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(delete_plan->child()));
    return make_unique<DeleteExec>(exec_ctx,
                                   move(delete_plan),
                                   move(child_exec));
  }

  case PlanType::LIMIT: {
    logger->debug("LimitPlan: " + plan->explain_plan());
    auto limit_plan = cast<LimitPlan>(move(plan));
    assert(limit_plan->child() != nullptr);
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(limit_plan->child()));
    return make_unique<LimitExec>(exec_ctx,
                                  move(limit_plan),
                                  move(child_exec));
  }
  case PlanType::SORT: {
    auto sort_plan = cast<SortPlan>(move(plan));
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(sort_plan->child()));
    return make_unique<SortExec>(exec_ctx,
                                 move(sort_plan),
                                 move(child_exec));
  }
  case PlanType::AGG: {
    // TODO: BasePlan should have an `explain_plan()` method that returns
    // a string representation of the plan.
    //
    // This is useful for two reasons:
    // - Makes it easier to debug this part of the code
    // - Will eventually be useful for EXPLAIN statements in the future.
    logger->debug("AggPlan: " + plan->explain_plan());
    auto agg_plan = cast<AggPlan>(move(plan));
    assert(agg_plan->child() != nullptr);
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(agg_plan->child()));
    assert(child_exec != nullptr);
    return make_unique<AggExec>(exec_ctx,
                                move(agg_plan),
                                move(child_exec));
  }

  case PlanType::PROJECT: {
    auto project_plan = cast<ProjectionPlan>(move(plan));
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(project_plan->child()));
    return make_unique<ProjectionExec>(exec_ctx,
                                       move(project_plan),
                                       move(child_exec));
  }

  case PlanType::LOOP_JOIN: {
    auto nlj_plan = cast<NestedLoopJoinPlan>(move(plan));

    auto left = ExecFactory::create(exec_ctx,
                                    move(nlj_plan->left_plan()));

    auto right = ExecFactory::create(exec_ctx,
                                     move(nlj_plan->right_plan()));

    return make_unique<NestedLoopJoinExec>(exec_ctx,
                                           move(nlj_plan),
                                           move(left),
                                           move(right));
  }

  default:
    throw NotImplementedException("Unsupported plan type.");
  }
}
