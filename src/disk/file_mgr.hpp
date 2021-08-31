#pragma once

#include <iostream>

#include "disk/file_handle.hpp"

#include "page/page_id.hpp"
#include "page/page.hpp"
#include "recovery/log_file_cursor.hpp"

class FileMgr {
public:
  static constexpr int32_t TABLE_HEADER_BLOCK_NUM = 0;
  static constexpr int32_t TABLE_CONTENT_BLOCK_NUM = 1;

  static constexpr int32_t INDEX_HEADER_BLOCK_NUM = 0;
  static constexpr int32_t INDEX_CONTENT_BLOCK_NUM = 1;

  FileMgr() {
    setup_db_directory();
    create_log_file();
  }

  void write_buffer(PageId page_id, const Buffer& buffer);
  void read_buffer(PageId page_id, Buffer& buffer);

  void deallocate_page(PageId page_id);
  PageId allocate_page(file_id_t file_id);


  // NOTE: table_header_page returns a PageId
  //
  // This is essentially the first block of the .tbl file
  //
  // This is also where we store the schema for the SQL table itself.
  // We load up the schema into in-memory data structures
  // (basically maps and vectors)
  //
  // We should do any SQL queries by looking at values in those structures.
  //
  // Therefore, we must read the first page of each file once during
  // system start-up, to load the proper schema.
  //
  static PageId table_header_page(file_id_t file_id);
  static PageId first_table_page(file_id_t file_id);

  static PageId index_header_page(file_id_t file_id);
  static PageId first_index_page(file_id_t file_id);

  file_id_t create_table_file(const string& table_name) {
    // TODO: assert file does not already exist!
    return open_file(table_file_for(table_name));
  }

  void setup_db_directory() {
    fs::current_path(home_path());
    fs::create_directory(".potatodb");
    fs::current_path(home_path() / ".potatodb");
  }

  void shutdown() {
    // TODO Close all file handles, not just the log
    log_file_->close();
  }

  file_id_t create_index_file(const string& table_name) {
    // TODO: assert file does not already exist!
    return open_file(index_file_for(table_name));
  }

  file_id_t load_table_file(const string& table_name) {
    // TODO: assert file already exists!
    return open_file(table_file_for(table_name));
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

  void write_log(const Buffer& log_data, buffer_offset_t offset);
  bool read_log(LogFileCursor& cursor);

  bool table_file_exists(const string& table_name) const {
    logger->debug("[DiskMgr] Checking if there is a table file for : "
                  + table_name);
    return file_exists(table_file_for(table_name));
  }

  void create_log_file() {
    log_file_ = make_unique<FileHandle>(log_file_name());
  }

  void remove_table_files();

  void write_page(PageId page_id, const Page& page) {
    write_buffer(page_id, page.buffer());
  }

  void read_page(PageId page_id, Page& page) {
    read_buffer(page_id, page.buffer());
  }

  vector<file_id_t> table_file_ids();
  vector<file_id_t> index_file_ids();
  file_id_t file_id_for(fs::path file_path);

  file_id_t open_file(fs::path file_path);

  void remove_file(fs::path file_path) const {
    // TODO: Maybe close the FileHandle before removing the file?
    fs::remove(file_path);
  }

  bool file_exists(fs::path file_path) const {
    return fs::exists(file_path);
  }

  void setup_log_file();
  void delete_log_file();
  void truncate_log_file();

private:
  // TODO: This should live in the FileHandle I think?
  map<file_id_t, block_id_t> next_block_ids_;
  ptr<FileHandle> log_file_ {nullptr};

  map<file_id_t, ptr<FileHandle>> file_handles_;
  // NOTE: string here is just the file_path.string()
  map<string, file_id_t> file_ids_;

  atomic<file_id_t> next_file_id_ = 0;

  std::future<void> *flush_log_func_ {nullptr};
};
