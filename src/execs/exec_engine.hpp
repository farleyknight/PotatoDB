#pragma once

#include "buffer/buff_mgr.hpp"
#include "catalog/catalog.hpp"

#include "execs/executor_factory.hpp"

#include "plans/base_plan.hpp"

#include "tuple/tuple.hpp"
#include "tuple/result_set.hpp"

#include "txns/txn_mgr.hpp"

class ExecEngine {
public:
  ExecEngine(Ref<BuffMgr> buff_mgr,
             Ref<TxnMgr> txn_mgr,
             Ref<Catalog> catalog)
    : buff_mgr_ (buff_mgr),
      txn_mgr_  (txn_mgr),
      catalog_  (catalog) {}

  static Ptr<ExecEngine> make(Ref<BuffMgr> buff_mgr,
                              Ref<TxnMgr> txn_mgr,
                              Ref<Catalog> catalog)
  {
    return make_unique<ExecEngine>(buff_mgr, txn_mgr, catalog);
  }

  Ptr<ResultSet> query(MovePtr<BasePlan> plan,
                       Ref<Txn> txn,
                       MRef<ExecCtx> exec_ctx) const
  {
    MutVec<Tuple> tuples;
    auto plan_schema = Schema::copy(plan->schema());
    auto exec = ExecFactory::create(exec_ctx,
                                    move(plan));

    exec->init();

    while (exec->has_next()) {
      tuples.push_back(exec->next());
    }

    // } catch (Exception &e) {
    //   assert(false);
    //   // TODO: handle exceptions
    //   return ResultSet::empty();
    // }

    return ResultSet::make(move(plan_schema),
                           move(tuples));
  }

  // NOTE: This version does not collect results, hence the inner
  // loop does not do anything with the Tuple & RID
  int execute(MovePtr<BasePlan> plan,
               Ref<Txn> txn,
               MRef<ExecCtx> exec_ctx)
  {
    auto exec = ExecFactory::create(exec_ctx, move(plan));

    int result_count = 0;
    exec->init();

    // execute
    try {
      while (exec->has_next()) {
        exec->next();
        ++result_count;
      }
    } catch (Exception &e) {

      // TODO: handle exceptions
      return 0;
    }

    // TODO: This should be returned to the user somehow.
    // std::cout << "Records effected: " << result_count << std::endl;

    return result_count;
  }

private:
  Ref<BuffMgr> buff_mgr_;
  Ref<TxnMgr> txn_mgr_;
  Ref<Catalog> catalog_;
};
