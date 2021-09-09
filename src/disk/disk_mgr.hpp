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
  const file_id_t LOG_FILE_ID   = 0;
  const file_id_t FIRST_FILE_ID = 1;

  DiskMgr() {
    setup_db_directory();
    setup_log_file();
  }

  void
  setup_log_file() {
    // TODO: Check if log file exists and open if necessary
    log_file_mgr_.create_log_file(LOG_FILE_ID);
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
  }

  void
  truncate_log_file() {
    log_file_mgr_.truncate_log_file();
  }

  void
  delete_log_file() {
    log_file_mgr_.delete_log_file();
  }

  file_id_t
  create_table_file(const file_path_t& file_path) {
    auto file_id = next_file_id_++;
    file_ids_.emplace(file_path, file_id);
    table_file_mgr_.create_table_file(file_id, file_path);
    return file_id;
  }

  file_id_t
  create_index_file(const file_path_t& file_path) {
    auto file_id = next_file_id_++;
    file_ids_.emplace(file_path, file_id);
    index_file_mgr_.create_index_file(file_id, file_path);
    return file_id;
  }

  file_id_t
  open_table_file(const file_path_t& file_path) {
    auto file_id = next_file_id_++;
    file_ids_.emplace(file_path, file_id);
    table_file_mgr_.open_table_file(file_id, file_path);
    return file_id;
  }

  fs::path
  table_file_for(const table_name_t& table_name) {
    return table_file_mgr_.table_file_for(table_name);
  }

  table_oid_t
  table_oid_for(file_id_t file_id) const {
    return table_file_mgr_.table_oid_for(file_id);
  }

  vector<file_id_t>
  table_file_ids() const {
    return table_file_mgr_.table_file_ids();
  }

  vector<file_id_t>
  index_file_ids() const {
    return index_file_mgr_.index_file_ids();
  }

  PageId
  table_header_page(file_id_t file_id) {
    return table_file_mgr_.header_page(file_id);
  }

  PageId
  first_table_page(file_id_t file_id) {
    return table_file_mgr_.first_page(file_id);
  }

  PageId
  index_header_page(file_id_t file_id) {
    return index_file_mgr_.header_page(file_id);
  }

  PageId
  first_index_page(file_id_t file_id) {
    return index_file_mgr_.first_page(file_id);
  }

  file_id_t
  file_id_for(fs::path file_path) const;

  file_id_t
  open_table_file(fs::path file_path);

  file_id_t
  file_id_for_table(table_oid_t table_oid) const {
    return table_file_mgr_.file_id_for(table_oid);
  }

  file_id_t
  file_id_for_index(index_oid_t index_oid) const {
    return index_file_mgr_.file_id_for(index_oid);
  }

  void
  write_log(const Buffer& log_data, buffer_offset_t offset) {
    log_file_mgr_.write_log(log_data, offset);
  }

  bool
  read_log(LogFileCursor& cursor) {
    return log_file_mgr_.read_log(cursor);
  }

  void
  write_buffer(PageId page_id, const Buffer& buffer);
  void
  read_buffer(PageId page_id, Buffer& buffer);

  void
  write_page(PageId page_id, const Page& page) {
    write_buffer(page_id, page.buffer());
  }
  void
  read_page(PageId page_id, Page& page) {
    read_buffer(page_id, page.buffer());
  }

  bool
  is_table_file(file_id_t file_id) {
    return table_file_mgr_.is_table_file(file_id);
  }

  bool
  is_index_file(file_id_t file_id) {
    return index_file_mgr_.is_index_file(file_id);
  }

  bool
  is_log_file(file_id_t file_id) {
    return log_file_mgr_.is_log_file(file_id);
  }

  void
  deallocate_page(PageId page_id);

private:
  TableFileMgr table_file_mgr_;
  IndexFileMgr index_file_mgr_;
  LogFileMgr   log_file_mgr_;

  using file_path_t = string;
  map<file_path_t, file_id_t> file_ids_;

  atomic<file_id_t> next_file_id_ = FIRST_FILE_ID;
};
