#pragma once

#include "buffer/buffer.hpp"
#include "tuple/tuple.hpp"
#include "recovery/log_record.hpp"

class LogFileCursor {
private:
  Buffer buffer_;
  buffer_offset_t buffer_offset_ = 0;
  size_t file_offset_ = 0;

  void increment_offset(int32_t offset) {
    buffer_offset_ += offset;
    file_offset_   += offset;
  }

public:
  LogFileCursor(uint32_t size)
    : buffer_ (size)
  {}

  bool deserialize_log_record(LogRecord& log);

  void append(LogRecord& log_record);
  void append_header(const LogRecord& log_record);
  void append_insert_record(const LogRecord& log_record);
  void append_delete_record(const LogRecord& log_record) {
    // Write the RID
    append_rid(log_record.delete_rid());

    // Write the deleted Tuple
    append_tuple(log_record.delete_tuple());
  }

  void append_update_record(const LogRecord& log_record) {
    // Write the RID
    append_rid(log_record.update_rid());
    // Write the old tuple (before update)
    append_tuple(log_record.old_tuple());
    // Write the new tuple (after update)
    append_tuple(log_record.new_tuple());
  }

  void append_new_page_record(const LogRecord& log_record) {
    // Write prev page ID
    append_page_id(log_record.prev_page_id());

    // Write new page ID
    append_page_id(log_record.page_id());
  }

  Buffer& buffer() {
    return buffer_;
  }

  void swap(Buffer& other) {
    buffer_.swap(other);
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

  int32_t next_int32();
  const PageId next_page_id();
  const RID next_rid();
  const Tuple next_tuple();
  txn_id_t next_txn_id();
  lsn_t next_lsn();

  void append_int32(int32_t val);
  void append_page_id(PageId val);
  void append_rid(RID val);
  void append_tuple(const Tuple& tuple);
  void append_txn_id(txn_id_t val);
  void append_lsn(lsn_t val);
};
