#pragma once

#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <memory>

#include "common/config.hpp"

#include "recovery/log_file_cursor.hpp"

#include "disk/file_mgr.hpp"
#include "page/page.hpp"

class DiskMgr {
public:
  DiskMgr(FileMgr& file_mgr);

  // No copy
  DiskMgr(const DiskMgr&) = delete;
  // No copy assign
  DiskMgr& operator=(const DiskMgr&) = delete;

  file_id_t create_table_file(const string& table_name);
  file_id_t load_table_file(const string& table_name);

  void write_page(PageId page_id, const Page& page);
  void read_page(PageId page_id, Page& page);

  void write_log(const Buffer& log_data, buffer_offset_t offset);
  bool read_log(LogFileCursor& cursor);

  PageId allocate_page(file_id_t file_id);
  PageId first_page(file_id_t file_id);

  void deallocate_page(PageId page_id);

  void shutdown() {
    // TODO Close all file handles, not just the log 
    log_io_.close();
  }


  fs::path table_file_for(const string& table_name) const;

  void setup_log_file();
  void setup_db_directory();

  void delete_log_file();
  void truncate_log_file();

private:
  FileMgr& file_mgr_;
  fstream log_io_;

  // stream to write db file
  std::future<void> *flush_log_f_{nullptr};
};
