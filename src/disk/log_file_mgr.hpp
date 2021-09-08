#pragma once

class LogFileMgr : public FileMgr {
public:

  void delete_log_file() {
    log_file_->close();
    fs::remove(log_file_name());
  }

  void truncate_log_file() {
    fs::resize_file(log_file_name(), 0);
  }

  fs::path log_file_name() const {
    return db_directory() / "database.log";
  }

  void setup_log_file() {
    auto handle = make_unique<FileHandle>(log_file_name());
    log_file_ = move(handle);
  }

  void create_log_file() {
    log_file_ = make_unique<FileHandle>(log_file_name());
  }

  void write_log(const Buffer& log_data, buffer_offset_t offset) {
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

  bool read_log(LogFileCursor& cursor) {
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

private:
  ptr<FileHandle> log_file_ {nullptr};
  std::future<void> *flush_log_func_ {nullptr};
};
