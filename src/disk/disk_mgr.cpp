// Provide database file name.
// Open a connection to the file handle.

#include <algorithm>
#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

file_id_t
DiskMgr::file_id_for(fs::path file_path) const {
  auto path_as_string = file_path.c_str();
  assert(file_ids_.contains(path_as_string));
  return file_ids_.at(path_as_string);
}

file_id_t
DiskMgr::open_table_file(fs::path file_path) {
  auto path_as_string = file_path.c_str();

  auto file_id = next_file_id_++;
  file_ids_[path_as_string] = file_id;

  table_file_mgr_.open_table_file(file_id, path_as_string);

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
