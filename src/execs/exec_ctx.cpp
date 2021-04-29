#include "execs/exec_ctx.hpp"
#include "server/session.hpp"

ExecCtx::ExecCtx(Txn& txn,
                 CRef<BuffMgr> buff_mgr,
                 CRef<TxnMgr> txn_mgr,
                 CRef<LockMgr> lock_mgr,
                 Catalog& catalog)
  : txn_      (txn),
    catalog_  (catalog),
    buff_mgr_ (buff_mgr),
    txn_mgr_  (txn_mgr),
    lock_mgr_ (lock_mgr) {}


Ptr<ExecCtx> ExecCtx::make(Txn& txn,
                           CRef<BuffMgr> buff_mgr,
                           CRef<TxnMgr> txn_mgr,
                           CRef<LockMgr> lock_mgr,
                           Catalog& catalog)
{
  return make_unique<ExecCtx>(txn, buff_mgr, txn_mgr, lock_mgr, catalog);
}


Ptr<ExecCtx> ExecCtx::make(Txn& txn,
                           Session& sess)
{
  return make(txn,
              sess.buff_mgr(),
              sess.txn_mgr(),
              sess.lock_mgr(),
              sess.catalog());
}
