#pragma once

#include "buffer/buff_mgr.hpp"

#include "hash/hash_function.hpp"
#include "hash/hash_table.hpp"

#include "index/comp.hpp"

#include "page/hash_table_block_page.hpp"
#include "page/hash_table_header_page.hpp"

template<class K, class V>
class LinearProbeHT : public HashTable<K, V> {
public:
  using MappingT = std::pair<K, V>;
  using CompT    = Comp<K>;

  explicit LinearProbeHT(const string& name,
                         BuffMgr& buff_mgr,
                         const CompT& comp,
                         size_t num_buckets,
                         HashFunc<K> hash_fn);

  virtual bool insert(const K& key,
                      const V& value) override;

  virtual bool remove(const K& key) override;

  virtual vector<V> find_values(const K& key) override;

  void resize(size_t initial_size);
  size_t size();

private:
  void append_buckets(HTHeaderPage& page,
                      size_t num_buckets);
  slot_offset_t slot_index(const K& key);
  HTHeaderPage fetch_header_page();
  size_t block_array_size();

  string name_;
  PageId header_page_id_ = PageId::INVALID();
  CompT comp_;
  int num_buckets_;

  // Readers includes inserts and removes, writer is only resize
  RWLatch table_latch_;

  // Hash function
  HashFunc<K> hash_fn_;
  BuffMgr& buff_mgr_;
};
