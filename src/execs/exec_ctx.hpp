#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/catalog.hpp"

class ExecCtx {
public:
  ExecCtx(Txn&          txn,
          const BuffMgr& buff_mgr,
          const LockMgr& lock_mgr,
          const TxnMgr&  txn_mgr,
          TableMgr&     table_mgr,
          Catalog&      catalog);

  // No copy
  ExecCtx(const ExecCtx&) = delete;
  // No copy assign
  ExecCtx& operator=(const ExecCtx&) = delete;
  // Default destructor
  ~ExecCtx() = default;

  Txn&            txn()             { return txn_; }
  TableMgr&       table_mgr()       { return table_mgr_; }
  Catalog&        catalog()         { return catalog_; }
  const Catalog&  catalog()   const { return catalog_; }

  const BuffMgr&  buff_mgr()  const { return buff_mgr_; }
  const TxnMgr&   txn_mgr()   const { return txn_mgr_; }
  const LockMgr&  lock_mgr()  const { return lock_mgr_; }

private:
  Txn&             txn_;
  TableMgr&        table_mgr_;
  Catalog&         catalog_;
  const BuffMgr&    buff_mgr_;
  const TxnMgr&     txn_mgr_;
  const LockMgr&    lock_mgr_;
};
