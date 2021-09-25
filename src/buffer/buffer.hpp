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

  // TODO: This really doesn't print anything :(
  // We may need to convert each byte_t into hexidecimal format
  const string to_string() const {
    return string(char_ptr(), data_.size());
  }

  byte_t* ptr() {
    return data_.data();
  }

  char* char_ptr() {
    return reinterpret_cast<char*>(data_.data());
  }

  const char* char_ptr() const {
    return reinterpret_cast<const char*>(data_.data());
  }

  byte_t* ptr(buffer_offset_t offset) {
    return data_.data() + offset;
  }

  const byte_t* const_ptr() const {
    return data_.data();
  }

  // TODO: Rename to `const_ptr`
  const byte_t* const_ptr(buffer_offset_t offset) const {
    return data_.data() + offset;
  }

  void copy_n_bytes(buffer_offset_t source_offset,
                    buffer_offset_t dest_offset,
                    const Buffer& source,
                    size_t n_bytes)
  {
    // TODO: Add assert to prevent out-of-bounds memory operations
    std::memcpy(ptr(dest_offset),
                source.const_ptr(source_offset),
                n_bytes);
  }

  const Tuple
  read_tuple(buffer_offset_t offset);

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

  // NOTE: This method brings part of the buffer forward.
  //
  // Graphically, a call to unshift(1) will take a buffer like this:
  //
  // [ 0x12, 0x34, 0x56, ... ]
  //
  // to one that looks like this:
  //
  // [ 0x34, 0x56, ..., ... ]
  //
  // This is only really used in one place: LogRecovery
  // However, it may be useful for other parts of the code?
  // At the very least, it felt more natural to add this here
  void unshift(buffer_offset_t offset) {
    std::memmove(ptr(), ptr(offset), data_.size() - offset);
  }

  buffer_offset_t size() const {
    return data_.size();
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
    return *reinterpret_cast<const numeric_t*>(const_ptr(offset));
  }

  void write_int64(buffer_offset_t offset, int64_t n) {
    *reinterpret_cast<int64_t*>(ptr(offset)) = n;
  }

  int64_t read_int64(buffer_offset_t offset) const {
    return *reinterpret_cast<const int64_t*>(const_ptr(offset));
  }

  void write_int32(buffer_offset_t offset, int32_t n) {
    *reinterpret_cast<int32_t*>(ptr(offset)) = n;
  }

  int32_t read_int32(buffer_offset_t offset) const {
    return *reinterpret_cast<const int32_t*>(const_ptr(offset));
  }

  void write_uint32(buffer_offset_t offset, int32_t n) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = n;
  }

  uint32_t read_uint32(buffer_offset_t offset) const {
    return *reinterpret_cast<const uint32_t*>(const_ptr(offset));
  }

  void write_bool(buffer_offset_t offset, bool b) {
    *reinterpret_cast<bool*>(ptr(offset)) = b;
  }

  bool read_bool(buffer_offset_t offset) const {
    return *reinterpret_cast<const bool*>(const_ptr(offset));
  }

  void write_int8(buffer_offset_t offset, int8_t n) {
    *reinterpret_cast<int8_t*>(ptr(offset)) = n;
  }

  int64_t read_int8(buffer_offset_t offset) const {
    return *reinterpret_cast<const int8_t*>(const_ptr(offset));
  }

  void write_float(buffer_offset_t offset, float f) {
    *reinterpret_cast<float*>(ptr(offset)) = f;
  }

  float read_float(buffer_offset_t offset) const {
    return *reinterpret_cast<const float*>(const_ptr(offset));
  }

  void write_double(buffer_offset_t offset, double d) {
    *reinterpret_cast<double*>(ptr(offset)) = d;
  }

  double read_double(buffer_offset_t offset) const {
    return *reinterpret_cast<const double*>(const_ptr(offset));
  }

  void write_string(buffer_offset_t offset, const string& value);
  const string read_string(buffer_offset_t offset) const;

  /**********************************************
   * DB specific types
   **********************************************/

  lsn_t read_lsn(buffer_offset_t offset) const {
    return *reinterpret_cast<const lsn_t*>(const_ptr(offset));
  }

  void write_lsn(buffer_offset_t offset, lsn_t lsn) {
    *reinterpret_cast<lsn_t*>(ptr(offset)) = lsn;
  }

  txn_id_t read_txn_id(buffer_offset_t offset) const {
    return *reinterpret_cast<const txn_id_t*>(const_ptr(offset));
  }

  void write_txn_id(buffer_offset_t offset, txn_id_t txn_id) {
    *reinterpret_cast<txn_id_t*>(ptr(offset)) = txn_id;
  }

  void write_rid(buffer_offset_t offset, const RID& rid) {
    *reinterpret_cast<uint64_t*>(ptr(offset)) = rid.as_uint64();
  }

  RID read_rid(buffer_offset_t offset) const {
    auto rid_as_uint64 =
      *reinterpret_cast<const uint64_t*>(const_ptr(offset));
    return RID(rid_as_uint64);
  }

  void write_page_id(buffer_offset_t offset, const PageId& page_id) {
    *reinterpret_cast<uint32_t*>(ptr(offset)) = page_id.as_uint32();
  }

  PageId read_page_id(buffer_offset_t offset) const {
    auto page_id_as_uint32 =
      *reinterpret_cast<const uint32_t*>(const_ptr(offset));
    return PageId::from(page_id_as_uint32);
  }

  Data data_;
};
