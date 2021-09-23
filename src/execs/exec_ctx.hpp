#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/schema_mgr.hpp"

class ExecCtx {
public:
  ExecCtx(Txn&       txn,
          BuffMgr&   buff_mgr,
          LockMgr&   lock_mgr,
          TxnMgr&    txn_mgr,
          SchemaMgr& schema_mgr)
    : txn_        (txn),
      schema_mgr_ (schema_mgr),
      buff_mgr_   (buff_mgr),
      txn_mgr_    (txn_mgr),
      lock_mgr_   (lock_mgr)
  {}

  // No copy
  ExecCtx(const ExecCtx&) = delete;
  // No copy assign
  ExecCtx& operator=(const ExecCtx&) = delete;
  // Default destructor
  ~ExecCtx() = default;

  Txn&       txn()         const { return txn_; }
  SchemaMgr& schema_mgr()        { return schema_mgr_; }
  BuffMgr&   buff_mgr()    const { return buff_mgr_; }
  TxnMgr&    txn_mgr()     const { return txn_mgr_; }
  LockMgr&   lock_mgr()    const { return lock_mgr_; }

private:
  Txn&        txn_;
  SchemaMgr&  schema_mgr_;
  BuffMgr&    buff_mgr_;
  TxnMgr&     txn_mgr_;
  LockMgr&    lock_mgr_;
};
