#pragma once

#include "btree/b_plus_tree_leaf_page.hpp"
#include "index/generic_key.hpp"
#include "index/generic_comp.hpp"

class IndexIterator {
public:
  using KeyT     = GenericKey;
  using ValueT   = RID;
  using MappingT = std::pair<KeyT, ValueT>;
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
  IndexIterator() : pair_ (MappingT(key_, value_)) {}
  ~IndexIterator() = default;

  bool is_end() {
    // TODO
    return false;
  }

  // TODO: Not a fan of this. Remove it.
  CRef<MappingT> operator*();

  IndexIterator& operator++();

  bool operator==(CRef<IndexIterator> itr) const {
    throw std::runtime_error("unimplemented");
  }

  bool operator!=(CRef<IndexIterator> itr) const {
    throw std::runtime_error("unimplemented");
  }

private:
  KeyT key_;
  ValueT value_;
  // TODO
  // KeyComp comp_;
  MappingT pair_;
};
