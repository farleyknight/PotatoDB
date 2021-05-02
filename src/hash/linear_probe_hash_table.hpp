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

  explicit LinearProbeHT(CRef<String> name,
                         BuffMgr& buff_mgr,
                         CRef<CompT> comp,
                         size_t num_buckets,
                         HashFunc<K> hash_fn);

  virtual bool insert(CRef<K> key,
                      CRef<V> value) override;

  virtual bool remove(CRef<K> key) override;

  vector<V> find_values(CRef<K> key) const override;

  void resize(size_t initial_size);
  size_t size();

private:
  void append_buckets(HTHeaderPage& page,
                      size_t num_buckets);
  slot_offset_t slot_index(CRef<K> key);
  HTHeaderPage& fetch_header_page();
  size_t block_array_size();

  OptRef<HTHeaderPage> header_page_;
  String name_;
  page_id_t header_page_id_;
  CompT comp_;
  int num_buckets_;

  void load_header_page();

  // Readers includes inserts and removes, writer is only resize
  RWLatch table_latch_;

  // Hash function
  HashFunc<K> hash_fn_;
  BuffMgr& buff_mgr_;
};
