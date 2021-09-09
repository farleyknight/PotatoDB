#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/catalog.hpp"

class ExecCtx {
public:
  ExecCtx(Txn&      txn,
          BuffMgr&  buff_mgr,
          LockMgr&  lock_mgr,
          TxnMgr&   txn_mgr,
          Catalog&  catalog)
    : txn_       (txn),
      catalog_   (catalog),
      buff_mgr_  (buff_mgr),
      txn_mgr_   (txn_mgr),
      lock_mgr_  (lock_mgr)
  {}

  // No copy
  ExecCtx(const ExecCtx&) = delete;
  // No copy assign
  ExecCtx& operator=(const ExecCtx&) = delete;
  // Default destructor
  ~ExecCtx() = default;

  Txn&      txn()       const { return txn_; }
  Catalog&  catalog()         { return catalog_; }
  BuffMgr&  buff_mgr()  const { return buff_mgr_; }
  TxnMgr&   txn_mgr()   const { return txn_mgr_; }
  LockMgr&  lock_mgr()  const { return lock_mgr_; }

private:

  Txn&        txn_;
  Catalog&    catalog_;
  BuffMgr&    buff_mgr_;
  TxnMgr&     txn_mgr_;
  LockMgr&    lock_mgr_;
};
