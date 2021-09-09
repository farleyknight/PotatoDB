#pragma once

#include "disk/file_mgr.hpp"

class IndexFileMgr : public FileMgr {
public:
  const string             FILE_EXTENSION   = ".idx";
  static constexpr int32_t HEADER_BLOCK_NUM = 0;
  static constexpr int32_t FIRST_BLOCK_NUM  = 1;

  IndexFileMgr() {}

  void
  close() {
    // TODO: Close all file handles
  }

  void
  remove_index_files() {
    for (const auto & [file_path, file_id] : index_file_ids_) {
      remove_file(file_path);
    }
  }

  vector<file_id_t>
  index_file_ids() const {
    vector<file_id_t> file_ids;
    for (const auto & [file_path, file_id] : index_file_ids_) {
      file_ids.push_back(file_id);
    }
    return file_ids;
  }

  index_oid_t
  index_oid_for(file_id_t file_id) const {
    assert(index_oid_to_file_id_.contains(file_id));
    return index_oid_to_file_id_.at(file_id);
  }

  file_id_t
  file_id_for(index_oid_t index_oid) const {
    assert(index_oid_to_file_id_.contains(index_oid));
    return index_oid_to_file_id_.at(index_oid);
  }

  void
  create_index_file(file_id_t file_id, const file_path_t& file_path) {
    assert(!file_exists(file_path));
    load_file_handle(file_id, file_path);
  }

  void
  open_index_file(file_id_t file_id, const file_path_t& file_path) {
    assert(file_exists(file_path));
    load_file_handle(file_id, file_path);
  }

  fs::path
  index_file_for(const index_name_t& index_name) const {
    return file_path_for(index_name + FILE_EXTENSION);
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
    assert(index_file_handles_.contains(file_id));

    index_file_handles_[file_id]->write_buffer(offset, buffer);
  }

  void
  read_buffer(PageId page_id, Buffer& buffer) {
    auto file_id = page_id.file_id();
    auto offset  = page_id.block_id() * buffer.size();
    assert(index_file_handles_.contains(file_id));

    index_file_handles_[file_id]->read_buffer(offset, buffer);
  }

  bool
  is_index_file(file_id_t file_id) {
    return index_file_handles_.contains(file_id);
  }

  void
  deallocate_page(PageId page_id) {
    auto file_id = page_id.file_id();
    auto offset  = page_id.block_id() * PAGE_SIZE;
    index_file_handles_[file_id]->resize(offset);
  }

private:
  // TODO: This method is duplicated in TableFileMgr.
  // We're waiting until we start adding ML capabilities
  // before refactoring it out into a superclass.
  void
  load_file_handle(file_id_t file_id,
                   const file_path_t& file_path)
  {
    auto handle = make_unique<FileHandle>(file_id, file_path);
    index_file_handles_.emplace(file_id, move(handle));
  }

  void
  load_index_oid_to_file_id(index_oid_t index_oid,
                            file_id_t file_id)
  {
    index_oid_to_file_id_[index_oid] = file_id;
    file_id_to_index_oid_[file_id]   = index_oid;
  }

  map<index_oid_t, file_id_t> index_oid_to_file_id_;
  map<file_id_t, index_oid_t> file_id_to_index_oid_;

  map<file_path_t, file_id_t> index_file_ids_;

  map<file_id_t, ptr<FileHandle>> index_file_handles_;
};
