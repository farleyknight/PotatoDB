#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/catalog.hpp"

class ExecCtx {
public:
  ExecCtx(Txn&          txn,
          CRef<BuffMgr> buff_mgr,
          CRef<LockMgr> lock_mgr,
          CRef<TxnMgr>  txn_mgr,
          TableMgr&     table_mgr,
          Catalog&      catalog);

  // No copy
  ExecCtx(CRef<ExecCtx>) = delete;
  // No copy assign
  ExecCtx& operator=(CRef<ExecCtx>) = delete;
  // Default destructor
  ~ExecCtx() = default;

  Txn&            txn()             { return txn_; }
  TableMgr&       table_mgr()       { return table_mgr_; }
  Catalog&        catalog()         { return catalog_; }
  CRef<Catalog>   catalog()   const { return catalog_; }

  CRef<BuffMgr>   buff_mgr()  const { return buff_mgr_; }
  CRef<TxnMgr>    txn_mgr()   const { return txn_mgr_; }
  CRef<LockMgr>   lock_mgr()  const { return lock_mgr_; }

private:
  Txn&             txn_;
  TableMgr&        table_mgr_;
  Catalog&         catalog_;
  CRef<BuffMgr>    buff_mgr_;
  CRef<TxnMgr>     txn_mgr_;
  CRef<LockMgr>    lock_mgr_;
};
