#pragma once

#include "common/config.hpp"
#include "btree/b_plus_tree_leaf_page.hpp"
#include "index/generic_key.hpp"
#include "index/generic_comp.hpp"

class IndexIterator {
public:
  using KeyT     = GenericKey;
  using ValueT   = RID;
  using MappingT = pair<KeyT, ValueT>;
  using KeyComp  = GenericComp;

  // You may define your own constructor based on your
  // member variables

  /*
   *
   IndexIterator(KeyT key, ValueT value, KeyComp comp)
   : key_   (key),
   value_ (value),
   comp_  (comp) {}
   */

  // IndexIterator() = default;
  IndexIterator() {}
  ~IndexIterator() = default;

  bool is_end() {
    // TODO
    return false;
  }

  const MappingT& operator*();

  IndexIterator& operator++();

  bool operator==(UNUSED const IndexIterator& itr) const {
    throw std::runtime_error("unimplemented");
  }

  bool operator!=(UNUSED const IndexIterator& itr) const {
    throw std::runtime_error("unimplemented");
  }

private:
  KeyT key_;
  ValueT value_;
  // TODO
  // KeyComp comp_;
  MappingT pair_;
};
