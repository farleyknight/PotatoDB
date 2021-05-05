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

  // NOTE: Buffers are allowed to be copied, but Pages are not.
  // Allow copy
  Buffer(const Buffer&) = default;
  // Allow copy assign
  Buffer& operator=(const Buffer&) = default;

  Data& as_bytes() {
    return data_;
  }

  const Data& as_bytes() const {
    return data_;
  }

  byte_t* ptr() {
    return data_.data();
  }

  char* char_ptr() {
    return reinterpret_cast<char*>(data_.data());
  }

  const byte_t* cptr() const {
    return data_.data();
  }

  const char* char_ptr() const {
    return reinterpret_cast<const char*>(data_.data());
  }

  byte_t* ptr(size_t offset) {
    return data_.data() + offset;
  }

  const byte_t* cptr(size_t offset) const {
    return data_.data() + offset;
  }

  void copy_n_bytes(size_t source_offset,
                    size_t dest_offset,
                    const Buffer& source,
                    size_t n_bytes)
  {
    // TODO: Add assert to prevent out-of-bounds memory operations
    std::memcpy(ptr(dest_offset),
                source.cptr(source_offset),
                n_bytes);
  }

  void copy_from(const Buffer& other) {
    data_ = other.data_;
  }

  void reset_memory() {
    std::fill(data_.begin(), data_.end(), 0);
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

  template<typename numeric_t>
  void write_numeric(size_t offset, numeric_t n) {
    *reinterpret_cast<numeric_t*>(ptr(offset)) = n;
  }

  template<typename numeric_t>
  numeric_t read_numeric(size_t offset) const {
    return *reinterpret_cast<const numeric_t*>(cptr(offset));
  }

  void write_int64(size_t offset, int64_t n) {
    *reinterpret_cast<int64_t*>(ptr(offset)) = n;
  }

  int64_t read_int64(size_t offset) const {
    return *reinterpret_cast<const int64_t*>(cptr(offset));
  }

  void write_int32(size_t offset, int32_t n) {
    *reinterpret_cast<int32_t*>(ptr(offset)) = n;
  }

  int32_t read_int32(size_t offset) const {
    return *reinterpret_cast<const int32_t*>(cptr(offset));
  }

  void write_uint32(size_t offset, int32_t n) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = n;
  }

  uint32_t read_uint32(size_t offset) const {
    return *reinterpret_cast<const uint32_t*>(cptr(offset));
  }

  void write_bool(size_t offset, bool b) {
    *reinterpret_cast<bool*>(ptr(offset)) = b;
  }

  bool read_bool(size_t offset) const {
    return *reinterpret_cast<const bool*>(cptr(offset));
  }

  void write_int8(size_t offset, int8_t n) {
    *reinterpret_cast<int8_t*>(ptr(offset)) = n;
  }

  int64_t read_int8(size_t offset) const {
    return *reinterpret_cast<const int8_t*>(cptr(offset));
  }

  void write_float(size_t offset, float f) {
    *reinterpret_cast<float*>(ptr(offset)) = f;
  }

  float read_float(size_t offset) const {
    return *reinterpret_cast<const float*>(cptr(offset));
  }

  void write_double(size_t offset, double d) {
    *reinterpret_cast<double*>(ptr(offset)) = d;
  }

  double read_double(size_t offset) const {
    return *reinterpret_cast<const double*>(cptr(offset));
  }

  void write_string(size_t offset, const string& value) {
    string_size_t size = value.size();

    auto c_string = reinterpret_cast<const unsigned char*>(value.c_str());

    std::memcpy(ptr(offset), &size, sizeof(string_size_t));
    std::memcpy(ptr(offset) + sizeof(string_size_t),
                c_string, size);
  }

  string read_string(size_t offset) {
    string_size_t size = as_bytes()[0];
    string new_string(size, 0);

    std::memcpy(new_string.data(),
                ptr(offset) + sizeof(string_size_t),
                size);

    return new_string;
  }

  Data data_;
};
