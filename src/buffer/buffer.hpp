#pragma once

#include "common/types.hpp"
#include <vector>

class Buffer {
public:
  using Data = std::vector<uint8_t>;
  friend class BufferRW;

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

private:
  Data data_;
};

