#pragma once

#include <iostream>

#include "disk/file_handle.hpp"

#include "page/page_id.hpp"
#include "page/page.hpp"
#include "recovery/log_file_cursor.hpp"

class FileMgr {
public:

  static constexpr int32_t INDEX_HEADER_BLOCK_NUM = 0;
  static constexpr int32_t INDEX_CONTENT_BLOCK_NUM = 1;

  void remove_all_files() {
    auto iter = fs::directory_iterator(db_directory());
    for (const auto &entry : iter) {
      remove_file(entry.path());
    }
  }

  fs::path
  file_path_for(const string& file_name) const {
    return db_directory() / file_name;
  }

  fs::path
  home_path() const {
    return std::getenv("HOME");
  }

  fs::path
  db_directory() const {
    return home_path() / ".potatodb";
  }

  fs::path
  main_file_name() const {
    return db_directory() / "database.db";
  }

  fs::path
  config_file_name() const {
    return db_directory() / "potatodb.yml";
  }

  file_id_t file_id_for(fs::path file_path);
  file_id_t open_file(fs::path file_path);

  void remove_file(fs::path file_path) const {
    // TODO: Close the FileHandle before removing the file
    fs::remove(file_path);
  }

  bool file_exists(fs::path file_path) const {
    return fs::exists(file_path);
  }
};
