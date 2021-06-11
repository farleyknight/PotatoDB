// Provide database file name.
// Open a connection to the file handle.

#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

DiskMgr::DiskMgr(FileMgr& file_mgr)
  : file_mgr_    (file_mgr),
    flush_log_f_ (nullptr)
{
  setup_db_directory();
  setup_log_file();
}

void DiskMgr::setup_log_file() {
  // TODO: Move this to a logger
  // std::cout << "Opening log with name " << log_file_name() << std::endl;

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

// TODO: Move this method to another class that is more appropriate
// for direct file access. Maybe FileMgr?
bool DiskMgr::read_log(Buffer& log_data,
                       buffer_offset_t offset)
{
  auto size = log_data.size();
  if (offset >= fs::file_size(log_file_name())) {
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

// TODO: Move this method to another class that is more appropriate
// for direct file access. Maybe FileMgr?
void DiskMgr::write_log(const Buffer& log_data) {
  // no effect on num_flushes_ if log buffer is empty
  if (log_data.size() == 0) {
    return;
  }

  if (flush_log_f_ != nullptr) {
    // used for checking non-blocking flushing
    assert(flush_log_f_->wait_for(std::chrono::seconds(10)) ==
           std::future_status::ready);
  }

  // sequence write
  log_io_.write(log_data.char_ptr(), log_data.size());

  // check for I/O error
  if (log_io_.bad()) {
    return;
  }
  // needs to flush to keep disk file in sync
  log_io_.flush();
}
