#pragma once

#include "common/types.hpp"
#include "buffer/buffer_rw.hpp"

const int8_t bits_in_a_byte = 8;

class ByteEncoder {
public:
  friend class BufferRW<ByteEncoder>;

private:
  ByteEncoder() = default;

  template<typename IntT>
  void write_int(MRef<Buffer> buff, IntT n)  const{
    size_t num_bytes = sizeof(IntT);
    for (size_t i = 0; i < num_bytes; ++i) {
      buff.data_[i] = (n >> (i*bits_in_a_byte));
    }
  }

  template<typename IntT>
  IntT read_int(CRef<Buffer> buff) const {
    size_t num_bytes = sizeof(IntT);
    IntT n = 0;
    for (size_t i = 0; i < num_bytes; ++i) {
      IntT value = buff.data_[i];
      n = n + (value << (i*bits_in_a_byte));
    }
    return n;
  }

  // NOTE: Use union technique to convert to bytes,
  // as the >> operator trick does not work for floats or doubles
  union float_bytes_t {
    float val;
    unsigned char bytes[sizeof(float)];
  };

  void write_float(MRef<Buffer> buff, float f) const {
    float_bytes_t data;
    data.val = f;
    for (size_t i = 0; i < sizeof(float); ++i) {
      buff.data_[i] = data.bytes[i];
    }
  }

  float read_float(CRef<Buffer> buff) const {
    float_bytes_t data;
    for (size_t i = 0; i < sizeof(float); ++i) {
      data.bytes[i] = buff.data_[i];
    }
    return data.val;
  }

  union double_bytes_t {
    double val;
    unsigned char bytes[sizeof(double)];
  };

  void write_double(MRef<Buffer> buff, double d) const {
    double_bytes_t data;
    data.val = d;
    for (size_t i = 0; i < sizeof(double); ++i) {
      buff.data_[i] = data.bytes[i];
    }
  }

  float read_double(CRef<Buffer> buff) const {
    double_bytes_t data;
    for (size_t i = 0; i < sizeof(double); ++i) {
      data.bytes[i] = buff.data_[i];
    }
    return data.val;
  }

  using string_size_t = Buffer::string_size_t;

  void write_string(MRef<Buffer> buff, String s) {
    assert(s.size() < std::numeric_limits<string_size_t>::max());
    int8_t string_size = s.size();

    assert(buff.size() >= s.size() + sizeof(string_size_t));
    buff.data_[0] = string_size;
    const char *c_string = s.c_str();

    for (size_t i = 0; i < s.size(); ++i) {
      buff.data_[i + sizeof(string_size_t)] = c_string[i];
    }
  }

  MutString read_string(CRef<Buffer> buff) {
    string_size_t size = buff.data_[0];

    MutString new_string(size, 0);
    char *c_string = new_string.data();

    for (size_t i = 0; i < size; ++i) {
      c_string[i] = buff.data_[i + sizeof(string_size_t)];
    }

    return new_string;
  }
};
