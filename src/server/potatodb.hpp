#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

namespace fs = std::filesystem;

const string system_table_sql =
  "CREATE TABLE system_catalog ( " \

  /*
    "id         INTEGER PRIMARY KEY, " \
    "type       INTEGER NOT NULL, " \
    "name       VARCHAR(32) NOT NULL, " \
    "table_name VARCHAR(32) NOT NULL, " \
    "sql        VARCHAR(255) NOT NULL " \
  */

  ");";


class PotatoDB {
public:
  PotatoDB();

  void shutdown(UNUSED int signal) {
    server_.shutdown();
  }

  void build_catalog_table();

  const Session& make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  int pool_size() {
    return 100;
  }

  ptr<ResultSet> execute(string query);

  ptr<BasePlan> build_plan(const BaseExpr& expr);
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

extern PotatoDB potatodb;
