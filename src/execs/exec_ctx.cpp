#include "execs/exec_ctx.hpp"
#include "server/session.hpp"

ExecCtx::ExecCtx(Txn& txn,
                 const BuffMgr&  buff_mgr,
                 const LockMgr&  lock_mgr,
                 const TxnMgr&   txn_mgr,
                 TableMgr&      table_mgr,
                 Catalog&       catalog)
  : txn_       (txn),
    table_mgr_ (table_mgr),
    catalog_   (catalog),
    buff_mgr_  (buff_mgr),
    txn_mgr_   (txn_mgr),
    lock_mgr_  (lock_mgr)
{}
