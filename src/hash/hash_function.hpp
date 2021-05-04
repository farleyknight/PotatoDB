#include <cstdint>

#include <MurmurHash3.h>

template <typename KeyT>
class HashFunc {
public:
  /**
   * @param key the key to be hashed
   * @return the hashed value
   */
  virtual uint64_t hash(KeyT key) {
    uint64_t hash[2];
    MurmurHash3_x64_128(reinterpret_cast<const void *>(&key),
                        static_cast<int>(sizeof(KeyT)),
                        0,
                        reinterpret_cast<void *>(&hash));
    return hash[0];
  }
};
