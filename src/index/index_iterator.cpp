
#include <utility> 
#include "index/index_iterator.hpp"

Ref<std::pair<IndexIterator::KeyT, IndexIterator::ValueT>>
IndexIterator::operator*() {
  // TODO
  return pair_;
}

MutRef<IndexIterator>
IndexIterator::operator++() {
  // TODO
  return *this;
};
