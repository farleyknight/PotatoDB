#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/catalog.hpp"

class ExecCtx {
public:
  ExecCtx(Txn&             txn,
          CRef<BuffMgr>    buff_mgr,
          CRef<LockMgr>    lock_mgr,
          CRef<TxnMgr>     txn_mgr,
          CRef<TableMgr>   table_mgr,
          Catalog&         catalog);

  // No copy
  ExecCtx(CRef<ExecCtx>) = delete;
  // No copy assign
  ExecCtx& operator=(CRef<ExecCtx>) = delete;
  // Default destructor
  ~ExecCtx() = default;

  Txn&            txn()             { return txn_; }
  CRef<BuffMgr>   buff_mgr()  const { return buff_mgr_; }
  CRef<TxnMgr>    txn_mgr()   const { return txn_mgr_; }
  CRef<LockMgr>   lock_mgr()  const { return lock_mgr_; }
  CRef<TableMgr>  table_mgr() const { return table_mgr_; }
  Catalog&        catalog()   const { return catalog_; }

private:
  Txn&             txn_;
  CRef<BuffMgr>    buff_mgr_;
  CRef<TxnMgr>     txn_mgr_;
  CRef<LockMgr>    lock_mgr_;
  CRef<TableMgr>   table_mgr_;
  Catalog&         catalog_;
};
