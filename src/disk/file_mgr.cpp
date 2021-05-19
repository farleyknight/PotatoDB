#include "disk/file_mgr.hpp"

void FileMgr::write_buffer(PageId page_id, const Buffer& buffer) {
  file_id_t file_id = page_id.file_id();
  buffer_offset_t offset = page_id.block_id() * buffer.size();
  files_[file_id]->write_buffer(offset, buffer);
}

void FileMgr::read_buffer(PageId page_id, Buffer& buffer) {
  file_id_t file_id = page_id.file_id();
  buffer_offset_t offset = page_id.block_id() * buffer.size();
  files_[file_id]->read_buffer(offset, buffer);
}

// TODO:
// 1) allocate_page should take a file_id
// 2) keep track fo all file_ids
// 3) on each call to `allocate_path`, increment a counter just for
//    that particular file_id
PageId FileMgr::allocate_page(file_id_t file_id) {
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

void FileMgr::deallocate_page(UNUSED PageId page_id) {
  /*
   * Deallocate page (operations like drop index/table)
   * Need bitmap in header page for tracking pages
   * This does not actually need to do anything for now.
   */
  // TODO! Implement in "DROP TABLE" or "DROP INDEX" context.
}
