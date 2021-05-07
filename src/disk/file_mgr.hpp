#pragma once

#include "disk/file_handle.hpp"

class FileMgr {
public:
  FileMgr(DiskMgr& disk_mgr)
    : disk_mgr_ (disk_mgr)
  {}

  void load_files() {
    // TODO:
    // 1) List all files under the DB directory ($HOME/.potatodb)
    // 2) Create a file handle for each one, add it to `files_`
  }

  file_id_t create_table_file(const string& table_name) {
    auto file_path = disk_mgr_.file_path_for(table_name + ".tbl");
    return add_file(file_path);
  }

  file_id_t add_file(fs::path file_path) {
    auto handle = FileHandle(file_path);
    file_id_t file_id = files_.size();
    files_.push_back(handle);
    return file_id;
  }

private:
  DiskMgr& disk_mgr_;
  vector<FileHandle> files_;
};
