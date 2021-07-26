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

  IndexIterator(BTreeLeafPage& curr_leaf,
                BuffMgr& buff_mgr,
                int32_t index)
    : curr_leaf_  (curr_leaf),
      index_      (index),
      buff_mgr_   (buff_mgr),
      at_the_end_ (false)
  {}

  ~IndexIterator() = default;

  bool at_the_end() {
    // TODO
    return false;
  }

  const MappingT& operator*();
  IndexIterator& operator++();

  bool operator==(const IndexIterator& iter) const;
  bool operator!=(const IndexIterator& iter) const;

private:
  BTreeLeafPage& curr_leaf_;
  KeyT key_;
  ValueT value_;
  BuffMgr& buff_mgr_;
  MappingT pair_;
  int32_t index_;
};
