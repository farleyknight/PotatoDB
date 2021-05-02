#pragma once

#include <array>
#include <optional>

#include "common/config.hpp"

#include "buffer/buffer.hpp"

#include "page/page_id.hpp"

#include "txns/rw_latch.hpp"

class Page {
public:
  // TODO: Maybe this constructor can take a `move`-ed chunk of data
  Page();

  // No copy
  Page(CRef<Page>) = delete;
  // No copy assign
  Page& operator=(CRef<Page>) = delete;

  virtual ~Page() {} // Make Page polymorphic

  /**********************************************
   * Instance methods
   **********************************************/

  Buffer& buffer() {
    return buffer_;
  }

  CRef<Buffer> buffer() const {
    return buffer_;
  }

  void reset_memory();

  void copy_n_bytes(size_t source_offset,
                    size_t dest_offset,
                    CRef<Buffer> source,
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

  lsn_t lsn();
  void set_lsn(lsn_t lsn);

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

  uint32_t read_uint32(size_t offset) const;
  void write_uint32(size_t offset, uint32_t data);

  void set_dirty(bool dirty) {
    is_dirty_ = dirty;
  }

  bool is_dirty() const {
    return is_dirty_;
  }

  PageId read_page_id(size_t offset) const;
  void write_page_id(size_t offset, PageId page_id);

  void wlatch();
  void wunlatch();

  void rlatch();
  void runlatch();


private:
  static constexpr size_t SIZE_PAGE_HEADER = 8;
  static constexpr size_t OFFSET_PAGE_START = 0;
  static constexpr size_t OFFSET_LSN = 4;

  PageId  page_id_;
  Buffer  buffer_;
  int     pin_count_ = 0;
  bool    is_dirty_ = false;
  RWLatch rwlatch_;
};
