#pragma once

#include <array>
#include <optional>

#include "common/config.hpp"

#include "buffer/buffer.hpp"
#include "page/page_id.hpp"
#include "txns/rw_latch.hpp"
#include "types/type_id.hpp"

class Page {
public:
  static constexpr size_t OFFSET_PAGE_START = 0;
  static constexpr size_t OFFSET_LSN        = 4;
  static constexpr size_t SIZE_PAGE_HEADER  = 8;

  Page();

  // No copy
  Page(const Page&) = delete;
  // No copy assign
  Page& operator=(const Page&) = delete;

  virtual ~Page() {} // Make Page polymorphic

  Buffer& buffer() {
    return buffer_;
  }

  const Buffer& buffer() const {
    return buffer_;
  }

  void reset_memory();

  // TODO: Remove this.
  // Replace it with `read/write_tuple` and `read/write_buffer`
  void copy_n_bytes(size_t source_offset,
                    size_t dest_offset,
                    const Buffer& source,
                    size_t n_bytes)
  {
    buffer_.copy_n_bytes(source_offset,
                         dest_offset,
                         source,
                         n_bytes);
  }

  PageId page_id() const {
    return page_id_;
  }

  void set_id(PageId id) {
    page_id_ = id;
  }

  size_t size() const {
    return buffer_.size();
  }

  // Increase the pin count.
  void pin() {
    ++pin_count_;
  }

  // Decrease the pin count.
  void unpin() {
    --pin_count_;
  }

  int pin_count() const {
    return pin_count_;
  }

  lsn_t read_lsn() const;
  void write_lsn(lsn_t lsn);

  int32_t read_int32(buffer_offset_t offset) const;
  void write_int32(buffer_offset_t offset, int32_t data);

  uint32_t read_uint32(buffer_offset_t offset) const;
  void write_uint32(buffer_offset_t offset, uint32_t data);

  const string read_string(buffer_offset_t offset) const;
  void write_string(buffer_offset_t offset, const string data);

  const Buffer read_buffer(UNUSED buffer_offset_t offset,
                           UNUSED buffer_offset_t size)
  {
    // TODO: Return a "sub"-buffer of the original
    return buffer_;
  }

  void write_buffer(UNUSED buffer_offset_t offset,
                    UNUSED const Buffer buffer) {
    // TODO: Write the buffer to the specified offset.
    return;
  }

  void set_dirty(bool dirty) {
    is_dirty_ = dirty;
  }

  bool is_dirty() const {
    return is_dirty_;
  }

  PageId read_page_id(buffer_offset_t offset) const;
  void write_page_id(buffer_offset_t offset, PageId page_id);

  TypeId read_type_id(buffer_offset_t offset) const;
  void write_type_id(buffer_offset_t offset, TypeId type_id);

  bool read_bool(buffer_offset_t offset) const;
  void write_bool(buffer_offset_t offset, bool value);

  void wlatch();
  void wunlatch();

  void rlatch();
  void runlatch();

private:
  PageId  page_id_ = PageId::INVALID();
  Buffer  buffer_;
  int32_t pin_count_ = 0;
  bool    is_dirty_ = false;
  RWLatch rwlatch_;
};
