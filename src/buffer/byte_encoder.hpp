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
  void write_int(MutRef<Buffer> buff, IntT n) {
    size_t num_bytes = sizeof(IntT);
    for (size_t i = 0; i < num_bytes; ++i) {
      buff.data_[i] = (n >> (i*bits_in_a_byte));
    }
  }

  template<typename IntT>
  IntT read_int(Ref<Buffer> buff) {
    size_t num_bytes = sizeof(IntT);
    IntT n = 0;
    for (int i = 0; i < num_bytes; ++i) {
      IntT value = buff.data_[i];
      n = n + (value << (i*bits_in_a_byte));
    }
    return n;
  }

  using string_size_t = Buffer::string_size_t;

  void write_string(MutRef<Buffer> buff, String s) {
    assert(s.size() < std::numeric_limits<string_size_t>::max());
    int8_t string_size = s.size();

    // NOTE: Should be the same as s.size() + 1
    assert(buff.size() >= s.size() + sizeof(string_size_t));
    buff.data_[0] = string_size;
    const char *c_string = s.c_str();

    for (size_t i = 0; i < s.size(); ++i) {
      buff.data_[i + sizeof(string_size_t)] = c_string[i];
    }
  }

  MutString read_string(Ref<Buffer> buff) {
    string_size_t size = buff.data_[0];

    MutString new_string(size, 0);
    char *c_string = new_string.data();

    for (size_t i = 0; i < size; ++i) {
      c_string[i] = buff.data_[i + sizeof(string_size_t)];
    }

    return new_string;
  }
};
