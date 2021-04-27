
#include "storage/hash_table_header_page.hpp"

size_t HTHeaderPage::size() const {
  return size_;
}

void HTHeaderPage::set_size(size_t size) {
  size_ = size;
}

page_id_t HTHeaderPage::page_id() const {
  return page_id_;
}

void HTHeaderPage::set_page_id(page_id_t page_id) {
  page_id_ = page_id;
}

lsn_t HTHeaderPage::lsn() const {
  return lsn_;
}

void HTHeaderPage::set_lsn(lsn_t lsn) {
  lsn_ = lsn;
}

void HTHeaderPage::add_block_page_id(page_id_t page_id) {

}

page_id_t HTHeaderPage::block_page_id(size_t index) {
  return 0;
}

size_t HTHeaderPage::num_blocks() const {
  return 0;
}

void HTHeaderPage::reset_block_index() {
  next_index_ = 0;
}
