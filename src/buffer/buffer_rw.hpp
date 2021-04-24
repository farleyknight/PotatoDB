#pragma once

// #include "buffer/cast_encoder.hpp"
class CastEncoder;

template<typename EncT = CastEncoder>
class BufferRW {
public:
  using string_size_t = int8_t;

  BufferRW() {}

  void write_string(MRef<Buffer> buff, String s) {
    encoder_.write_string(buff, s);
  }

  MutString read_string(CRef<Buffer> buff) {
    return encoder_.read_string(buff);
  }

  template<typename IntT>
  void write_int(MRef<Buffer> buff, IntT n) const {
    encoder_.template write_int<IntT>(buff, n);
  }

  template<typename IntT>
  IntT read_int(CRef<Buffer> buff) const {
    return encoder_.template read_int<IntT>(buff);
  }

  void write_float(MRef<Buffer> buff, float f) const {
    encoder_.write_float(buff, f);
  }

  float read_float(CRef<Buffer> buff) const {
    return encoder_.read_float(buff);
  }

  void write_double(MRef<Buffer> buff, float f) const {
    encoder_.write_double(buff, f);
  }

  float read_double(CRef<Buffer> buff) const {
    return encoder_.read_double(buff);
  }

  void write_int8(MRef<Buffer> buff, int8_t n) const {
    write_int<int8_t>(buff, n);
  }

  void write_int16(MRef<Buffer> buff, int16_t n) const {
    write_int<int16_t>(buff, n);
  }

  void write_int32(MRef<Buffer> buff, int32_t n) const {
    write_int<int32_t>(buff, n);
  }

  void write_int64(MRef<Buffer> buff, int64_t n) const {
    write_int<int64_t>(buff, n);
  }

  int8_t read_int8(CRef<Buffer> buff) const {
    return read_int<int8_t>(buff);
  }

  int16_t read_int16(CRef<Buffer> buff) const {
    return read_int<int16_t>(buff);
  }

  int32_t read_int32(CRef<Buffer> buff) const {
    return read_int<int32_t>(buff);
  }

  int64_t read_int64(CRef<Buffer> buff) const {
    return read_int<int64_t>(buff);
  }

  MutString to_hex_string(CRef<Buffer> buff) {
    const int8_t lower_byte_mask = 0x0F;
    const char hex_chars[] = "0123456789ABCDEF";
    MutString result(buff.data_.size() * 2, 0);
    char *char_buff = const_cast<char *>(result.data());

    for (auto const &byte : buff.data_) {
      *char_buff = hex_chars[byte >> 4];
      char_buff++;
      *char_buff = hex_chars[byte & lower_byte_mask];
      char_buff++;
    }
    return result;
  }

private:
  EncT encoder_;
};
