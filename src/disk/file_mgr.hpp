#pragma once

#include <iostream>

#include "disk/file_handle.hpp"
#include "page/page_id.hpp"

class FileMgr {
public:
  static constexpr int32_t TABLE_HEADER_BLOCK_NUM = 0;
  static constexpr int32_t TABLE_CONTENT_BLOCK_NUM = 1;

  FileMgr() {}

  void write_buffer(PageId page_id, const Buffer& buffer);
  void read_buffer(PageId page_id, Buffer& buffer);

  void deallocate_page(PageId page_id);
  PageId allocate_page(file_id_t file_id);
  PageId first_table_page(file_id_t file_id);

  file_id_t create_table_file(const string& table_name) {
    return create_file(table_file_for(table_name));
  }

  file_id_t create_index_file(const string& table_name) {
    return create_file(index_file_for(table_name));
  }

  file_id_t load_table_file(const string& table_name) {
    return load_file(table_file_for(table_name));
  }

  fs::path file_path_for(const string& file_name) const {
    return db_directory() / file_name;
  }

  fs::path home_path() const {
    return std::getenv("HOME");
  }

  fs::path db_directory() const {
    return home_path() / ".potatodb";
  }

  fs::path table_file_for(const string& table_name) const {
    return file_path_for(table_name + ".tbl");
  }

  fs::path index_file_for(const string& table_name) const {
    return file_path_for(table_name + ".idx");
  }

  void remove_all_files() {
    auto iter = fs::directory_iterator(db_directory());
    for (const auto &entry : iter) {
      remove_file(entry.path());
    }
  }

  fs::path main_file_name() const {
    return db_directory() / "database.db";
  }

  fs::path config_file_name() const {
    return db_directory() / "potatodb.yml";
  }

  fs::path log_file_name() const {
    return db_directory() / "database.log";
  }

  bool table_file_exists(const string& table_name) const {
    logger->debug("[DiskMgr] Checking if there is a table file for : " + table_name);
    return file_exists(table_file_for(table_name));
  }

  void remove_table_files() {
    auto iter = fs::directory_iterator(db_directory());
    for (const auto &entry : iter) {
      if (entry.path().extension() == ".tbl") {
        remove_file(entry.path());
      }
    }
  }

  file_id_t create_file(fs::path file_path) {
    file_id_t file_id = files_.size();
    auto handle = make_unique<FileHandle>(file_path);
    files_.emplace_back(move(handle));
    return file_id;
  }

  // NOTE: create_file and load_file are identical for now.
  // TODO: At some point, we may combine them?
  file_id_t load_file(fs::path file_path) {
    // std::cout << "Creating file " << file_path << std::endl;
    file_id_t file_id = files_.size();
    auto handle = make_unique<FileHandle>(file_path);
    files_.emplace_back(move(handle));
    return file_id;
  }

  void remove_file(fs::path file_path) const {
    fs::remove(file_path);
  }

  bool file_exists(fs::path file_path) const {
    return fs::exists(file_path);
  }

private:
  map<file_id_t, block_id_t> next_block_ids_;
  // TODO: Maybe this should be a mapping as well?
  // TODO: Eventually `files_` will have to be persisted to disk
  // It may be easier to store a mapping between file_ids and fs::path
  vector<ptr<FileHandle>> files_;
};
