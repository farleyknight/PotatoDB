#pragma once

#include "txns/txn_mgr.hpp"
#include "buffer/table_mgr.hpp"
#include "catalog/catalog.hpp"

class ExecCtx {
public:
  ExecCtx(MRef<Txn>     txn,
          Ref<BuffMgr>    buff_mgr,
          Ref<LockMgr>    lock_mgr,
          Ref<TxnMgr>     txn_mgr,
          Ref<TableMgr>   table_mgr,
          MRef<Catalog> catalog);

  // No copy
  ExecCtx(Ref<ExecCtx>) = delete;
  // No copy assign
  MRef<ExecCtx> operator=(Ref<ExecCtx>) = delete;
  // Default destructor
  ~ExecCtx() = default;

  MRef<Txn>     txn()             { return txn_; }
  Ref<BuffMgr>    buff_mgr()  const { return buff_mgr_; }
  Ref<TxnMgr>     txn_mgr()   const { return txn_mgr_; }
  Ref<LockMgr>    lock_mgr()  const { return lock_mgr_; }
  Ref<TableMgr>   table_mgr() const { return table_mgr_; }
  MRef<Catalog> catalog()   const { return catalog_; }

private:
  MRef<Txn>     txn_;
  Ref<BuffMgr>    buff_mgr_;
  Ref<TxnMgr>     txn_mgr_;
  Ref<LockMgr>    lock_mgr_;
  Ref<TableMgr>   table_mgr_;
  MRef<Catalog> catalog_;
};
