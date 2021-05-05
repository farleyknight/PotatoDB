#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

#include "common/types.hpp"

class Value;

using hash_t = std::size_t;

class HashUtil {
private:
  static const hash_t prime_factor = 10000019;

public:
  static inline hash_t hash_bytes(const char bytes[], size_t length) {
    // https://github.com/greenplum-db/gpos/blob/b53c1acd6285de94044ff91fbee91589543feba1/libgpos/src/utils.cpp#L126
    hash_t hash = length;
    for (size_t i = 0; i < length; ++i) {
      hash = ((hash << 5) ^ (hash >> 27)) ^ bytes[i];
    }
    return hash;
  }

  static inline hash_t combine_hashes(hash_t l, hash_t r) {
    hash_t both[2];
    both[0] = l;
    both[1] = r;
    return hash_bytes(reinterpret_cast<char *>(both), sizeof(hash_t) * 2);
  }

  static inline hash_t sum_hashes(hash_t l, hash_t r) {
    return (l % prime_factor + r % prime_factor) % prime_factor;
  }

  template <typename T>
  static inline hash_t hash(const T *ptr) {
    return hash_bytes(reinterpret_cast<const char *>(ptr), sizeof(T));
  }

  template <typename T>
  static inline hash_t hash_pointer(const T *ptr) {
    return hash_bytes(reinterpret_cast<const char *>(&ptr), sizeof(void *));
  }

  static hash_t hash_value(const Value& val);
};
