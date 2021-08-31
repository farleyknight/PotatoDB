#pragma once

#include <cstdint>

#include <murmurhash.h>

template <typename KeyT>
class HashFunc {
public:
  virtual uint64_t hash(KeyT key) {
    uint64_t hash[2];
    lmmh_x64_128(reinterpret_cast<const void *>(&key),
                 static_cast<int>(sizeof(KeyT)),
                 0,
                 reinterpret_cast<uint64_t *>(&hash));
    return hash[0];
  }
};
