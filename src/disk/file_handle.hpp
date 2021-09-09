#pragma once

#include <filesystem>
#include <fstream>

#include "common/config.hpp"
#include "buffer/buffer.hpp"

namespace fs = std::filesystem;

class FileHandle {
public:
  FileHandle(file_id_t file_id, fs::path file_path);

  void
  read_buffer(buffer_offset_t offset, Buffer& buffer);
  void
  write_buffer(buffer_offset_t offset, const Buffer& buffer);

  void print_status() const;

  bool
  allocate_block(block_id_t block_id);

  bool
  deallocate_block(block_id_t block_id);

  void
  create() {
    handle_.open(file_path_, fstream::out);
    handle_ << "";
    handle_.close();
  }

  bool
  resize(std::uintmax_t new_size) {
    std::error_code error;
    std::error_condition ok;
    fs::resize_file(file_path_, new_size, error);

    return (error == ok);
  }

  void
  open() {
    handle_.open(file_path_,
                 fstream::in | fstream::out | fstream::binary);
  }

  void
  close() {
    handle_.close();
  }

  ~FileHandle() {
    close();
  }

  buffer_offset_t
  size() const {
    return fs::file_size(file_path_);
  }

  const string
  file_path() const {
    return file_path_.string();
  }

  file_id_t
  file_id() const {
    return file_id_;
  }

  fstream&
  io() {
    return handle_;
  }

private:
  file_id_t file_id_;
  fs::path file_path_;
  fstream handle_;

  atomic<block_id_t> next_block_id_ {0};
};
