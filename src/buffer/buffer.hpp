#pragma once

#include "common/types.hpp"
#include <vector>

class Buffer {
public:
  using byte_t = uint8_t;
  using Data = std::vector<byte_t>;
  using string_size_t = byte_t;

  Buffer(size_t size) {
    data_.resize(size);
  }

  // No copy
  Buffer(Ref<Buffer>) = delete;
  // No copy assign
  MutRef<Buffer> operator=(Ref<Buffer>) = delete;

  uint8_t* data() {
    return data_.data();
  }

  const uint8_t* data() const {
    return data_.data();
  }

  Data data_;
};

