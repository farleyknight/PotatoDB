#include "disk/file_mgr.hpp"


// TODO: Let's move the DiskMgr::write_log stuff into this class?

void FileMgr::write_buffer(PageId page_id, const Buffer& buffer) {
  file_id_t file_id = page_id.file_id();
  buffer_offset_t offset = page_id.block_id() * buffer.size();
  assert(files_.size() > file_id);

  logger->debug("[FileMgr] Writing buffer to file_id " + std::to_string(file_id));
  logger->debug("[FileMgr] Buffer offset " + std::to_string(offset));
  logger->debug("[FileMgr] File name: " + files_[file_id]->file_path());
  logger->debug("[FileMgr] File size: " + std::to_string(files_[file_id]->size()));

  files_[file_id]->write_buffer(offset, buffer);
}

void FileMgr::read_buffer(PageId page_id, Buffer& buffer) {
  file_id_t file_id = page_id.file_id();
  buffer_offset_t offset = page_id.block_id() * buffer.size();
  assert(files_.size() > file_id);

  logger->debug("[FileMgr] Reading buffer at file_id " + std::to_string(file_id));
  logger->debug("[FileMgr] Reading block_id " + std::to_string(page_id.block_id()));

  logger->debug("[FileMgr] Buffer offset " + std::to_string(offset));
  logger->debug("[FileMgr] File name: " + files_[file_id]->file_path());
  logger->debug("[FileMgr] File size: " + std::to_string(files_[file_id]->size()));

  files_[file_id]->read_buffer(offset, buffer);
}

// TODO:
// 1) allocate_page should take a file_id
// 2) keep track of all file_ids
// 3) on each call to `allocate_path`, increment a counter just for
//    that particular file_id
PageId FileMgr::allocate_new_page(file_id_t file_id) {
  // TODO! Implement in "CREATE TABLE"
  // or "CREATE INDEX" context.

  if (next_block_ids_.count(file_id) == 0) {
    next_block_ids_[file_id] = TABLE_CONTENT_BLOCK_NUM;
  } else {
    next_block_ids_[file_id]++;
  }

  files_[file_id]->grow(next_block_ids_[file_id] * PAGE_SIZE);

  return PageId(file_id, next_block_ids_[file_id]);
}

PageId FileMgr::first_table_page(file_id_t file_id) {
  assert(next_block_ids_.count(file_id) == 0);
  next_block_ids_[file_id] = TABLE_CONTENT_BLOCK_NUM;
  return PageId(file_id, next_block_ids_[file_id]);
}

PageId FileMgr::table_header(file_id_t file_id) {
  return PageId(file_id, TABLE_HEADER_BLOCK_NUM);
}

void FileMgr::deallocate_existing_page(file_id_t file_id, PageId page_id) {
  /*
   * Deallocate page (operations like drop index/table)
   * Need bitmap in header page for tracking pages
   */
  // TODO! Implement in "DROP TABLE" or "DROP INDEX" context.

  assert(next_block_ids_[file_id] < page_id.block_id());
  auto new_size = (page_id.block_id() + 1) * PAGE_SIZE;

  files_[file_id]->shrink(new_size);
}
