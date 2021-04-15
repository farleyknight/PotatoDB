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

private:
  Data data_;
};

