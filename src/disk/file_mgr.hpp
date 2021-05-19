#pragma once

#include <iostream>

#include "disk/file_handle.hpp"
#include "page/page_id.hpp"

class FileMgr {
public:
  FileMgr() {}

  void load_files() {
    // TODO
    // 1) List all files under the DB directory ($HOME/.potatodb)
    // 2) Create a file handle for each one, add it to `files_`
  }

  void write_buffer(PageId page_id, const Buffer& buffer);
  void read_buffer(PageId page_id, Buffer& buffer);

  void deallocate_page(UNUSED PageId page_id);
  PageId allocate_page(file_id_t file_id);

  file_id_t create_file(fs::path file_path) {
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
  vector<ptr<FileHandle>> files_;
};
