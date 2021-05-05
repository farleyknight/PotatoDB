#pragma once

#include "buffer/buff_mgr.hpp"
#include "catalog/catalog.hpp"

#include "execs/exec_factory.hpp"

#include "plans/base_plan.hpp"

#include "tuple/tuple.hpp"
#include "tuple/result_set.hpp"

#include "txns/txn_mgr.hpp"

class ExecEngine {
public:
  ExecEngine(const BuffMgr& buff_mgr,
             const TxnMgr& txn_mgr,
             const Catalog& catalog)
    : buff_mgr_ (buff_mgr),
      txn_mgr_  (txn_mgr),
      catalog_  (catalog) {}

  Ptr<ResultSet> query(MovePtr<BasePlan> plan,
                       UNUSED const Txn& txn,
                       ExecCtx& exec_ctx) const
  {
    MutVec<Tuple> tuples;

    auto exec = ExecFactory::create(exec_ctx, move(plan));

    exec->init();

    while (exec->has_next()) {
      tuples.push_back(exec->next());
    }

    return make_unique<ResultSet>(plan->schema_ref(),
                                  move(tuples));
  }

  // NOTE: This version does not collect results, hence the inner
  // loop does not do anything with the Tuple & RID
  int execute(MovePtr<BasePlan> plan,
              UNUSED const Txn& txn,
              ExecCtx& exec_ctx)
  {
    auto exec = ExecFactory::create(exec_ctx, move(plan));

    int result_count = 0;
    exec->init();

    try {
      while (exec->has_next()) {
        exec->next();
        ++result_count;
      }
    } catch (Exception &e) {
      return 0;
    }

    return result_count;
  }

private:
  UNUSED const BuffMgr& buff_mgr_;
  UNUSED const TxnMgr& txn_mgr_;
  UNUSED const Catalog& catalog_;
};
