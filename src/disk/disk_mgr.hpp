#pragma once

#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <memory>

#include "common/config.hpp"

#include "recovery/log_file_cursor.hpp"

#include "disk/table_file_mgr.hpp"
#include "disk/index_file_mgr.hpp"
#include "disk/log_file_mgr.hpp"

#include "page/page.hpp"

class DiskMgr : public FileMgr {
public:
  DiskMgr() {
    setup_db_directory();
    log_file_mgr_.create_log_file();
  }

  // No copy
  DiskMgr(const DiskMgr&) = delete;
  // No copy assign
  DiskMgr& operator=(const DiskMgr&) = delete;

  void
  setup_db_directory() {
    fs::current_path(home_path());
    fs::create_directory(".potatodb");
    fs::current_path(home_path() / ".potatodb");
  }

  void
  shutdown() {
    table_file_mgr_.close();
    index_file_mgr_.close();
    log_file_mgr_.close();

    // TODO Close all file handles, not just the log
    // log_file_->close();
  }

private:
  TableFileMgr table_file_mgr_;
  IndexFileMgr index_file_mgr_;
  LogFileMgr   log_file_mgr_;

  // TODO: This should live in the FileHandle I think?
  map<file_id_t, block_id_t> next_block_ids_;

  using file_path_t = string;
  map<file_path_t, file_id_t> file_ids_;
  atomic<file_id_t> next_file_id_ = 0;
};
