#pragma once

#include "btree/b_tree_page.hpp"

// https://github.com/astronaut0131/cmu15-445-2017/blob/d393b2b76c38ef02ad8432f3eb66452219fe6508/src/page/b_plus_tree_internal_page.cpp

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
template <typename KeyT, typename ValueT, typename KeyComp>
class BTreeInternalPage : public BTreePage {
public:
  using MappingT = pair<KeyT, ValueT>;
  static constexpr int32_t PAGE_HEADER_SIZE = 24;
  static constexpr int32_t INTERNAL_PAGE_SIZE =
    ((PAGE_SIZE - PAGE_HEADER_SIZE) / (sizeof(MappingT)));

  BTreeInternalPage(Page* page)
    : BTreePage (page)
  {}

  // must call initialize method after "create" a new node
  void init(PageId page_id,
            PageId parent_id = PageId::INVALID(),
            int32_t max_size = INTERNAL_PAGE_SIZE);

  KeyT key_at(int32_t index) const;
  void set_key_at(int32_t index, const KeyT& key);
  int32_t value_index(const ValueT& value) const;
  ValueT value_at(int32_t index) const;

  ValueT lookup(const KeyT& key,
                const KeyComp& comparator) const;

  void populate_new_root(const ValueT& old_value,
                         const KeyT& new_key,
                         const ValueT& new_value);

  int32_t insert_node_after(const ValueT& old_value,
                            const KeyT& new_key,
                            const ValueT& new_value);
  void remove(int32_t index);
  ValueT remove_and_return_only_child();

  // Split and Merge utility methods
  void move_all_to(BTreeInternalPage& recipient,
                   const KeyT& middle_key,
                   const BuffMgr& buff_mgr);

  void move_half_to(BTreeInternalPage& recipient,
                    const BuffMgr& buff_mgr);

  void move_first_to_end_of(BTreeInternalPage& recipient,
                            const KeyT& middle_key,
                            const BuffMgr& buff_mgr);

  void move_last_to_front_of(BTreeInternalPage& recipient,
                             const KeyT& middle_key,
                             const BuffMgr& buff_mgr);

private:
  void copy_n_from(const vector<MappingT>& items,
                   int32_t size,
                   const BuffMgr& buff_mgr);

  void copy_last_from(const MappingT& pair, const BuffMgr& buff_mgr);
  void copy_first_from(const MappingT& pair, const BuffMgr& buff_mgr);
};
