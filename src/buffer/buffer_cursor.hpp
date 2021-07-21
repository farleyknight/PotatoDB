#pragma once

#include "buffer/buffer.hpp"
#include "tuple/tuple.hpp"

// TODO: Now that we've got the file offset involved,
// maybe rename this class?
//
// What about `BufferedFileCursor` ?
//
class BufferCursor {
private:
  Buffer buffer_;
  buffer_offset_t buffer_offset_ = 0;
  size_t file_offset_ = 0;

  void increment_offset(uint32_t offset) {
    buffer_offset_ += offset;
    file_offset_   += offset;
  }

public:
  BufferCursor(uint32_t size)
    : buffer_ (size)
  {}

  Buffer& buffer() {
    return buffer_;
  }

  void buffer_reset() {
    buffer_offset_ = 0;
  }

  buffer_offset_t buffer_offset() {
    return buffer_offset_;
  }

  void set_buffer_offset(buffer_offset_t offset) {
    buffer_offset_ = offset;
  }

  size_t file_offset() {
    return file_offset_;
  }

  void set_file_offset(size_t offset) {
    file_offset_ = offset;
  }

  int32_t next_int32() {
    std::cout << "next_int32 at buffer_offset: " << buffer_offset_ << std::endl;
    auto val = buffer_.read_int32(buffer_offset_);
    increment_offset(sizeof(val));
    return val;
  }

  const PageId next_page_id() {
    std::cout << "next_page_id at buffer_offset: " << buffer_offset_ << std::endl;
    auto page_id = buffer_.read_page_id(buffer_offset_);
    increment_offset(sizeof(page_id));
    return page_id;
  }

  const RID next_rid() {
    std::cout << "next_rid at buffer_offset: " << buffer_offset_ << std::endl;
    auto rid = buffer_.read_rid(buffer_offset_);
    increment_offset(sizeof(rid));
    return rid;
  }

  const Tuple next_tuple() {
    std::cout << "next_tuple at buffer_offset: " << buffer_offset_ << std::endl;
    auto tuple = buffer_.read_tuple(buffer_offset_);
    increment_offset(tuple.size() + sizeof(uint32_t));
    return tuple;
  }

  txn_id_t next_txn_id() {
    std::cout << "next_txn_id at buffer_offset: " << buffer_offset_ << std::endl;
    auto val = buffer_.read_txn_id(buffer_offset_);
    increment_offset(sizeof(val));
    return val;
  }

  lsn_t next_lsn() {
    std::cout << "next_lsn at buffer_offset: " << buffer_offset_ << std::endl;
    auto val = buffer_.read_lsn(buffer_offset_);
    increment_offset(sizeof(val));
    return val;
  }
};
