#pragma once

#include "btree/b_plus_tree_page.hpp"

// TODO: Delete these lines
// #define B_PLUS_TREE_INTERNAL_PAGE_TYPE BPlusTreeInternalPage<KeyT, ValueT, KeyComparator>

/**
 * Store n indexed keys and n+1 child pointers (page_id) within internal page.
 * Pointer PAGE_ID(i) points to a subtree in which all keys K satisfy:
 * K(i) <= K < K(i+1).
 * NOTE: since the number of keys does not equal to number of child pointers,
 * the first key always remains invalid. That is to say, any search/lookup
 * should ignore the first key.
 *
 * Internal page format (keys are stored in increasing order):
 *  --------------------------------------------------------------------------
 * | HEADER | KEY(1)+PAGE_ID(1) | KEY(2)+PAGE_ID(2) | ... | KEY(n)+PAGE_ID(n) |
 *  --------------------------------------------------------------------------
 */
template <typename KeyT, typename ValueT, typename KeyComparator>
class BPlusTreeInternalPage : public BPlusTreePage {
public:
  using MappingT = std::pair<KeyT, ValueT>;
  static constexpr int PAGE_HEADER_SIZE = 24;
  static constexpr int PAGE_SIZE = ((PAGE_SIZE - PAGE_HEADER_SIZE) / (sizeof(MappingT)));

  // must call initialize method after "create" a new node
  void init(page_id_t page_id, page_id_t parent_id = INVALID_PAGE_ID, int max_size = PAGE_SIZE);

  KeyT key_at(int index) const;
  void set_key_at(int index, Ref<KeyT> key);
  int value_index(Ref<ValueT> value) const;
  ValueT value_at(int index) const;

  ValueT lookup(Ref<KeyT> key, Ref<KeyComparator> comparator) const;
  void populate_new_root(Ref<ValueT> old_value, Ref<KeyT> new_key, Ref<ValueT> new_value);
  int insert_node_after(Ref<ValueT> old_value, Ref<KeyT> new_key, Ref<ValueT> new_value);
  void remove(int index);
  ValueT remove_and_return_only_child();

  // Split and Merge utility methods
  void move_all_to(MRef<BPlusTreeInternalPage> recipient, Ref<KeyT> middle_key, Ref<BuffMgr> buff_mgr);
  void Move_half_to(MRef<BPlusTreeInternalPage> recipient, Ref<BuffMgr> buff_mgr);
  void move_first_to_end_of(MRef<BPlusTreeInternalPage> recipient, Ref<KeyT> middle_key, Ref<BuffMgr> buff_mgr);
  void move_last_to_front_of(MRef<BPlusTreeInternalPage> recipient, Ref<KeyT> middle_key, Ref<BuffMgr> buff_mgr);

private:
  void copy_n_from(Ref<Vec<MappingT>> items, int size, Ref<BuffMgr> buff_mgr);
  void Copy_last_from(Ref<MappingT> pair, Ref<BuffMgr> buff_mgr);
  void copy_first_from(Ref<MappingT> pair, Ref<BuffMgr> buff_mgr);
  MappingT array[0];
};
