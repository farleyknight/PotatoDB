#pragma once

#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <memory>

#include "common/config.hpp"
#include "page/page.hpp"
#include "disk/file_mgr.hpp"

class DiskMgr {
public:
  DiskMgr(FileMgr& file_mgr);

  // No copy
  DiskMgr(const DiskMgr&) = delete;
  // No copy assign
  DiskMgr& operator=(const DiskMgr&) = delete;

  file_id_t create_table_file(const string& table_name);

  void write_page(PageId page_id, const Page& page);
  void read_page(PageId page_id, Page& page);

  void write_log(const Buffer& log_data, size_t size);
  bool read_log(Buffer& log_data, size_t size, offset_t offset);

  PageId allocate_page(file_id_t file_id);
  void deallocate_page(PageId page_id);

  // Close all file handles.
  void shutdown() {
    log_io_.close();
  }

  fs::path file_path_for(const string& file_name) {
    return db_directory() / file_name;
  }

private:
  void setup_log_file();
  void setup_db_file();
  void setup_db_directory();

  fs::path main_file_name() const {
    return db_directory() / "database.db";
  }

  fs::path config_file_name() const {
    return db_directory() / "potatodb.yml";
  }

  fs::path log_file_name() const {
    return db_directory() / "database.log";
  }

  fs::path db_directory() const {
    return home_path() / ".potatodb";
  }

  fs::path home_path() const {
    return std::getenv("HOME");
  }

  FileMgr& file_mgr_;
  fstream log_io_;

  // stream to write db file
  bool flush_log_;
  std::future<void> *flush_log_f_{nullptr};
};
