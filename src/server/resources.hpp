#pragma once

class Resources {
public:
  Resources() {
    // TODO: Build Resources instance
    // 1) Determine user's home directory
    // 2) Create DiskMgr file under home directory
    // 3) Create Catalog file under home directory
    // 4) [LATER] Each table and index deserves it's own file
  }

  MRef<DiskMgr> disk_mgr()    { return disk_mgr_; }
  MRef<BuffMgr> buff_mgr()    { return buff_mgr_; }
  MRef<ExecEngine> exec_eng() { return exec_eng_; }
  MRef<TxnMgr> txn_mgr()      { return txn_mgr_; }
  MRef<Catalog> catalog()     { return catalog_; }
  MRef<LockMgr> lock_mgr()    { return lock_mgr_; }

private:
  DiskMgr disk_mgr_;
  BuffMgr buff_mgr_;
  LogMgr log_mgr_;
  LockMgr lock_mgr_;
  TxnMgr txn_mgr_;
  Catalog catalog_;
  ExecEngine exec_eng_;
};
