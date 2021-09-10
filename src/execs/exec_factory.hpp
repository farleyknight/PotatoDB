#pragma once

#include <memory>

#include "common/config.hpp"

#include "plans/base_plan.hpp"
#include "plans/agg_plan.hpp"
#include "plans/create_table_plan.hpp"
#include "plans/insert_plan.hpp"
#include "plans/update_plan.hpp"
#include "plans/delete_plan.hpp"
#include "plans/limit_plan.hpp"
#include "plans/raw_tuples_plan.hpp"
#include "plans/sort_plan.hpp"
#include "plans/nested_loop_join_plan.hpp"
#include "plans/projection_plan.hpp"
#include "plans/show_tables_plan.hpp"

#include "execs/base_exec.hpp"
#include "execs/agg_exec.hpp"
#include "execs/create_table_exec.hpp"
#include "execs/delete_exec.hpp"
#include "execs/insert_exec.hpp"
#include "execs/limit_exec.hpp"
#include "execs/sort_exec.hpp"
#include "execs/nested_loop_join_exec.hpp"
#include "execs/projection_exec.hpp"
#include "execs/raw_tuples_exec.hpp"
#include "execs/seq_scan_exec.hpp"
#include "execs/update_exec.hpp"
#include "execs/show_tables_exec.hpp"
#include "execs/exec_ctx.hpp"

class ExecFactory {
public:
  template <class T>
  static ptr<T> cast(ptr<BasePlan>&& plan) {
    assert(plan != nullptr);

    auto tmp = dynamic_cast<T*>(plan.get());
    unique_ptr<T> derived;

    plan.release();
    derived.reset(tmp);

    return derived;
  }

  static ptr<BaseExec> create(ExecCtx& exec_ctx,
                              ptr<BasePlan>&& plan);
};
