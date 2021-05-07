#pragma once

#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <memory>

#include "common/config.hpp"
#include "page/page.hpp"

class DiskMgr {
public:
  DiskMgr();

  // No copy
  DiskMgr(const DiskMgr&) = delete;
  // No copy assign
  DiskMgr& operator=(const DiskMgr&) = delete;

  void write_buffer(PageId page_id, const Buffer& buffer);
  void read_buffer(PageId page_id, Buffer& buffer);

  void write_page(PageId page_id, const Page& page);
  void read_page(PageId page_id, Page& page);

  // TODO:
  // 1) allocate_page should take a file_id
  // 2) keep track fo all file_ids
  // 3) on each call to `allocate_path`, increment a counter just for
  //    that particular file_id
  PageId allocate_page(file_id_t file_id) {
    // TODO! Implement in "CREATE TABLE"
    // or "CREATE INDEX" context.

    if (next_block_ids_.count(file_id) == 0) {
      next_block_ids_.emplace(make_pair(0, 0));
      return PageId(file_id, 0);
    } else {
      auto block_id = next_block_ids_[file_id]++;
      return PageId(file_id, block_id);
    }
  }

  void deallocate_page(UNUSED PageId page_id) {
    /*
     * Deallocate page (operations like drop index/table)
     * Need bitmap in header page for tracking pages
     * This does not actually need to do anything for now.
     */
    // TODO! Implement in "DROP TABLE" or "DROP INDEX" context.
  }

  void write_log(const Buffer& log_data, size_t size);
  bool read_log(Buffer& log_data, size_t size, size_t offset);

  // Close all file handles.
  void shutdown() {
    db_file_.close();
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

  MutMap<file_id_t, block_id_t> next_block_ids_;

  // std::atomic<page_id_t> next_page_id_{0};


  fstream db_file_, log_io_;

  // stream to write db file
  int num_flushes_;
  UNUSED int num_writes_;
  bool flush_log_;
  std::future<void> *flush_log_f_{nullptr};
};
