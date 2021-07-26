
#include <utility> 
#include "index/index_iterator.hpp"

template <typename KeyT, typename ValueT, typename KeyComp>
IndexIterator<KeyT, ValueT, KeyComp> &IndexIterator<KeyT, ValueT, KeyComp>::operator++() {
  if (index_ < curr_leaf_.size() - 1) {
    index_++;
  } else if (curr_leaf_.next_page_id() == INVALID_PAGE_ID) {
    at_the_end_ = true;
  } else {
    auto next_page = buff_mgr_.fetch_page(curr_leaf_.next_page_id());
    assert(next_page);
    buff_mgr_.unpin_page(curr_leaf_.page_id(), false);
    curr_leaf_.set_ptr(next_page->data());
    index_ = 0;
  }
  return *this;
}

template <typename KeyT, typename ValueT, typename KeyComp>
const pair<KeyT, ValueT>& IndexIterator<KeyT, ValueT, KeyComp>::operator*() {
  return curr_leaf_.item(index_);
}
