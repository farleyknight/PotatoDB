#pragma once

#include "buffer/buff_mgr.hpp"

#include "catalog/schema_mgr.hpp"

#include "execs/exec_factory.hpp"

#include "plans/base_plan.hpp"

#include "tuple/tuple.hpp"
#include "tuple/result_set.hpp"

#include "txns/txn_mgr.hpp"

class ExecEngine {
public:
  ExecEngine(const BuffMgr& buff_mgr,
             const TxnMgr& txn_mgr,
             const SchemaMgr& schema_mgr)
    : buff_mgr_   (buff_mgr),
      txn_mgr_    (txn_mgr),
      schema_mgr_ (schema_mgr) {}

  // Queries should NOT have to write to the execution engine.
  // TODO: At some point we should try making some of the
  // parameters const, such as `plan` or `exec_ctx`
  ptr<ResultSet>
  query(ptr<BasePlan>&& plan,
        ExecCtx& exec_ctx) const;

  const string
  execute(ptr<BasePlan>&& plan,
          ExecCtx& exec_ctx);

private:
  UNUSED const BuffMgr& buff_mgr_;
  UNUSED const TxnMgr& txn_mgr_;
  UNUSED const SchemaMgr& schema_mgr_;
};
