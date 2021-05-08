#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

class PotatoDB {
public:
  PotatoDB();

  void shutdown(UNUSED int signal) {
    server_.shutdown();
  }

  void build_system_catalog();
  void start_server();

  const Session& make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  int pool_size() {
    return 100;
  }

  void execute(string statement);
  ptr<ResultSet> query(string statement);

  void startup();

private:
  int port_ = 7878;
  vector<Session> sessions_;
  SocketServer server_;

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
