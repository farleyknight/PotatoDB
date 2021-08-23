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

  PageId allocate_page(file_id_t file_id);
  PageId first_page(file_id_t file_id);

  void deallocate_page(PageId page_id);

  fs::path table_file_for(const string& table_name) const;

  void setup_db_directory();

private:
  FileMgr& file_mgr_;

  // stream to write db file
};
