#pragma once

#include <vector>
#include <iostream>

#include "common/config.hpp"
#include "tuple/rid.hpp"

class Tuple;

class Buffer {
public:
  using Data = vector<byte_t>;

  Buffer() {
    data_.resize(0);
  }

  Buffer(buffer_offset_t size) {
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

  byte_t* ptr(buffer_offset_t offset) {
    return data_.data() + offset;
  }

  const byte_t* cptr(buffer_offset_t offset) const {
    return data_.data() + offset;
  }

  void copy_n_bytes(buffer_offset_t source_offset,
                    buffer_offset_t dest_offset,
                    const Buffer& source,
                    size_t n_bytes)
  {
    // TODO: Add assert to prevent out-of-bounds memory operations
    std::memcpy(ptr(dest_offset),
                source.cptr(source_offset),
                n_bytes);
  }

  void write_tuple(buffer_offset_t offset, const Tuple& tuple);

  void copy_from(const Buffer& other) {
    data_ = other.data_;
  }

  void reset_memory() {
    std::fill(data_.begin(), data_.end(), 0);
  }

  void swap(Buffer& other) {
    data_.swap(other.data_);
  }

  buffer_offset_t size() const {
    return data_.size();
  }

  void truncate() {
    data_.resize(0);
  }

  void resize(buffer_offset_t new_size) {
    data_.resize(new_size);
  }

  Data::iterator begin() {
    return data_.begin();
  }

  Data::iterator end() {
    return data_.end();
  }

  template<typename numeric_t>
  void write_numeric(buffer_offset_t offset, numeric_t n) {
    *reinterpret_cast<numeric_t*>(ptr(offset)) = n;
  }

  template<typename numeric_t>
  numeric_t read_numeric(buffer_offset_t offset) const {
    return *reinterpret_cast<const numeric_t*>(cptr(offset));
  }

  void write_int64(buffer_offset_t offset, int64_t n) {
    *reinterpret_cast<int64_t*>(ptr(offset)) = n;
  }

  int64_t read_int64(buffer_offset_t offset) const {
    return *reinterpret_cast<const int64_t*>(cptr(offset));
  }

  void write_int32(buffer_offset_t offset, int32_t n) {
    *reinterpret_cast<int32_t*>(ptr(offset)) = n;
  }

  int32_t read_int32(buffer_offset_t offset) const {
    return *reinterpret_cast<const int32_t*>(cptr(offset));
  }

  void write_uint32(buffer_offset_t offset, int32_t n) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = n;
  }

  uint32_t read_uint32(buffer_offset_t offset) const {
    return *reinterpret_cast<const uint32_t*>(cptr(offset));
  }

  void write_bool(buffer_offset_t offset, bool b) {
    *reinterpret_cast<bool*>(ptr(offset)) = b;
  }

  bool read_bool(buffer_offset_t offset) const {
    return *reinterpret_cast<const bool*>(cptr(offset));
  }

  void write_int8(buffer_offset_t offset, int8_t n) {
    *reinterpret_cast<int8_t*>(ptr(offset)) = n;
  }

  int64_t read_int8(buffer_offset_t offset) const {
    return *reinterpret_cast<const int8_t*>(cptr(offset));
  }

  void write_float(buffer_offset_t offset, float f) {
    *reinterpret_cast<float*>(ptr(offset)) = f;
  }

  float read_float(buffer_offset_t offset) const {
    return *reinterpret_cast<const float*>(cptr(offset));
  }

  void write_double(buffer_offset_t offset, double d) {
    *reinterpret_cast<double*>(ptr(offset)) = d;
  }

  double read_double(buffer_offset_t offset) const {
    return *reinterpret_cast<const double*>(cptr(offset));
  }

  void write_string(buffer_offset_t offset, const string& value) {
    string_size_t length = value.size();

    auto c_string = reinterpret_cast<const unsigned char*>(value.c_str());

    std::memcpy(ptr(offset),
                &length, sizeof(string_size_t));
    std::memcpy(ptr(offset + sizeof(string_size_t)),
                c_string, length);
  }

  const string read_string(buffer_offset_t offset) const {
    string_size_t size;
    std::memcpy(&size, cptr(offset), sizeof(string_size_t));

    string new_string(size, 0);
    std::memcpy(new_string.data(),
                cptr(offset + sizeof(string_size_t)),
                size);

    return new_string;
  }

  /**********************************************
   * DB specific types
   **********************************************/

  void write_lsn(buffer_offset_t offset, lsn_t lsn) {
    *reinterpret_cast<lsn_t*>(ptr(offset)) = lsn;
  }

  void write_txn_id(buffer_offset_t offset, txn_id_t txn_id) {
    *reinterpret_cast<txn_id_t*>(ptr(offset)) = txn_id;
  }

  void write_rid(buffer_offset_t offset, const RID& rid) {
    *reinterpret_cast<uint64_t*>(ptr(offset)) = rid.as_uint64();
  }

  RID read_rid(buffer_offset_t offset) const {
    auto rid_as_int64 = *reinterpret_cast<const uint64_t*>(cptr(offset));
    return RID(rid_as_int64);
  }

  void write_page_id(buffer_offset_t offset, const PageId& page_id) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = page_id.as_uint32();
  }

  Data data_;
};
