#pragma once

#include "execs/base_exec.hpp"

#include "plans/seq_scan_plan.hpp"

#include "storage/table_iterator.hpp"

class SeqScanExec : public BaseExec {
public:
  /**********************************************
   * Constructor and destructor
   **********************************************/

  SeqScanExec(MRef<ExecCtx> exec_ctx,
              MovePtr<SeqScanPlan> plan);
  ~SeqScanExec() = default;

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
                            MovePtr<SeqScanPlan> plan) {
    return make_unique<SeqScanExec>(exec_ctx, move(plan));
  }

  /**********************************************
   * Instance methods
   **********************************************/

  void init() override {
    // TODO: This might fail for empty tables?
    // Maybe we should check if the table is empty
    // befor doing a scan?
    assert(table_iter_.has_tuple());
    // NOTE: Iter object created in constructor
    // TODO: Maybe do a reset here?
  }

  bool has_next() override;
  Tuple next() override;
  Ref<Schema> schema() override;

private:
  bool match_found(Ref<Tuple> tuple);
  bool at_the_end();

  Ptr<SeqScanPlan> plan_;

  table_oid_t table_oid_;
  MRef<TableHeap> table_heap_;
  TableIterator table_iter_;
};
