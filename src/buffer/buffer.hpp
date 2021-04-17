#pragma once

#include "common/types.hpp"
#include <vector>

// TODO: Let's add:
// * seek method
// * operator[] for access to the buffer
// The seek method sets an offset
// The operator[] reads data, starting at the offset.

class Buffer {
public:
  using byte_t = uint8_t;
  using Data = std::vector<byte_t>;
  using string_size_t = byte_t;

  Buffer(size_t size) {
    data_.resize(size);
  }

  // TODO: Write perf tests to see if `move`-ed Buffers are
  // faster than implicitly copied buffers.

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

