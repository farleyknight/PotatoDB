#pragma once

#include <utility>
#include <vector>

#include "common/config.hpp"
#include "btree/b_plus_tree_page.hpp"

/**
 * Store indexed key and record id (record id = page id combined with slot id,
 * see include/common/rid.h for detailed implementation) together within leaf
 * page. Only support unique key.
 *
 * Leaf page format (keys are stored in order):
 *  ----------------------------------------------------------------------
 * | HEADER | KEY(1) + RID(1) | KEY(2) + RID(2) | ... | KEY(n) + RID(n)
 *  ----------------------------------------------------------------------
 *
 *  Header format (size in byte, 28 bytes in total):
 *  ---------------------------------------------------------------------
 * | PageType (4) | lsn_t (4) | CurrentSize (4) | MaxSize (4) |
 *  ---------------------------------------------------------------------
 *  -----------------------------------------------
 * | Parentpage_id_t (4) | page_id_t (4) | Nextpage_id_t (4)
 *  -----------------------------------------------
 */

// TODO: Remove the word "Plus" from BPlusTreeLeafPage
// It's already too many words!
// I can write somewhere that I have decided to shorten the name
// to BTree for brevity.
template <typename KeyT, typename ValueT, typename KeyComp>
class BPlusTreeLeafPage : public BPlusTreePage {
public:
  using MappingT = std::pair<KeyT, ValueT>;

  static constexpr int PAGE_HEADER_SIZE = 28;
  static constexpr int LEAF_PAGE_SIZE = (PAGE_SIZE - PAGE_HEADER_SIZE) / sizeof(MappingT);

  // After creating a new leaf page from buffer pool, must call initialize
  // method to set default values
  void init(PageId page_id,
            PageId parent_id = PageId::INVALID(),
            int max_size = LEAF_PAGE_SIZE);
  // helper methods
  PageId next_page_id() const;
  void set_next_page_id(page_id_t next_page_id);
  KeyT key_at(int index) const;
  int key_index(CRef<KeyT> key, CRef<KeyComp> comparator) const;
  CRef<MappingT> item(int index);

  // insert and delete methods
  int insert(CRef<KeyT> key, CRef<ValueT> value, CRef<KeyComp> comparator);
  ValueT lookup(CRef<KeyT> key, CRef<KeyComp> comparator) const;
  int remove_and_delete_record(CRef<KeyT> key, CRef<KeyComp> comparator);

  // Split and Merge utility methods
  void move_half_to(BPlusTreeLeafPage& recipient);
  void move_all_to(BPlusTreeLeafPage& recipient);
  void move_first_to_end_of(BPlusTreeLeafPage& recipient);
  void move_last_to_front_of(BPlusTreeLeafPage& recipient);

private:
  void copy_n_from(CRef<Vec<MappingT>> items, int size);
  void copy_last_from(CRef<MappingT> item);
  void copy_first_from(CRef<MappingT> item);
  PageId next_page_id_;
};
