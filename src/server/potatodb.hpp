#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

#include "recovery/log_recovery.hpp"
#include "recovery/checkpoint_mgr.hpp"

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

  void shutdown() {
    std::cout << "Flushing all pages to disk" << std::endl;
    buff_mgr().flush_all();
    std::cout << "Shutting down server" << std::endl;
    shutdown(0);
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

  StatementResult run(const string& statement);

  void run_create_table(const table_name_t table_name,
                        const vector<ColumnDefExpr> column_list,
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

  const Catalog& catalog() const {
    return catalog_;
  }

  TxnMgr& txn_mgr() {
    return txn_mgr_;
  }

  TableMgr& table_mgr() {
    return table_mgr_;
  }

  LogMgr& log_mgr() {
    return log_mgr_;
  }

  BuffMgr& buff_mgr() {
    return buff_mgr_;
  }

  CheckpointMgr& checkpoint_mgr() {
    return checkpoint_mgr_;
  }

  FileMgr& file_mgr() {
    return file_mgr_;
  }

  DiskMgr& disk_mgr() {
    return disk_mgr_;
  }

  LogRecovery& log_recovery() {
    return log_recovery_;
  }

  bool file_exists(fs::path file_path) const;
  bool is_logging_enabled() const;
  void run_flush_thread();

private:
  int port_ = 7878;
  vector<Session> sessions_;
  SocketServer server_;

  ServerState state_ = ServerState::STARTING_UP;

  FileMgr       file_mgr_;
  DiskMgr       disk_mgr_;
  BuffMgr       buff_mgr_;
  LogMgr        log_mgr_;
  LogRecovery   log_recovery_;
  LockMgr       lock_mgr_;
  CheckpointMgr checkpoint_mgr_;
  TableMgr      table_mgr_;
  TxnMgr        txn_mgr_;
  Catalog       catalog_;
  ExecEngine    exec_eng_;
};

extern PotatoDB potatodb;
