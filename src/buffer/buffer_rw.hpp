#pragma once

// #include "buffer/cast_encoder.hpp"
class CastEncoder;

template<typename EncT = CastEncoder>
class BufferRW {
public:
  using string_size_t = int8_t;

  BufferRW() {}

  void write_string(Buffer& buff, const string s) {
    // std::cout << "Using write_string" << std::endl;
    encoder_.write_string(buff, s);
  }

  const string read_string(const Buffer& buff) {
    return encoder_.read_string(buff);
  }

  template<typename IntT>
  void write_int(Buffer& buff, IntT n) const {
    encoder_.template write_int<IntT>(buff, n);
  }

  template<typename IntT>
  IntT read_int(const Buffer& buff) const {
    return encoder_.template read_int<IntT>(buff);
  }

  void write_float(Buffer& buff, float f) const {
    encoder_.write_float(buff, f);
  }

  float read_float(const Buffer& buff) const {
    return encoder_.read_float(buff);
  }

  void write_double(Buffer& buff, float f) const {
    encoder_.write_double(buff, f);
  }

  float read_double(const Buffer& buff) const {
    return encoder_.read_double(buff);
  }

  void write_int8(const Buffer& buff, int8_t n) const {
    write_int<int8_t>(buff, n);
  }

  void write_int16(Buffer& buff, int16_t n) const {
    write_int<int16_t>(buff, n);
  }

  void write_int32(Buffer& buff, int32_t n) const {
    write_int<int32_t>(buff, n);
  }

  void write_int64(Buffer& buff, int64_t n) const {
    write_int<int64_t>(buff, n);
  }

  int8_t read_int8(const Buffer& buff) const {
    return read_int<int8_t>(buff);
  }

  int16_t read_int16(const Buffer& buff) const {
    return read_int<int16_t>(buff);
  }

  int32_t read_int32(const Buffer& buff) const {
    return read_int<int32_t>(buff);
  }

  int64_t read_int64(const Buffer& buff) const {
    return read_int<int64_t>(buff);
  }

  const string to_hex_string(const Buffer& buff) {
    const int8_t lower_byte_mask = 0x0F;
    const char hex_chars[] = "0123456789ABCDEF";
    string result(buff.size() * 2, 0);
    char *char_buff = const_cast<char *>(result.data());

    for (auto const &byte : buff.as_bytes()) {
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
