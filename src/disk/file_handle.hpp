#pragma once

#include <filesystem>
#include <fstream>

#include "common/config.hpp"
#include "buffer/buffer.hpp"

namespace fs = std::filesystem;

class FileHandle {
public:
  FileHandle(fs::path file_path)
    : file_path_ (file_path)
  {
    if (!fs::exists(file_path)) {
      create();
    }
    open();
  }

  void write_buffer(buffer_offset_t offset, const Buffer& buffer) {
    handle_.seekp(offset);
    handle_.write(buffer.char_ptr(), buffer.size());
    handle_.flush();
  }

  void read_buffer(buffer_offset_t offset, Buffer& buffer) {
    handle_.seekp(offset);
    handle_.read(buffer.char_ptr(), buffer.size());
  }

  void create() {
    handle_.open(file_path_, fstream::out);
    handle_ << "";
    handle_.close();
  }

  void open() {
    handle_.open(file_path_, fstream::out);
  }

  void close() {
    handle_.close();
  }

  ~FileHandle() {
    close();
  }

private:
  fs::path file_path_;
  fstream handle_;
};
