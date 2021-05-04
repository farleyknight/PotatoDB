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
  using MappingT = pair<KeyT, ValueT>;
  static constexpr int PAGE_HEADER_SIZE = 24;
  static constexpr int INTERNAL_PAGE_SIZE = ((PAGE_SIZE - PAGE_HEADER_SIZE) / (sizeof(MappingT)));

  // must call initialize method after "create" a new node
  void init(PageId page_id,
            PageId parent_id = PageId::INVALID(),
            int max_size = INTERNAL_PAGE_SIZE);

  KeyT key_at(int index) const;
  void set_key_at(int index, CRef<KeyT> key);
  int value_index(CRef<ValueT> value) const;
  ValueT value_at(int index) const;

  ValueT lookup(CRef<KeyT> key,
                CRef<KeyComparator> comparator) const;

  void populate_new_root(CRef<ValueT> old_value,
                         CRef<KeyT> new_key,
                         CRef<ValueT> new_value);

  int insert_node_after(CRef<ValueT> old_value,
                        CRef<KeyT> new_key,
                        CRef<ValueT> new_value);
  void remove(int index);
  ValueT remove_and_return_only_child();

  // Split and Merge utility methods
  void move_all_to(BPlusTreeInternalPage& recipient,
                   CRef<KeyT> middle_key,
                   CRef<BuffMgr> buff_mgr);

  void move_half_to(BPlusTreeInternalPage& recipient,
                    CRef<BuffMgr> buff_mgr);

  void move_first_to_end_of(BPlusTreeInternalPage& recipient,
                            CRef<KeyT> middle_key,
                            CRef<BuffMgr> buff_mgr);

  void move_last_to_front_of(BPlusTreeInternalPage& recipient,
                             CRef<KeyT> middle_key,
                             CRef<BuffMgr> buff_mgr);

private:
  void copy_n_from(CRef<Vec<MappingT>> items,
                   int size,
                   CRef<BuffMgr> buff_mgr);

  void copy_last_from(CRef<MappingT> pair, CRef<BuffMgr> buff_mgr);
  void copy_first_from(CRef<MappingT> pair, CRef<BuffMgr> buff_mgr);
};
