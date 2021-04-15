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
      n = n + (buff.data_[i] << (i*bits_in_a_byte));
    }
    return n;
  }
};
