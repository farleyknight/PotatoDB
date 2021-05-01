#pragma once

#include "execs/exec_ctx.hpp"
#include "execs/exec_engine.hpp"

#include "parser/sql_parser.hpp"

#include "tuple/result_set.hpp"

class PotatoDB;

class Session {
public:
  Session(PotatoDB* db);
  ~Session();

  ResultSet execute(String query);

private:
  PotatoDB* db_; // Use as a reference

  DiskMgr disk_mgr_;
  BuffMgr buff_mgr_;
  LogMgr log_mgr_;
  LockMgr lock_mgr_;
  TxnMgr txn_mgr_;
  Catalog catalog_;
  ExecEngine exec_eng_;
};
