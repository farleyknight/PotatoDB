
#include "page/page.hpp"

Page::Page() {
  buffer_.resize(PAGE_SIZE);
  reset_memory();
}

lsn_t Page::read_lsn() const {
  return buffer_.read_int32(OFFSET_LSN);
}

void Page::write_lsn(lsn_t lsn) {
  buffer_.write_int32(OFFSET_LSN, lsn);
}

int32_t Page::read_int32(size_t offset) const {
  return buffer_.read_int32(offset);
}

void Page::write_int32(size_t offset, int32_t data) {
  buffer_.write_int32(offset, data);
}

PageId Page::read_page_id(size_t offset) const {
  return PageId::from(buffer_.read_int32(offset));
}

void Page::write_page_id(size_t offset, PageId page_id) {
  buffer_.write_int32(offset, page_id.as_int32());
}

void Page::reset_memory() {
  // Zero-out the entire buffer
  buffer_.reset_memory();
  // Freshly zeroed-out page should not be dirty and have no pins
  is_dirty_ = false;
  pin_count_ = 0;
}

void Page::wlatch() {
  rwlatch_.wlock();
}

void Page::wunlatch() {
  rwlatch_.wunlock();
}

void Page::rlatch() {
  rwlatch_.rlock();
}

void Page::runlatch() {
  rwlatch_.runlock();
}
