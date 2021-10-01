#pragma once

#include "plans/agg_plan.hpp"

#include "execs/base_exec.hpp"
#include "execs/has_child_exec.hpp"
#include "execs/agg_ht.hpp"
#include "execs/seq_scan_exec.hpp"
#include "plans/query_schema_plan.hpp"
#include "execs/has_child_exec.hpp"

class AggExec : public BaseExec,
                public HasChildExec
{
public:
  AggExec(ExecCtx& exec_ctx,
          ptr<AggPlan>&& plan,
          ptr<BaseExec>&& child)
    : BaseExec     (exec_ctx),
      HasChildExec (move(child)),
      plan_        (move(plan)),
      table_iter_  (table_.begin())
  {
    assert(child_ != nullptr);
  }

  void
  init() override;
  bool
  has_next() override;
  Tuple
  next_tuple() override;
  map<column_oid_t, Value>
  next_value_map() override;

  bool
  at_the_end();
  bool
  match_found();

  AggKey
  make_key(const Tuple& tuple);
  AggValue
  make_val(const Tuple& tuple);

  const QuerySchema&
  schema() const {
    return dynamic_cast<QuerySchemaPlan*>(plan_.get())->schema();
  }

  const QuerySchema&
  child_schema() const {
    auto child_exec = dynamic_cast<SeqScanExec*>(child_.get());
    return child_exec->schema();
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<AggPlan> plan_;
  AggHT table_;
  AggHT::Iterator table_iter_;
};
