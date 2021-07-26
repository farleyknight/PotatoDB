
#include "page/hash_table_header_page.hpp"

// TODO: Move to `/hash`

size_t HTHeaderPage::size() const {
  return size_;
}

void HTHeaderPage::set_size(size_t size) {
  size_ = size;
}

PageId HTHeaderPage::page_id() const {
  return page_id_;
}

void HTHeaderPage::set_page_id(PageId page_id) {
  page_id_ = page_id;
}

lsn_t HTHeaderPage::lsn() const {
  return lsn_;
}

void HTHeaderPage::set_lsn(lsn_t lsn) {
  lsn_ = lsn;
}

void HTHeaderPage::add_block_page_id(UNUSED PageId page_id) {
  return;
}

PageId HTHeaderPage::block_page_id(UNUSED size_t index) {
  return PageId::INVALID();
}

size_t HTHeaderPage::num_blocks() const {
  return 0;
}

void HTHeaderPage::reset_block_index() {
  next_index_ = 0;
}
