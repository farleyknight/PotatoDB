#pragma once

#include "common/config.hpp"
#include "btree/b_tree_leaf_page.hpp"
#include "index/generic_key.hpp"
#include "index/generic_comp.hpp"

class IndexIterator {
public:
  using KeyT      = GenericKey;
  using ValueT    = RID;
  using MappingT  = pair<KeyT, ValueT>;
  using KeyComp   = GenericComp;
  using LeafPageT = BTreeLeafPage<KeyT, ValueT, KeyComp>;

  IndexIterator(LeafPageT& curr_leaf,
                BuffMgr& buff_mgr,
                int32_t index)
    : curr_leaf_  (curr_leaf),
      buff_mgr_   (buff_mgr),
      index_      (index),
      at_the_end_ (false)
  {}

  ~IndexIterator() = default;

  bool at_the_end() {
    return at_the_end_;
  }

  const MappingT& operator*();
  IndexIterator& operator++();

  bool operator==(const IndexIterator& iter) const;
  bool operator!=(const IndexIterator& iter) const;

private:
  LeafPageT& curr_leaf_;
  KeyT key_;
  ValueT value_;
  BuffMgr& buff_mgr_;
  MappingT pair_;
  int32_t index_;
  bool at_the_end_;
};
