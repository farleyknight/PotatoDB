
#include <utility> 
#include "index/index_iterator.hpp"

const std::pair<IndexIterator::KeyT, IndexIterator::ValueT>&
IndexIterator::operator*() {
  // TODO
  return pair_;
}

IndexIterator& IndexIterator::operator++() {
  // TODO
  return *this;
};
