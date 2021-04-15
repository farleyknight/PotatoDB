#pragma once

template<typename EncT>
class BufferRW {
public:
  BufferRW() {}

  void write_string(MutRef<Buffer> buff, String s) {
    encoding_.write_string(buff, s);
  }

  MutString read_string(Ref<Buffer> buff) {
    return encoding_._read_string(buff);
  }

  template<typename IntT>
  void write_int(MutRef<Buffer> buff, IntT n) {
    encoding_.template write_int<IntT>(buff, n);
  }

  template<typename IntT>
  IntT read_int(MutRef<Buffer> buff) {
    return encoding_.template read_int<IntT>(buff);
  }

  void write_int8(MutRef<Buffer> buff, int8_t n) {
    write_int<int8_t>(buff, n);
  }

  void write_int16(MutRef<Buffer> buff, int16_t n) {
    write_int<int16_t>(buff, n);
  }

  void write_int32(MutRef<Buffer> buff, int32_t n) {
    write_int<int32_t>(buff, n);
  }

  void write_int64(MutRef<Buffer> buff, int64_t n) {
    write_int<int64_t>(buff, n);
  }

  int8_t read_int8(Ref<Buffer> buff) {
    return read_int<int8_t>(buff);
  }

  int16_t read_int16(Ref<Buffer> buff) {
    return read_int<int16_t>(buff);
  }

  int32_t read_int32(Ref<Buffer> buff) {
    return read_int<int32_t>(buff);
  }

  int64_t read_int64(Ref<Buffer> buff) {
    return read_int<int64_t>(buff);
  }

  MutString to_hex_string(Ref<Buffer> buff) {
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
  EncT encoding_;
};
