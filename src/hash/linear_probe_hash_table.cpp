
// TODO: This entire class can be put under `storage`!
// It has a lot of knowledge about the storage format,
// in particular, the HTBlockPage.

// https://github.com/zwj-coder/cmudb/blob/master/src/container/hash/linear_probe_hash_table.cpp

#include "hash/linear_probe_hash_table.hpp"

/**********************************************
 * TODO: Document me
 **********************************************/

template<class K, class V>
LinearProbeHT<K, V>::LinearProbeHT(CRef<String> name,
                                   BuffMgr& buff_mgr,
                                   CRef<CompT> comp,
                                   size_t num_buckets,
                                   HashFunc<K> hash_fn)
  : name_        (name),
    comp_        (comp),
    num_buckets_ (num_buckets),
    hash_fn_     (move(hash_fn)),
    buff_mgr_    (buff_mgr)
{
  auto header_page = fetch_header_page();
  header_page.set_size(num_buckets);
  append_buckets(header_page, num_buckets);
}

/**********************************************
 * TODO: Document me
 **********************************************/

template<class K, class V>
vector<V> LinearProbeHT<K, V>::find_values(CRef<K> key) {
  MutVec<V> result;

  table_latch_.rlock();
  auto header_page = fetch_header_page();
  auto expected_index = slot_index(key);
  auto meet_starting_point = false;
  for (auto index = expected_index;; index = (index + 1) % header_page.size()) {
    if (index == expected_index) {
      if (meet_starting_point) break;
      meet_starting_point = true;
    }
    // initialize block_page and block (casting)
    auto block_index = index / block_array_size();
    auto maybe_page = buff_mgr_.fetch_page(PageId::from(block_index));
    assert(maybe_page);
    auto page = HTBlockPage<K,V>(maybe_page);

    // expected offset of key-value pair in this block
    auto data_offset_in_block = index % block_array_size();

    page.rlatch();
    if (!page.is_occupied(data_offset_in_block)) {
      page.runlatch();
      break;
    }

    if (page.is_readable(data_offset_in_block) &&
        comp_(key, page.key_at(data_offset_in_block)) == 0) {
      result.push_back(page.value_at(data_offset_in_block));
    }
    page.runlatch();
  }

  table_latch_.runlock();
  return result;
}

template<class K, class V>
bool LinearProbeHT<K, V>::insert(CRef<K> key,
                                 CRef<V> value)
{
  table_latch_.rlock();
  auto result = find_values(key);
  if (std::find(result.begin(), result.end(), value) != result.end()) {
    return false;
  }

  auto header_page = fetch_header_page();
  auto expected_index = slot_index(key);
  auto meet_starting_point = false;

  // TODO: This for-loop is UGLY AS FUCK.
  // Refactor this to be a while loop, with comments.

  // This whole entire thing could use some good comments.
  // Lots of stuff happening w/o explanation.
  for (auto index = expected_index; ;index = (index + 1) % header_page.size()) {
    if (index == expected_index) {
      if (meet_starting_point) break;
      meet_starting_point = true;
    }
    // initialize block_page and block (casting)
    auto block_index = index / block_array_size();
    auto page_id = header_page.block_page_id(block_index);
    auto maybe_page = buff_mgr_.fetch_page(page_id);
    assert(maybe_page);

    auto page = HTBlockPage<K,V>(maybe_page);

    // inserting (and flushing the page if the insert
    // operator is successfuly)
    page.wlatch();
    auto success = page.insert(index % block_array_size(), key, value);
    if (success) {
      buff_mgr_.flush_page(page.page_id());
      page.wunlatch();
      table_latch_.runlock();
      return true;
    }
    page.wunlatch();
  }
  table_latch_.runlock();
  // come here mean the current hash table is full, we need to resize
  resize(header_page.size());
  return insert(key, value);
}

template<class K, class V>
bool LinearProbeHT<K, V>::remove(CRef<K> key) {
  table_latch_.rlock();
  auto header_page = fetch_header_page();
  auto expected_index = slot_index(key);
  auto meet_starting_point = false;
  for (auto index = expected_index;; index = (index + 1) % header_page.size()) {
    if (index == expected_index) {
      if (meet_starting_point) break;
      meet_starting_point = true;
    }
    // initialize block_page and block (casting)
    auto block_index = index / block_array_size();
    auto page_id = header_page.block_page_id(block_index);
    auto maybe_page = buff_mgr_.fetch_page(page_id);
    assert(maybe_page);
    auto page = HTBlockPage<K,V>(maybe_page);

    // expected offset of key-value pair in this block
    auto data_offset_in_block = index % block_array_size();

    // conditions
    page.wlatch();
    if (!page.is_occupied(data_offset_in_block)) {
      page.wunlatch();
      break;
    }

    if (page.is_readable(data_offset_in_block) &&
        comp_(key, page.key_at(data_offset_in_block)) == 0) {
      // removing and unlock
      page.remove(data_offset_in_block);
      page.wunlatch();
      table_latch_.runlock();
      return true;
    }
    page.wunlatch();
  }
  table_latch_.runlock();
  return false;
}

template<class K, class V>
void LinearProbeHT<K, V>::resize(size_t initial_size) {
  table_latch_.wlock();

  auto header_page = fetch_header_page();

  auto expected_size = initial_size * 2;
  // only grow up in size
  if (header_page.size() < expected_size) {
    auto old_size = header_page.size();
    header_page.set_size(expected_size);
    append_buckets(header_page, expected_size - old_size);
    // re-organize all key-value pairs
    vector<HTBlockPage<K, V>> all_old_blocks;
    vector<PageId> all_block_page_ids;

    // NOTE: Why are we grabbing the blocks 0 up to N?
    // Are we always certain that these blocks will have our HT pages?
    // Something seems smelly.. This looks like a bug waiting to happen!
    for (size_t index = 0; index < header_page.num_blocks(); ++index) {
      auto maybe_page = buff_mgr_.fetch_page(PageId::from(index));
      assert(maybe_page);
      auto page = HTBlockPage<K, V>(maybe_page);

      all_old_blocks.push_back(page);
      all_block_page_ids.push_back(header_page.block_page_id(index));
    }

    header_page.reset_block_index();

    for (size_t idx = 0; idx < header_page.num_blocks(); idx++) {
      const auto page = all_old_blocks[idx];
      for (size_t pair_idx = 0; pair_idx < block_array_size(); pair_idx++) {
        insert(page.key_at(pair_idx), page.value_at(pair_idx));
      }
      buff_mgr_.delete_page(all_block_page_ids[idx]);
    }
  }
  table_latch_.wunlock();
}

template<class K, class V>
size_t LinearProbeHT<K, V>::size() {
  table_latch_.rlock();
  auto size = fetch_header_page().size();
  table_latch_.runlock();
  return size;
}

/*****************************************************************************
 * UTILITIES (these functions should already be called in a lock context)
 *****************************************************************************/

template<class K, class V>
HTHeaderPage LinearProbeHT<K, V>::fetch_header_page() {
  Page* maybe_page = buff_mgr_.fetch_page(header_page_id_);
  if (maybe_page == nullptr) {
    throw new Exception("Can't initialize header page");
  }

  return HTHeaderPage(maybe_page);
}

template<class K, class V>
void LinearProbeHT<K, V>::append_buckets(HTHeaderPage& header_page,
                                         size_t num_buckets)
{
  size_t total_current_buckets
    = header_page.num_blocks() * block_array_size();
  for (; total_current_buckets < num_buckets;
       total_current_buckets += block_array_size()) {

    auto maybe_page = buff_mgr_.create_page();
    assert(maybe_page);
    auto page = HTBlockPage<K,V>(maybe_page);

    auto next_block_id = page.page_id();
    buff_mgr_.unpin(next_block_id, true);
    buff_mgr_.flush_page(next_block_id);
    header_page.add_block_page_id(next_block_id);
  }
}

template<class K, class V>
slot_offset_t LinearProbeHT<K, V>::slot_index(CRef<K> key) {
  return hash_fn_.hash(key) % fetch_header_page().size();
}

template<class K, class V>
size_t LinearProbeHT<K, V>::block_array_size() {
  return (4 * PAGE_SIZE / (4 * sizeof(MappingT) + 1));
}

template class LinearProbeHT<GenericKey, RID>;
