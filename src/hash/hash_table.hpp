#pragma once

#include "common/config.hpp"
#include "txns/txn.hpp"
#include "page/hash_table_block_page.hpp"
#include "index/generic_key.hpp"

template<class K, class V>
class HashTable {
public:
  using CompT = Comp<K>;

  virtual ~HashTable() = default;

  virtual bool insert(const K& key,
                      const V& value) = 0;

  virtual bool remove(const K& key) = 0;

  virtual vector<V> find_values(const K& key) = 0;
};
