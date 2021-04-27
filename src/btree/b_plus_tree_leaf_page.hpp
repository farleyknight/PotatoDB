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
  static constexpr int PAGE_SIZE = (PAGE_SIZE - PAGE_HEADER_SIZE) / sizeof(MappingT);

  // After creating a new leaf page from buffer pool, must call initialize
  // method to set default values
  void init(page_id_t page_id, page_id_t parent_id = INVALID_PAGE_ID, int max_size = PAGE_SIZE);
  // helper methods
  page_id_t next_page_id() const;
  void set_next_page_id(page_id_t next_page_id);
  KeyT key_at(int index) const;
  int key_index(Ref<KeyT> key, Ref<KeyComp> comparator) const;
  Ref<MappingT> item(int index);

  // insert and delete methods
  int insert(Ref<KeyT> key, Ref<ValueT> value, Ref<KeyComp> comparator);
  bool lookup(Ref<KeyT> key, MutRawPtr<ValueT> value, Ref<KeyComp> comparator) const;
  int remove_and_delete_record(Ref<KeyT> key, Ref<KeyComp> comparator);

  // Split and Merge utility methods
  void move_half_to(MRef<BPlusTreeLeafPage> recipient);
  void move_all_to(MRef<BPlusTreeLeafPage> recipient);
  void move_first_to_end_of(MRef<BPlusTreeLeafPage> recipient);
  void move_last_to_front_of(MRef<BPlusTreeLeafPage> recipient);

 private:
  void copy_n_from(Ref<Vec<MappingT>> items, int size);
  void copy_last_from(Ref<MappingT> item);
  void copy_first_from(Ref<MappingT> item);
  page_id_t next_page_id_;
  MappingT array[0];
};
