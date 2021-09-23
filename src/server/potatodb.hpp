#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

#include "recovery/log_recovery.hpp"
#include "recovery/checkpoint_mgr.hpp"

enum class ServerState {
  STARTING_UP   = 1,
  RUNNING       = 2,
  SHUTTING_DOWN = 3
};

class PotatoDB {
public:
  PotatoDB();

  void shutdown(UNUSED int signal) {
    state_ = ServerState::SHUTTING_DOWN;
    server_.shutdown();
  }

  void shutdown() {
    logger->debug("Flushing all pages to disk");
    buff_mgr().flush_all();
    logger->debug("Shutting down server");
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

  int pool_size() {
    return 100;
  }

  StatementResult run(const string& statement);

  // TODO: Remove this? Not sure what we did here, but creating new SQL queries was kind of
  // a bad idea.. Stick to in-memory data structures.
  void run_create_table(const table_name_t table_name,
                        const vector<ColumnDefExpr> column_list,
                        Txn& txn,
                        ExecCtx& exec_ctx);

  void reset_installation();
  void verify_system_files();

  fs::path table_file_for(const string& table_name);

  const IndexSchema&
  index_for(const index_name_t index_name) const
  {
    return schema_mgr_.index_schema_for(index_name);
  }

  ExecEngine& exec_eng() {
    return exec_eng_;
  }

  SchemaMgr& schema_mgr() {
    return schema_mgr_;
  }

  const SchemaMgr& schema_mgr() const {
    return schema_mgr_;
  }

  TxnMgr& txn_mgr() {
    return txn_mgr_;
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

  DiskMgr& disk_mgr() {
    return disk_mgr_;
  }

  ExecCtx make_exec_ctx(Txn& txn) {
    return ExecCtx(txn,
                   buff_mgr_,
                   lock_mgr_,
                   txn_mgr_,
                   schema_mgr_);
  }

  LogRecovery log_recovery() {
    auto &txn = txn_mgr_.begin();
    return LogRecovery(disk_mgr_, buff_mgr_, log_mgr_, lock_mgr_, txn);
  }

  bool file_exists(fs::path file_path) const;
  table_oid_t table_oid_for(table_name_t table_name) const;
  table_name_t table_name_for(table_oid_t table_oid) const;

  bool is_logging_enabled() const;
  void run_flush_thread();
  void rebuild_system_catalog();

private:
  int port_ = 7878;
  vector<Session> sessions_;
  SocketServer server_;

  ServerState state_ = ServerState::STARTING_UP;

  DiskMgr       disk_mgr_;
  BuffMgr       buff_mgr_;
  LogMgr        log_mgr_;
  CheckpointMgr checkpoint_mgr_;
  LockMgr       lock_mgr_;
  SchemaMgr     schema_mgr_;

  TxnMgr        txn_mgr_;
  ExecEngine    exec_eng_;
};

extern PotatoDB potatodb;
