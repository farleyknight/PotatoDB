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
  create();

  bool
  resize(std::uintmax_t new_size);

  void
  open();

  void
  close();

  ~FileHandle();

  buffer_offset_t
  size() const;

  const string
  file_path() const;

  file_id_t
  file_id() const;

  fstream&
  io();

private:
  file_id_t file_id_;
  fs::path file_path_;
  fstream handle_;

  atomic<block_id_t> next_block_id_ {0};
};
