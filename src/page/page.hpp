#pragma once

#include <array>
#include <optional>

#include "common/config.hpp"
#include "txns/rw_latch.hpp"

class Page {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  Page();
  // No copy
  Page(CRef<Page>) = delete;
  // No copy assign
  Page& operator=(CRef<Page>) = delete;

  // TODO: The line below should get replaced soon.
  // We should not have to make Page polymorphic we decouple
  // page layout from page data.
  // Page should hold a buffer
  // PageLayout should RW into the Page buffer.
  virtual ~Page() {} // Make Page polymorphic

  static OptRef<Page> make_opt(MutRef<Page> page);

  /**********************************************
   * Instance methods
   **********************************************/

  char* data();
  MRef<char[]> as_char_array();
  lsn_t lsn();
  void set_lsn(lsn_t lsn);
  void reset_memory();

  MRef<Buffer> buffer() {
    return buffer_;
  }

  page_id_t id() const {
    return id_;
  }

  void set_id(page_id_t id) {
    id_ = id;
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

  void set_dirty(bool dirty) {
    is_dirty_ = dirty;
  }

  bool is_dirty() const {
    return is_dirty_;
  }

  void wlatch();
  void wunlatch();

  void rlatch();
  void runlatch();

private:
  static constexpr size_t SIZE_PAGE_HEADER = 8;
  static constexpr size_t OFFSET_PAGE_START = 0;
  static constexpr size_t OFFSET_LSN = 4;

  page_id_t id_ = INVALID_PAGE_ID;
  Buffer buffer_;
  int pin_count_ = 0;
  bool is_dirty_ = false;
  RWLatch rwlatch_;
};
