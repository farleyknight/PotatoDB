#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

enum class ServerState {
  STARTING_UP   = 0,
  RUNNING       = 1,
  SHUTTING_DOWN = 2
};

class PotatoDB {
public:
  PotatoDB();

  void shutdown(UNUSED int signal) {
    state_ = ServerState::SHUTTING_DOWN;
    server_.shutdown();
  }

  void startup();

  void build_system_catalog();
  void start_server();

  const Session& make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  ptr<BasePlan> sql_to_plan(const string& statement) const;

  ptr<ExecCtx> make_exec_ctx(Txn& txn) {
    return make_unique<ExecCtx>(txn,
                                buff_mgr_,
                                lock_mgr_,
                                txn_mgr_,
                                table_mgr_,
                                catalog_);
  }

  int pool_size() {
    return 100;
  }

  StatementResult run_statement(const string& statement);
  StatementResult run_create_table(ptr<BasePlan>&& plan,
                                   Txn& txn,
                                   ExecCtx& exec_ctx);

  void reset_installation();
  void verify_system_files();
  fs::path table_file_for(const string& table_name);

  ExecEngine& exec_eng() {
    return exec_eng_;
  }

  Catalog& catalog() {
    return catalog_;
  }

  TxnMgr& txn_mgr() {
    return txn_mgr_;
  }

  bool file_exists(fs::path file_path) const;

private:
  int port_ = 7878;
  vector<Session> sessions_;
  SocketServer server_;

  ServerState state_ = ServerState::STARTING_UP;

  FileMgr    file_mgr_;
  DiskMgr    disk_mgr_;
  BuffMgr    buff_mgr_;
  LogMgr     log_mgr_;
  LockMgr    lock_mgr_;
  TableMgr   table_mgr_;
  TxnMgr     txn_mgr_;
  Catalog    catalog_;
  ExecEngine exec_eng_;
};

extern PotatoDB potatodb;
