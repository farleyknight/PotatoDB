// Provide database file name.
// Open a connection to the file handle.

#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

/**********************************************
 *
 **********************************************/

DiskMgr::DiskMgr(string db_name)
  : next_page_id_ (0),
    db_name_      (db_name),
    flush_log_f_  (nullptr)
{
  String::size_type n = db_name_.rfind('.');
  if (n == String::npos) {
    throw Exception(ExceptionType::BAD_FILE, "Wrong file format");
  }

  log_name_ = db_name_.substr(0, n) + ".log";
  log_io_.open(log_name_,
               std::ios::binary |
               std::ios::in |
               std::ios::app |
               std::ios::out);

  // directory or file does not exist
  if (!log_io_.is_open()) {
    log_io_.clear();
    // create a new file
    log_io_.open(log_name_,
                 std::ios::binary |
                 std::ios::trunc |
                 std::ios::app |
                 std::ios::out);
    log_io_.close();
    // reopen with original mode
    log_io_.open(log_name_,
                 std::ios::binary |
                 std::ios::in |
                 std::ios::app |
                 std::ios::out);
    if (!log_io_.is_open()) {
      throw Exception(ExceptionType::BAD_FILE, "Can't open DB log file");
    }
  }

  // Create the file if it doesn't exist
  // https://www.systutorials.com/how-to-create-a-file-if-not-exist-and-open-it-in-read-and-write-modes-in-c/
  db_file_.open(db_name, std::ios::out | std::ios::app);
  // Close the file handle, then re-open so we can start using it.
  db_file_.close();
  db_file_.open(db_name_, std::ios::binary | std::ios::in | std::ios::out);
  if (!db_file_.is_open()) {
    throw Exception(ExceptionType::BAD_FILE, "Can't open db file "
                    + db_name);
  }
}

void DiskMgr::write_buffer(PageId page_id, CRef<Buffer> buffer) {
  int offset = page_id.block_id() * PAGE_SIZE;
  db_file_.seekp(offset);
  db_file_.write(buffer.char_ptr(), PAGE_SIZE);
  db_file_.flush();
}

/**********************************************
 * Write to page
 **********************************************/

void DiskMgr::write_page(PageId page_id, CRef<Page> page) {
  write_buffer(page_id, page.buffer());
}

/**********************************************
 * Read from buffer
 **********************************************/

void DiskMgr::read_buffer(PageId page_id, Buffer& buffer) {
  // First compute the offset
  int offset = page_id.block_id() * PAGE_SIZE;
  // Move file pointer to the offset.
  db_file_.seekp(offset);
  // Read the data into disk
  db_file_.read(buffer.char_ptr(), PAGE_SIZE);
}

/**********************************************
 * Read from page
 **********************************************/

void DiskMgr::read_page(PageId page_id, Page& page) {
  read_buffer(page_id, page.buffer());
}

/**********************************************
 *
 **********************************************/

bool DiskMgr::read_log(Buffer& log_data,
                       size_t size,
                       size_t offset)
{
  if (offset >= std::filesystem::file_size(log_name_)) {
    return false;
  }

  log_io_.seekp(offset);
  log_io_.read(log_data.char_ptr(), size);

  if (log_io_.bad()) {
    return false;
  }

  // if log file ends before reading "size"
  size_t read_count = log_io_.gcount();
  if (read_count < size) {
    log_io_.clear();
    std::memset(log_data.ptr(read_count), 0, size - read_count);
  }

  return true;
}

/**********************************************
 *
 **********************************************/

void DiskMgr::write_log(CRef<Buffer> log_data, size_t size) {
  if (size == 0) { // no effect on num_flushes_ if log buffer is empty
    return;
  }

  flush_log_ = true;

  if (flush_log_f_ != nullptr) {
    // used for checking non-blocking flushing
    assert(flush_log_f_->wait_for(std::chrono::seconds(10)) ==
           std::future_status::ready);
  }

  num_flushes_ += 1;
  // sequence write
  log_io_.write(log_data.char_ptr(), size);

  // check for I/O error
  if (log_io_.bad()) {
    return;
  }
  // needs to flush to keep disk file in sync
  log_io_.flush();
  flush_log_ = false;
}