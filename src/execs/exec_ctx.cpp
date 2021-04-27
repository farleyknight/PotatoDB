#include "execs/exec_ctx.hpp"
#include "txns/session.hpp"

ExecCtx::ExecCtx(MRef<Txn> txn,
                 Ref<BuffMgr> buff_mgr,
                 Ref<TxnMgr> txn_mgr,
                 Ref<LockMgr> lock_mgr,
                 MRef<Catalog> catalog)
  : txn_      (txn),
    catalog_  (catalog),
    buff_mgr_ (buff_mgr),
    txn_mgr_  (txn_mgr),
    lock_mgr_ (lock_mgr) {}


Ptr<ExecCtx> ExecCtx::make(MRef<Txn> txn,
                           Ref<BuffMgr> buff_mgr,
                           Ref<TxnMgr> txn_mgr,
                           Ref<LockMgr> lock_mgr,
                           MRef<Catalog> catalog)
{
  return make_unique<ExecCtx>(txn, buff_mgr, txn_mgr, lock_mgr, catalog);
}


Ptr<ExecCtx> ExecCtx::make(MRef<Txn> txn,
                           MRef<Session> sess)
{
  return make(txn,
              sess.buff_mgr(), sess.txn_mgr(), sess.lock_mgr(), sess.catalog());
}
