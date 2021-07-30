#include "btree/b_tree_page.hpp"


bool BTreePage::is_leaf_page() const {
  return page_type() == IndexPageType::LEAF_PAGE;
}

bool BTreePage::is_root_page() const {
  return parent_page_id() == PageId::INVALID();
}

IndexPageType BTreePage::page_type() {
  auto page_type_as_int32 = read_int32(PAGE_TYPE_OFFSET);
  return *reinterpret_cast<IndexPageType*>(page_type_as_int32);
}

void BTreePage::set_page_type(IndexPageType page_type) {
  auto page_type_as_int32 = *reinterpret_cast<int32_t*>(page_type);
  write_int32(PAGE_TYPE_OFFSET, page_type_as_int32);
}

void BTreePage::increase_size(int32_t amount) {
  // TODO ??
  // What does this do?
}

int32_t BTreePage::size() const {
  return read_int32(CURRENT_SIZE_OFFSET);
}

void BTreePage::set_size(int32_t size) {
  write_int32(CURRENT_SIZE_OFFSET, size);
}

int32_t BTreePage::max_size() const {
  return read_int32(MAX_SIZE_OFFSET);
}

void BTreePage::set_max_size(int32_t max_size) {
  write_int32(MAX_SIZE_OFFSET, max_size);
}

PageId BTreePage::parent_page_id() const {
  return read_page_id(PARENT_PAGE_ID_OFFSET);
}

void BTreePage::set_parent_page_id(PageId parent_page_id) {
  write_page_id(PARENT_PAGE_ID_OFFSET, parent_page_id);
}

PageId BTreePage::page_id() const {
  return read_page_id(PAGE_ID_OFFSET);
}

void BTreePage::set_page_id(PageId page_id) {
  write_page_id(PAGE_ID_OFFSET, page_id);
}

lsn_t BTreePage::lsn() const {
  return read_lsn(LSN_OFFSET);
}

void BTreePage::set_lsn(lsn_t lsn) {
  write_lsn(LSN_OFFSET, lsn);
}
