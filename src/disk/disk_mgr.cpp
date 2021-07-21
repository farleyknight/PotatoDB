// Provide database file name.
// Open a connection to the file handle.

#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

DiskMgr::DiskMgr(FileMgr& file_mgr)
  : file_mgr_    (file_mgr),
    flush_log_f_ (nullptr)
{
  std::cout << "Creating DiskMgr" << std::endl;
  setup_db_directory();
  setup_log_file();
}

void DiskMgr::delete_log_file() {
  log_io_.close();
  fs::remove(log_file_name());
}

void DiskMgr::setup_log_file() {
  std::cout << "First time attempting to open" << std::endl;
  log_io_.clear();
  log_io_.open(log_file_name(),
               std::ios::binary |
               std::ios::in |
               std::ios::app |
               std::ios::out);

  // directory or file does not exist
  if (!log_io_.is_open()) {
    std::cout << "Log file is not open, clearing" << std::endl;
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
    std::cout << "Log file open failed! :(" << std::endl;
    std::cout << e.what() << std::endl;
    std::cout << "Error code: " << e.code().value() << std::endl;
    std::cout << "Error message: " << e.code().message() << std::endl;
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

// NOTE: A BufferCursor is basically a buffer with an `offset_`
bool DiskMgr::read_log(BufferCursor& cursor) {
  if (cursor.file_offset() >= fs::file_size(log_file_name())) {
    std::cout << "Cursor trying to read past file size!" << std::endl;
    std::cout << "File offset: " << cursor.file_offset() << std::endl;
    std::cout << "File size: " << fs::file_size(log_file_name()) << std::endl;
    return false;
  }

  // NOTE: Always try to fill up the buffer we are given with bytes from disk
  auto amount_to_read = cursor.buffer().size() - cursor.buffer_offset();

  // NOTE: Move to the disk cursor offset and read in our bytes
  log_io_.seekp(cursor.file_offset());
  log_io_.read(cursor.buffer().char_ptr(), amount_to_read);

  // NOTE: If something bad happened, let's return immediately
  // TODO: We should try and report extra details of the error
  // message if we can.
  if (log_io_.bad()) {
    std::cout << "Bad I/O when reading from log" << std::endl;
    return false;
  }

  // NOTE: Check if we have disk problems and cannot read the full
  // number of requested bytes.
  size_t read_count = log_io_.gcount();
  if (read_count < amount_to_read) {
    log_io_.clear();
    // NOTE: If we read too little bytes, zero-out the bytes that
    // we did read in.
    std::memset(cursor.buffer().ptr(read_count), 0, amount_to_read - read_count);
    std::cout << "Read too few bytes. Zeroing out what we did read." << std::endl;
    return false;
  }

  return true;
}

// TODO: Move this method to another class that is more appropriate
// for direct file access. Maybe FileMgr?
void DiskMgr::write_log(const Buffer& log_data) {
  try {
    std::cout << "Setting fail bit to raise exception " << std::endl;
    log_io_.exceptions(std::ios::failbit);

    // no effect on num_flushes_ if log buffer is empty
    if (log_data.size() == 0) {
      std::cout << "No data to write! Returning early" << std::endl;
      return;
    }

    if (flush_log_f_ != nullptr) {
      // used for checking non-blocking flushing
      assert(flush_log_f_->wait_for(std::chrono::seconds(10)) ==
             std::future_status::ready);
    }

    // sequence write
    std::cout << "Performing write to log file" << std::endl;
    log_io_.write(log_data.char_ptr(), log_data.size());
  } catch (std::ios_base::failure& e) {
    std::cout << "Log file writing failed! :(" << std::endl;
    std::cout << e.what() << std::endl;
  }

  // check for I/O error
  if (log_io_.bad()) {
    std::cout << "For write_log - Bad I/O :(" << std::endl;
    return;
  }

  if (log_io_.eof()) {
    std::cout << "For write_log - EOF :(" << std::endl;
    return;
  }

  if (log_io_.fail()) {
    std::cout << "For write_log - Fail I/O :(" << std::endl;
    return;
  }

  // needs to flush to keep disk file in sync
  std::cout << "Flushing to disk" << std::endl;
  log_io_.flush();

  std::cout << "File size is now: " << log_io_.tellp() << std::endl;
}
