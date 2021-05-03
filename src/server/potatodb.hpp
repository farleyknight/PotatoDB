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

  CRef<Session> make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  fs::path main_file_name() {
    return home_path() / ".potatodb" / "database.db";
  }

  fs::path config_file_name() {
    return home_path() / ".potatodb" / "potatodb.yml";
  }

  fs::path log_file_name() {
    return home_path() / ".potatodb" / "database.log";
  }

  fs::path home_path() {
    return std::getenv("HOME");
  }

  int pool_size() {
    return 100;
  }

  MutPtr<ResultSet> execute(string query);

  MutPtr<BasePlan> build_plan(const BaseExpr& expr);
  void startup();

private:
  void setup_db_directory() {
    fs::current_path(home_path());
    fs::create_directory(".potatodb");
    fs::current_path(home_path() / ".potatodb");

    if (!fs::exists(main_file_name())) {
      std::ofstream db_file(main_file_name());
      db_file << "";
      db_file.close();
    }
  }

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
