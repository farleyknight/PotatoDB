
#include <utility> 
#include "index/index_iterator.hpp"

IndexIterator& IndexIterator::operator++() {
  if (index_ < curr_leaf_.size() - 1) {
    index_++;
  } else if (curr_leaf_.next_page_id() == PageId::INVALID()) {
    at_the_end_ = true;
  } else {
    auto next_page_ptr = buff_mgr_.fetch_page(curr_leaf_.next_page_id());
    assert(next_page_ptr);
    buff_mgr_.unpin(curr_leaf_.page_id(), false);
    curr_leaf_.update_ptr(next_page_ptr);
    index_ = 0;
  }
  return *this;
}

const IndexIterator::MappingT&
IndexIterator<KeyT, ValueT, KeyComp>::operator*() {
  return curr_leaf_.item(index_);
}
