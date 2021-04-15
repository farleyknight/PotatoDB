#include "common/types.hpp"
#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"

const int8_t bits_in_a_byte = 8;

void BufferRW::write_string(MutRef<Buffer> buff, String s) {
  // TODO!
}

void BufferRW::write_int8(MutRef<Buffer> buff, int8_t n) {
  size_t num_bytes = 1;
  for (int i = 0; i < num_bytes; ++i) {
    buff.data_[i] = (n >> (i*bits_in_a_byte));
  }
}

void BufferRW::write_int16(MutRef<Buffer> buff, int16_t n) {
  size_t num_bytes = 2;
  for (int i = 0; i < num_bytes; ++i) {
    buff.data_[i] = (n >> (i*bits_in_a_byte));
  }
}

void BufferRW::write_int32(MutRef<Buffer> buff, int32_t n) {
  size_t num_bytes = 4;
  for (int i = 0; i < num_bytes; ++i) {
    buff.data_[i] = (n >> (i*bits_in_a_byte));
  }
}

void BufferRW::write_int64(MutRef<Buffer> buff, int64_t n) {
  size_t num_bytes = bits_in_a_byte;
  for (int i = 0; i < num_bytes; ++i) {
    buff.data_[i] = (n >> (i*bits_in_a_byte));
  }
}

MutString BufferRW::read_string(Ref<Buffer> buff) {
  // TODO
  return "";
}

int8_t BufferRW::read_int8(Ref<Buffer> buff) {
  size_t num_bytes = 1;
  int8_t n = 0;

  for (int i = 0; i < num_bytes; ++i) {
    n = n + (buff.data_[i] << (i*bits_in_a_byte));
  }

  return n;
}

int16_t BufferRW::read_int16(Ref<Buffer> buff) {
  size_t num_bytes = 2;
  int16_t n = 0;

  for (int i = 0; i < num_bytes; ++i) {
    n = n + (buff.data_[i] << (i*bits_in_a_byte));
  }

  return n;
}

int32_t BufferRW::read_int32(Ref<Buffer> buff) {
  size_t num_bytes = 4;
  int32_t n = 0;

  for (int i = 0; i < num_bytes; ++i) {
    n = n + (buff.data_[i] << (i*bits_in_a_byte));
  }

  return n;
}

int64_t BufferRW::read_int64(Ref<Buffer> buff) {
  size_t num_bytes = bits_in_a_byte;
  int64_t n = 0;

  for (int i = 0; i < num_bytes; ++i) {
    int64_t temp = buff.data_[i];
    n = n + (temp << (i*bits_in_a_byte));
  }

  return n;
}

const int8_t lower_byte_mask = 0x0F;

MutString BufferRW::to_hex_string(Ref<Buffer> buff) {
  static const char hex_chars[] = "0123456789ABCDEF";
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
