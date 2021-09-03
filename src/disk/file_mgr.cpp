#include "disk/file_mgr.hpp"

void FileMgr::write_buffer(PageId page_id, const Buffer& buffer) {
  auto file_id = page_id.file_id();
  auto offset  = page_id.block_id() * buffer.size();
  assert(file_handles_.contains(file_id));

  logger->debug("[FileMgr] Writing buffer to file_id " +
                std::to_string(file_id));
  logger->debug("[FileMgr] Buffer offset " +
                std::to_string(offset));
  logger->debug("[FileMgr] File name: " +
                file_handles_[file_id]->file_path());
  logger->debug("[FileMgr] File size: " +
                std::to_string(file_handles_[file_id]->size()));

  file_handles_[file_id]->write_buffer(offset, buffer);
}

vector<file_id_t> FileMgr::table_file_ids() {
  vector<file_id_t> file_ids;
  auto dir_iter = fs::directory_iterator(db_directory());
  for (const auto &entry : dir_iter) {
    if (entry.path().extension() == ".tbl") {
      file_ids.push_back(file_id_for(entry.path()));
    }
  }

  return file_ids;
}

vector<file_id_t> FileMgr::index_file_ids() {
  vector<file_id_t> file_ids;
  auto dir_iter = fs::directory_iterator(db_directory());
  for (const auto &entry : dir_iter) {
    if (entry.path().extension() == ".idx") {
      file_ids.push_back(file_id_for(entry.path()));
    }
  }

  return file_ids;
}

file_id_t FileMgr::file_id_for(fs::path file_path) {
  auto path_as_string = file_path.c_str();
  assert(file_ids_.contains(path_as_string));
  return file_ids_[path_as_string];
}

file_id_t FileMgr::open_file(fs::path file_path) {
  auto path_as_string = file_path.c_str();

  auto file_id = next_file_id_++;
  file_ids_.insert(make_pair(path_as_string, file_id));

  auto handle         = make_unique<FileHandle>(file_path);
  file_handles_.insert(make_pair(file_id, move(handle)));

  return file_id;
}

void FileMgr::read_buffer(PageId page_id, Buffer& buffer) {
  file_id_t file_id = page_id.file_id();
  buffer_offset_t offset = page_id.block_id() * buffer.size();
  assert(file_handles_.contains(file_id));

  logger->debug("[FileMgr] Reading buffer at file_id " +
                std::to_string(file_id));
  logger->debug("[FileMgr] Reading block_id " +
                std::to_string(page_id.block_id()));

  logger->debug("[FileMgr] Buffer offset " +
                std::to_string(offset));
  logger->debug("[FileMgr] File name: " +
                file_handles_[file_id]->file_path());
  logger->debug("[FileMgr] File size: " +
                std::to_string(file_handles_[file_id]->size()));

  file_handles_[file_id]->read_buffer(offset, buffer);
}

void FileMgr::remove_table_files() {
  auto iter = fs::directory_iterator(db_directory());
  for (const auto &entry : iter) {
    if (entry.path().extension() == ".tbl") {
      remove_file(entry.path());
    }
  }
}

bool FileMgr::read_log(LogFileCursor& cursor) {
  try {
    auto &log_io = log_file_->io();
    log_io.exceptions(std::ios::failbit);
    int32_t file_size = fs::file_size(log_file_name());

    if (cursor.file_offset() >= file_size) {
      logger->debug("[DiskMgr] Cursor trying to read past file size!");
      return false;
    }
    cursor.buffer_reset();

    int32_t amount_remaining = file_size - cursor.file_offset();
    int32_t buffer_size      = cursor.buffer().size();
    int32_t amount_to_read   = std::min(buffer_size, amount_remaining);

    log_io.seekp(cursor.file_offset());
    log_io.read(cursor.buffer().char_ptr(), amount_to_read);

    int32_t read_count = log_io.gcount();
    if (read_count < amount_to_read) {
      log_io.clear();
      std::memset(cursor.buffer().ptr(read_count),
                  0, amount_to_read - read_count);
      logger->debug("[DiskMgr] Read too few bytes. Zeroing out what we did read.");
      return false;
    }

    return true;
  } catch (std::ios_base::failure& e) {
    logger->debug("[DiskMgr] Log file reading failed! :(");
    logger->debug("[DiskMgr] Failure was " + std::string(e.what()));
  }
  return false;
}

void FileMgr::write_log(const Buffer& log_data, buffer_offset_t offset) {
  try {
    auto &log_io = log_file_->io();
    log_io.exceptions(std::ios::failbit);

    // no effect on num_flushes_ if log buffer is empty
    if (offset == 0) {
      logger->debug("[DiskMgr] No data to write! Returning early");
      return;
    }

    if (flush_log_func_ != nullptr) {
      // used for checking non-blocking flushing
      assert(flush_log_func_->wait_for(std::chrono::seconds(10)) ==
             std::future_status::ready);
    }

    log_io.write(log_data.char_ptr(), offset);
    log_io.flush();

    auto file_size = fs::file_size(log_file_name());
    assert(file_size > 0);
  } catch (std::ios_base::failure& e) {
    logger->debug("[DiskMgr] Log file writing failed! :(");
    logger->debug("[DiskMgr] Failure was " + std::string(e.what()));
  }
}

// TODO:
// 1) allocate_page should take a file_id
// 2) keep track of all file_ids
// 3) on each call to `allocate_path`, increment a counter just for
//    that particular file_id
PageId FileMgr::allocate_page(file_id_t file_id) {
  // TODO! Implement in "CREATE TABLE"
  // or "CREATE INDEX" context.

  if (next_block_ids_.contains(file_id)) {
    next_block_ids_[file_id] = TABLE_CONTENT_BLOCK_NUM;
  } else {
    next_block_ids_[file_id]++;
  }

  file_handles_[file_id]->resize(next_block_ids_[file_id] * PAGE_SIZE);

  return PageId(file_id, next_block_ids_[file_id]);
}

PageId FileMgr::first_table_page(file_id_t file_id) {
  return PageId(file_id, TABLE_CONTENT_BLOCK_NUM);
}

PageId FileMgr::table_header_page(file_id_t file_id) {
  return PageId(file_id, TABLE_HEADER_BLOCK_NUM);
}

PageId FileMgr::first_index_page(file_id_t file_id) {
  return PageId(file_id, TABLE_CONTENT_BLOCK_NUM);
}

PageId FileMgr::index_header_page(file_id_t file_id) {
  return PageId(file_id, INDEX_HEADER_BLOCK_NUM);
}

void FileMgr::delete_log_file() {
  log_file_->close();
  fs::remove(log_file_name());
}

void FileMgr::truncate_log_file() {
  fs::resize_file(log_file_name(), 0);
}

void FileMgr::deallocate_page(PageId page_id) {
  /*
   * Deallocate page (operations like drop index/table)
   * Need bitmap in header page for tracking pages
   */
  // TODO! Implement in "DROP TABLE" or "DROP INDEX" context.

  auto file_id = page_id.file_id();
  assert(next_block_ids_[file_id] < page_id.block_id());
  auto new_size = (page_id.block_id() - 1) * PAGE_SIZE;

  file_handles_[file_id]->resize(new_size);
}

void FileMgr::setup_log_file() {
  auto handle = make_unique<FileHandle>(log_file_name());
  log_file_ = move(handle);
}

/*
 *

void FileMgr::setup_log_file() {
  log_io_.exceptions(std::ios::goodbit);
  log_io_.clear();
  log_io_.open(log_file_name(),
               std::ios::binary |
               std::ios::in |
               std::ios::app |
               std::ios::out);

  // directory or file does not exist
  if (!log_io_.is_open()) {
    log_io_.clear();
    // create a new file
    log_io_.open(log_file_name(),
                 std::ios::binary |
                 std::ios::trunc |
                 std::ios::app |
                 std::ios::out);
    log_io_.close();
    // reopen with original mode
    log_io_.open(log_file_name(),
                 std::ios::binary |
                 std::ios::in |
                 std::ios::app |
                 std::ios::out);
   if (!log_io_.is_open()) {
      throw Exception(ExceptionType::BAD_FILE,
                      "Can't open DB log file");
    }
  }

  try {
    log_io_.clear();
    log_io_.exceptions(std::ios::failbit);
  } catch (std::ios_base::failure& e) {
    logger->debug("[FileMgr] Log file setup failed! :(");
    logger->debug("[FileMgr] Failure was " + std::string(e.what()));
  }
}


 */
