#pragma once

#include <filesystem>
#include <fstream>

#include "common/config.hpp"
#include "buffer/buffer.hpp"

namespace fs = std::filesystem;

class FileHandle {
public:
  FileHandle(fs::path file_path);

  void write_buffer(buffer_offset_t offset, const Buffer& buffer);

  void print_status() const;

  void read_buffer(buffer_offset_t offset, Buffer& buffer);

  void create() {
    handle_.open(file_path_, fstream::out);
    handle_ << "";
    handle_.close();
  }

  void resize(std::uintmax_t new_size) {
    fs::resize_file(file_path_, new_size);
  }

  void open() {
    handle_.open(file_path_,
                 fstream::in | fstream::out | fstream::binary);
  }

  void close() {
    handle_.close();
  }

  ~FileHandle() {
    close();
  }

  buffer_offset_t size() const {
    return fs::file_size(file_path_);
  }

  const string file_path() const {
    return file_path_.string();
  }

  fstream& io() {
    return handle_;
  }

private:
  fs::path file_path_;
  fstream handle_;
};
