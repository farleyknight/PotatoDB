// Provide database file name.
// Open a connection to the file handle.

#include "storage/disk_mgr.hpp"
#include "common/exception_type.hpp"

/**********************************************
 *
 **********************************************/

DiskMgr::DiskMgr(String db_name)
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
    throw Exception(ExceptionType::BAD_FILE, "Can't open db file " + db_name);
  }
}

/**********************************************
 * Write to buffer
 **********************************************/

void DiskMgr::write_buffer(page_id_t page_id, MutRawPtr<char> buffer) {
  // First compute the offset
  int offset = page_id * PAGE_SIZE; // Defined in config above as 4KB
  // Move file pointer to the offset.
  db_file_.seekp(offset);
  // Write the page data, given the PAGE_SIZE
  db_file_.write(buffer, PAGE_SIZE);
  // Flush to disk!
  db_file_.flush();
}

/**********************************************
 * Write to page
 **********************************************/

void DiskMgr::write_page(page_id_t page_id, MRef<Page> page) {
  write_buffer(page_id, page.data());
}

/**********************************************
 * Read from buffer
 **********************************************/

void DiskMgr::read_buffer(page_id_t page_id, MutRawPtr<char> buffer) {
  // First compute the offset
  int offset = page_id * PAGE_SIZE; // Defined in config above as 4KB
  // Move file pointer to the offset.
  db_file_.seekp(offset);
  // Read the data into disk
  // TODO: Find a way to get rid of this ugly C-ism
  db_file_.read(buffer, PAGE_SIZE);
}

/**********************************************
 * Read from page
 **********************************************/

void DiskMgr::read_page(page_id_t page_id, MRef<Page> page) {
  read_buffer(page_id, page.data());
}

/**********************************************
 *
 **********************************************/

bool DiskMgr::read_log(MutRawPtr<char> log_data,
                       int size,
                       int offset)
{
  if (offset >= std::filesystem::file_size(log_name_)) {
    return false;
  }

  log_io_.seekp(offset);
  log_io_.read(log_data, size);

  if (log_io_.bad()) {
    return false;
  }

  // if log file ends before reading "size"
  int read_count = log_io_.gcount();
  if (read_count < size) {
    log_io_.clear();
    memset(log_data + read_count, 0, size - read_count);
  }

  return true;
}

/**********************************************
 *
 **********************************************/

void DiskMgr::write_log(RawPtr<char> log_data, int size) {
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
  log_io_.write(log_data, size);

  // check for I/O error
  if (log_io_.bad()) {
    return;
  }
  // needs to flush to keep disk file in sync
  log_io_.flush();
  flush_log_ = false;
}
