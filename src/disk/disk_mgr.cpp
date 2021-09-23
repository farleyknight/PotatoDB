// Open a connection to the file handle.
// Provide database file name.

#include <algorithm>
#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

file_id_t
DiskMgr::file_id_for(fs::path file_path) const {
  assert(file_ids_.contains(file_path));
  return file_ids_.at(file_path);
}

file_id_t
DiskMgr::open_table_file(fs::path file_path) {
  auto file_id = next_file_id_++;
  file_ids_.emplace(file_path.c_str(), file_id);
  table_file_mgr_.open_table_file(file_id, file_path);
  return file_id;
}

void
DiskMgr::write_buffer(PageId page_id, const Buffer& buffer) {
  auto file_id = page_id.file_id();

  if (is_table_file(file_id)) {
    table_file_mgr_.write_buffer(page_id, buffer);
  } else if (is_index_file(file_id)) {
    index_file_mgr_.write_buffer(page_id, buffer);
  } else {
    throw Exception("The file ID did not match any existing files!");
  }
}

void
DiskMgr::read_buffer(PageId page_id, Buffer& buffer) {
  auto file_id = page_id.file_id();

  if (is_table_file(file_id)) {
    table_file_mgr_.read_buffer(page_id, buffer);
  } else if (is_index_file(file_id)) {
    index_file_mgr_.read_buffer(page_id, buffer);
  } else {
    throw Exception("The file ID did not match any existing files!");
  }
}

void
DiskMgr::deallocate_page(PageId page_id) {
  auto file_id = page_id.file_id();

  if (is_table_file(file_id)) {
    table_file_mgr_.deallocate_page(page_id);
  } else if (is_index_file(file_id)) {
    index_file_mgr_.deallocate_page(page_id);
  } else {
    throw Exception("The file ID did not match any existing files!");
  }
}

void
DiskMgr::open_index_files() {
  auto iter = fs::directory_iterator(db_directory());
  for (const auto &entry : iter) {
    if (entry.path().extension() == index_file_mgr_.file_extension()) {
      open_index_file(entry.path());
    }
  }
}

void
DiskMgr::open_table_files() {
  auto iter = fs::directory_iterator(db_directory());
  for (const auto &entry : iter) {
    if (entry.path().extension() == table_file_mgr_.file_extension()) {
      open_table_file(entry);
    }
  }
}
