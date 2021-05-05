#pragma once

#include "execs/base_exec.hpp"

#include "plans/seq_scan_plan.hpp"

#include "page/table_iterator.hpp"

class SeqScanExec : public BaseExec {
public:
  SeqScanExec(ExecCtx& exec_ctx,
              MovePtr<SeqScanPlan> plan);
  ~SeqScanExec() = default;

  void init() override;
  bool has_next() override;
  Tuple next() override;

private:
  bool match_found(const Tuple& tuple);
  bool at_the_end();
  const QuerySchema& schema();
  TableHeap& table_heap();

  Ptr<SeqScanPlan> plan_;

  UNUSED table_oid_t table_oid_;
  MutPtr<TableIterator> table_iter_;
};
