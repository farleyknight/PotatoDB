
#include "common/config.hpp"
#include "storage/page.hpp"

Page::Page() {
  reset_memory();
}

OptRef<Page>
Page::make_opt(MRef<Page> page) {
  return std::optional<RefWrap<Page>>(page);
}

MutRawPtr<char> Page::data() {
  return reinterpret_cast<MutRawPtr<char>>(buffer_.data());
}

MRef<char[]> Page::as_char_array() {
  return reinterpret_cast<char(&)[]>(*buffer_.data());
}

lsn_t Page::lsn() {
  return *reinterpret_cast<lsn_t *>(data() + OFFSET_LSN);
}

void Page::set_lsn(lsn_t lsn) {
  memcpy(data() + OFFSET_LSN, &lsn, sizeof(lsn_t));
}

void Page::reset_memory() {
  // Zero-out the entire buffer
  buffer_.fill({});
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
