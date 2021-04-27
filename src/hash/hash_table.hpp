#pragma once

#include "common/config.hpp"
#include "txns/txn.hpp"
#include "storage/hash_table_block_page.hpp"
#include "index/generic_key.hpp"

template<class KeyT, class ValueT>
class HashTable {
public:
  using CompT = Comp<KeyT>;

  virtual ~HashTable() = default;

  virtual bool insert(Ref<KeyT> key,
                      Ref<ValueT> value) = 0;

  virtual bool remove(Ref<KeyT> key,
                      Ref<ValueT> value) = 0;

  virtual MutVec<ValueT> find_values(Ref<KeyT> key) const = 0;
};
