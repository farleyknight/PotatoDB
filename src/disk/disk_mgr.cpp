// Provide database file name.
// Open a connection to the file handle.

#include <algorithm>
#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

DiskMgr::DiskMgr(FileMgr& file_mgr)
  : file_mgr_    (file_mgr),
    flush_log_f_ (nullptr)
{
  setup_db_directory();
  setup_log_file();
}

void DiskMgr::delete_log_file() {
  log_io_.close();
  fs::remove(log_file_name());
}

// TODO: Rename to `create_log_file()`
// TODO: We shouldn't have to be creating files here!
// Instead, we should have some "SetupMgr" that creates the directory plus any files needed.
// SetupMgr would be responsible for:
// 1) Creating the log file
// 2) Creating the system catalog
// 3) ???

void DiskMgr::setup_log_file() {
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
    logger->debug("[DiskMgr] Log file setup failed! :(");
    logger->debug("[DiskMgr] Failure was " + std::string(e.what()));
  }
}

file_id_t DiskMgr::create_table_file(const string& table_name) {
  return file_mgr_.create_file(table_file_for(table_name));
}

file_id_t DiskMgr::load_table_file(const string& table_name) {
  return file_mgr_.load_file(table_file_for(table_name));
}

fs::path DiskMgr::table_file_for(const string& table_name) const {
  return file_path_for(table_name + ".tbl");
}

void DiskMgr::setup_db_directory() {
  fs::current_path(home_path());
  fs::create_directory(".potatodb");
  fs::current_path(home_path() / ".potatodb");
}

PageId DiskMgr::allocate_page(file_id_t file_id) {
  return file_mgr_.allocate_page(file_id);
}

PageId DiskMgr::first_page(file_id_t file_id) {
  return file_mgr_.first_page(file_id);
}

void DiskMgr::deallocate_page(PageId page_id) {
  file_mgr_.deallocate_page(page_id);
}

void DiskMgr::write_page(PageId page_id, const Page& page) {
  file_mgr_.write_buffer(page_id, page.buffer());
}

void DiskMgr::read_page(PageId page_id, Page& page) {
  file_mgr_.read_buffer(page_id, page.buffer());
}

bool DiskMgr::read_log(LogFileCursor& cursor) {
  try {
    log_io_.exceptions(std::ios::failbit);
    int32_t file_size = fs::file_size(log_file_name());

    if (cursor.file_offset() >= file_size) {
      logger->debug("[DiskMgr] Cursor trying to read past file size!");
      return false;
    }
    cursor.buffer_reset();

    int32_t amount_remaining = file_size - cursor.file_offset();
    int32_t buffer_size      = cursor.buffer().size();
    int32_t amount_to_read   = std::min(buffer_size, amount_remaining);

    log_io_.seekp(cursor.file_offset());
    log_io_.read(cursor.buffer().char_ptr(), amount_to_read);

    size_t read_count = log_io_.gcount();
    if (read_count < amount_to_read) {
      log_io_.clear();
      std::memset(cursor.buffer().ptr(read_count), 0, amount_to_read - read_count);
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

// TODO: Move this method to another class that is more appropriate
// for direct file access. Maybe FileMgr?
void DiskMgr::write_log(const Buffer& log_data, buffer_offset_t offset) {
  try {
    log_io_.exceptions(std::ios::failbit);

    // no effect on num_flushes_ if log buffer is empty
    if (offset == 0) {
      logger->debug("[DiskMgr] No data to write! Returning early");
      return;
    }

    if (flush_log_f_ != nullptr) {
      // used for checking non-blocking flushing
      assert(flush_log_f_->wait_for(std::chrono::seconds(10)) ==
             std::future_status::ready);
    }

    log_io_.write(log_data.char_ptr(), offset);
    log_io_.flush();

    auto file_size = fs::file_size(log_file_name());
    assert(file_size > 0);
  } catch (std::ios_base::failure& e) {
    logger->debug("[DiskMgr] Log file writing failed! :(");
    logger->debug("[DiskMgr] Failure was " + std::string(e.what()));
  }
}
