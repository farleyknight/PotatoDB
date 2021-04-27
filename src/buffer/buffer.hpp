#pragma once

#include <vector>

#include "common/types.hpp"

class Buffer {
public:
  using byte_t = uint8_t;
  using Data = vector<byte_t>;
  using string_size_t = byte_t;

  Buffer() {
    data_.resize(0);
  }

  Buffer(size_t size) {
    data_.resize(size);
  }

  // TODO: Write perf tests to see if `move`-ed Buffers are
  // faster than implicitly copied buffers.

  // No copy
  Buffer(CRef<Buffer>) = delete;
  // No copy assign
  MRef<Buffer> operator=(CRef<Buffer>) = delete;

  MRef<Data> as_bytes() {
    return data_;
  }

  CRef<Data> as_bytes() const {
    return data_;
  }

  byte_t* ptr() {
    return data_.data();
  }

  const byte_t* ptr() const {
    return data_.data();
  }

  void copy_from(CRef<Buffer> other) {
    data_ = other.data_;
  }

  size_t size() const {
    return data_.size();
  }

  void resize(size_t new_size) {
    data_.resize(new_size);
  }

  Data::iterator begin() {
    return data_.begin();
  }

  Data::iterator end() {
    return data_.end();
  }

private:
  Data data_;
};

