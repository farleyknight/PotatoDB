#pragma once

#include <vector>

#include "common/types.hpp"

class Buffer {
public:
  using Data = vector<byte_t>;
  using string_size_t = byte_t;

  Buffer() {
    data_.resize(0);
  }

  Buffer(size_t size) {
    data_.resize(size);
  }

  // No copy
  Buffer(CRef<Buffer>) = delete;
  // No copy assign
  Buffer& operator=(CRef<Buffer>) = delete;

  Data& as_bytes() {
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

  byte_t* ptr(size_t offset) {
    return data_.data() + offset;
  }

  const byte_t* ptr(size_t offset) const {
    return data_.data() + offset;
  }

  void copy_n_bytes(size_t source_offset,
                    size_t dest_offset,
                    CRef<Buffer> source,
                    size_t n_bytes)
  {
    // TODO: Add assert to prevent out-of-bounds memory operations
    std::memcpy(ptr() + dest_offset,
                source.ptr() + source_offset,
                n_bytes);
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

  void write_int64(size_t offset, int64_t n) {
    *reinterpret_cast<int64_t*>(ptr(offset)) = n;
  }

  int64_t read_int64(size_t offset) const {
    return *reinterpret_cast<const int64_t*>(ptr(offset));
  }

  void write_int32(size_t offset, int32_t n) {
    *reinterpret_cast<int32_t*>(ptr(offset)) = n;
  }

  int32_t read_int32(size_t offset) const {
    return *reinterpret_cast<const int32_t*>(ptr(offset));
  }

  void write_uint32(size_t offset, int32_t n) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = n;
  }

  uint32_t read_uint32(size_t offset) const {
    return *reinterpret_cast<const uint32_t*>(ptr(offset));
  }

  void write_float(size_t offset, float f) {
    *reinterpret_cast<float*>(ptr(offset)) = f;
  }

  float read_float(size_t offset) const {
    return *reinterpret_cast<const float*>(ptr(offset));
  }

  void write_double(size_t offset, double d) {
    *reinterpret_cast<double*>(ptr(offset)) = d;
  }

  double read_double(size_t offset) const {
    return *reinterpret_cast<const double*>(ptr(offset));
  }

  void write_string(size_t offset, String value) {
    string_size_t size = value.size();

    auto c_string = reinterpret_cast<const unsigned char*>(value.c_str());

    std::memcpy(ptr(offset), &size, sizeof(string_size_t));
    std::memcpy(ptr(offset) + sizeof(string_size_t),
                c_string, size);
  }

  MutString read_string(size_t offset) {
    string_size_t size = as_bytes()[0];
    MutString new_string(size, 0);

    std::memcpy(new_string.data(),
                ptr(offset) + sizeof(string_size_t),
                size);

    return new_string;
  }
private:
  Data data_;
};
