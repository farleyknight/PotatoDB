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

  virtual bool insert(CRef<KeyT> key,
                      CRef<ValueT> value) = 0;

  virtual bool remove(CRef<KeyT> key) = 0;

  virtual vector<ValueT> find_values(CRef<KeyT> key) = 0;
};
