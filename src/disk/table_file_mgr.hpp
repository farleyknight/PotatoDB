#pragma once

#include "disk/file_mgr.hpp"

class TableFileMgr : public FileMgr {
public:
  const string         FILE_EXTENSION   = ".tbl";
  static const int32_t HEADER_BLOCK_NUM = 0;
  static const int32_t FIRST_BLOCK_NUM  = 1;

  TableFileMgr() {}

  void
  close() {
    // TODO: Close all file handles
  }

  void
  remove_table_files() {
    for (const auto & [file_path, file_id] : table_file_ids_) {
      remove_file(file_path);
    }
  }

  vector<file_id_t>
  table_file_ids() const {
    vector<file_id_t> file_ids;
    for (const auto & [file_path, file_id] : table_file_ids_) {
      file_ids.push_back(file_id);
    }
    return file_ids;
  }

  table_oid_t
  table_oid_for(file_id_t file_id) const {
    assert(file_id_to_table_oid_.contains(file_id));
    return file_id_to_table_oid_.at(file_id);
  }

  file_id_t
  file_id_for(table_oid_t table_oid) const {
    assert(table_oid_to_file_id_.contains(table_oid));
    return table_oid_to_file_id_.at(table_oid);
  }

  fs::path
  table_file_for(const table_name_t& table_name) const {
    // TODO: We should probably put all tables under the directory `tables/`
    return file_path_for(table_name + FILE_EXTENSION);
  }

  void
  create_table_file(file_id_t file_id, const file_path_t& file_path) {
    assert(!file_exists(file_path));
    load_file_handle(file_id, file_path);
  }

  void
  open_table_file(file_id_t file_id, const file_path_t& file_path) {
    assert(file_exists(file_path));
    load_file_handle(file_id, file_path);
  }

  PageId
  first_page(file_id_t file_id) {
    return PageId(file_id, FIRST_BLOCK_NUM);
  }

  PageId
  header_page(file_id_t file_id) {
    return PageId(file_id, HEADER_BLOCK_NUM);
  }

  void
  write_buffer(PageId page_id, const Buffer& buffer) {
    auto file_id = page_id.file_id();
    auto offset  = page_id.block_id() * buffer.size();
    assert(table_file_handles_.contains(file_id));

    table_file_handles_[file_id]->write_buffer(offset, buffer);
  }

  void
  read_buffer(PageId page_id, Buffer& buffer) {
    auto file_id = page_id.file_id();
    auto offset  = page_id.block_id() * buffer.size();
    assert(table_file_handles_.contains(file_id));

    table_file_handles_[file_id]->read_buffer(offset, buffer);
  }

  bool
  is_table_file(file_id_t file_id) {
    return table_file_handles_.contains(file_id);
  }

  void
  deallocate_page(PageId page_id) {
    auto file_id = page_id.file_id();
    auto offset  = page_id.block_id() * PAGE_SIZE;
    table_file_handles_[file_id]->resize(offset);
  }

private:
  // TODO: This method is duplicated in IndexFileMgr.
  // We're waiting until we start adding ML capabilities before
  // refactoring it out into a superclass.
  void
  load_file_handle(file_id_t file_id, const file_path_t& file_path) {
    auto handle
      = make_unique<FileHandle>(file_id, file_path);
    table_file_ids_.emplace(file_path, file_id);
    table_file_handles_.emplace(file_id, move(handle));
  }

  void
  load_table_oid_to_file_id(table_oid_t table_oid, file_id_t file_id) {
    table_oid_to_file_id_[table_oid] = file_id;
    file_id_to_table_oid_[file_id]   = table_oid;
  }

  map<table_oid_t, file_id_t> table_oid_to_file_id_;
  map<file_id_t, table_oid_t> file_id_to_table_oid_;

  map<file_path_t, file_id_t> table_file_ids_;
  map<file_id_t, ptr<FileHandle>> table_file_handles_;
};
