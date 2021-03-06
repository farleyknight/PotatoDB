#include "page/page.hpp"
#include "types/type.hpp"

Page::Page() {
  buffer_.resize(PAGE_SIZE);
  reset_memory();
}

lsn_t
Page::read_lsn() const {
  return buffer_.read_int32(OFFSET_LSN);
}

void
Page::write_lsn(lsn_t lsn) {
  buffer_.write_int32(OFFSET_LSN, lsn);
}

const string
Page::read_string(buffer_offset_t offset) const {
  return buffer_.read_string(offset);
}

void
Page::write_string(buffer_offset_t offset, const string data) {
  return buffer_.write_string(offset, data);
}

int32_t
Page::read_int32(buffer_offset_t offset) const {
  return buffer_.read_int32(offset);
}

void
Page::write_int32(buffer_offset_t offset, int32_t data) {
  buffer_.write_int32(offset, data);
}



PageId
Page::read_page_id(buffer_offset_t offset) const {
  return PageId::from(buffer_.read_uint32(offset));
}

void
Page::write_page_id(buffer_offset_t offset, PageId page_id) {
  buffer_.write_uint32(offset, page_id.as_uint32());
}


TypeId
Page::read_type_id(buffer_offset_t offset) const {
  auto type_id_as_int32 = buffer_.read_int32(offset);
  return Type::from_int32(type_id_as_int32);
}

void
Page::write_type_id(buffer_offset_t offset, TypeId type_id) {
  auto type_id_as_int32 = Type::as_int32(type_id);
  buffer_.write_int32(offset, type_id_as_int32);
}

bool
Page::read_bool(buffer_offset_t offset) const {
  return buffer_.read_bool(offset);
}

void
Page::write_bool(buffer_offset_t offset, bool value) {
  buffer_.write_bool(offset, value);
}

void
Page::reset_memory() {
  // Zero-out the entire buffer
  buffer_.reset_memory();
  // Freshly zeroed-out page should not be dirty and have no pins
  is_dirty_ = false;
  pin_count_ = 0;
}

void
Page::wlatch() {
  rwlatch_.wlock();
}

void
Page::wunlatch() {
  rwlatch_.wunlock();
}

void
Page::rlatch() {
  rwlatch_.rlock();
}

void
Page::runlatch() {
  rwlatch_.runlock();
}
