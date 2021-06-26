
#include "execs/exec_factory.hpp"

ptr<BaseExec>
ExecFactory::create(ExecCtx& exec_ctx,
                    ptr<BasePlan>&& plan)
{
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
    auto limit_plan = cast<LimitPlan>(move(plan));
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
    auto agg_plan = cast<AggPlan>(move(plan));
    assert(agg_plan->child() != nullptr);
    auto child_exec = ExecFactory::create(exec_ctx,
                                          move(agg_plan->child()));
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
