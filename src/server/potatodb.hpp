#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

namespace fs = std::filesystem;

class PotatoDB {
public:
  PotatoDB();

  void shutdown(UNUSED int signal) {
    server_.shutdown();
  }

  const Session& make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  int pool_size() {
    return 100;
  }

  MutPtr<ResultSet> execute(string query);

  MutPtr<BasePlan> build_plan(const BaseExpr& expr);
  void startup();

private:
  int port_ = 7878;
  vector<Session> sessions_;

  SocketServer server_;
  DiskMgr disk_mgr_;
  BuffMgr buff_mgr_;
  LogMgr log_mgr_;
  LockMgr lock_mgr_;
  TxnMgr txn_mgr_;
  TableMgr table_mgr_;
  Catalog catalog_;
  ExecEngine exec_eng_;
};
