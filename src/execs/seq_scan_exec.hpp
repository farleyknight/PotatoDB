#pragma once

#include "execs/base_exec.hpp"
#include "plans/seq_scan_plan.hpp"
#include "page/table_iterator.hpp"

class SeqScanExec : public BaseExec {
public:
  SeqScanExec(ExecCtx& exec_ctx,
              ptr<SeqScanPlan>&& plan);
  ~SeqScanExec() = default;

  void init() override;
  bool has_next() override;
  Tuple next() override;

  const QuerySchema& schema();
  const TableSchema& table_schema();

  const string message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  bool match_found(const Tuple& tuple);
  bool at_the_end();
  TableHeap& table_heap();

  ptr<SeqScanPlan> plan_;

  ptr<TableIterator> table_iter_;
};
