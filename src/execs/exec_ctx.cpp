#include "execs/exec_ctx.hpp"
#include "server/session.hpp"

ExecCtx::ExecCtx(Txn& txn,
                 const BuffMgr&  buff_mgr,
                 const LockMgr&  lock_mgr,
                 const TxnMgr&   txn_mgr,
                 TableMgr&      table_mgr,
                 Catalog&       catalog)
