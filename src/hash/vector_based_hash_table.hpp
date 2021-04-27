#pragma once

#include "common/hash_util.hpp"
#include "hash/hash_table.hpp"

template<class K, class V>
class VectorBasedHT : public HashTable<K, V> {
public:
  using KVPair = std::pair<K, V>;

  VectorBasedHT(size_t capacity)
    : capacity_ (capacity)
  {
    assert(capacity_ > 0);
    table_.resize(capacity);
  }

  bool insert(Ref<K> key, Ref<V> value) {
    auto index = slot_index(key);
    table_[index].push_back(KVPair(key, value));
    return true;
  }

  MutVec<V> find_values(Ref<K> key) const {
    auto index = slot_index(key);
    auto pairs = table_[index];

    MutVec<V> values;
    for (auto const& pair : pairs) {
      if (pair.first == key) {
        values.push_back(pair.second);
      }
    }
    return values;
  }

  bool remove(Ref<K> key, Ref<V> value) {
    auto index = slot_index(key);
    auto pairs = table_[index];
    auto removed = false;
    pairs.remove_if([&key, &removed](KVPair pair) {
      if (pair.first == key) {
        removed = true;
        return true;
      }
      return false;
    });
    return removed;
  }

private:
  slot_offset_t slot_index(Ref<Value> key) {
    // NOTE: hash_fn_ is most likely something from `HashUtils::`
    return HashUtil::hash_value(key) % capacity_;
  }

  slot_offset_t slot_index(Ref<hash_t> key) const {
    return key % capacity_;
  }

  size_t capacity_;
  MutVec<MutList<KVPair>> table_;
};
