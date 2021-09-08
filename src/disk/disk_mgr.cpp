// Provide database file name.
// Open a connection to the file handle.

#include <algorithm>
#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

file_id_t
DiskMgr::file_id_for(fs::path file_path) {
  auto path_as_string = file_path.c_str();
  assert(file_ids_.contains(path_as_string));
  return file_ids_[path_as_string];
}

file_id_t
DiskMgr::open_table_file(fs::path file_path) {
  auto path_as_string = file_path.c_str();

  // file_ids should live in DiskMgr
  auto file_id = next_file_id_++;
  file_ids_[path_as_string] = file_id;

  table_file_mgr_.open_file(file_id, file_path);

  return file_id;
}
