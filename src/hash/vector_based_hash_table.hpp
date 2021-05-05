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

  virtual bool insert(const K& key,
                      const K& value) override
  {
    auto index = slot_index(key);
    table_[index].push_back(KVPair(key, value));
    return true;
  }

  virtual vector<V> find_values(const K& key) override {
    auto index = slot_index(key);
    auto pairs = table_[index];

    vector<V> values;
    for (auto const& pair : pairs) {
      if (pair.first == key) {
        values.push_back(pair.second);
      }
    }
    return values;
  }

  virtual bool remove(const K& key) override {
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
  slot_offset_t slot_index(const K& key) {
    // NOTE: hash_fn_ is most likely something from `HashUtils::`
    return HashUtil::hash_value(key) % capacity_;
  }

  slot_offset_t slot_index(const K& key) const {
    return key % capacity_;
  }

  size_t capacity_;
  vector<MutList<KVPair>> table_;
};
