#pragma once

#include "common/config.hpp"
#include "txns/txn.hpp"
#include "page/hash_table_block_page.hpp"
#include "index/generic_key.hpp"

template<class KeyT, class ValueT>
class HashTable {
public:
  using CompT = Comp<KeyT>;

  virtual ~HashTable() = default;

  virtual bool insert(const KeyT& key,
                      const ValueT& value) = 0;

  virtual bool remove(const KeyT& key) = 0;

  virtual vector<ValueT> find_values(const KeyT& key) = 0;
};
