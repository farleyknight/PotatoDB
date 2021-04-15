#pragma once

enum class BufferEnc {
  BYTE = 0,
  CAST = 1
};

class BufferRW {
public:
  static void write_string(MutRef<Buffer> buff, String s);
  static void write_int8(MutRef<Buffer> buff, int8_t n);
  static void write_int16(MutRef<Buffer> buff, int16_t n);

  template<BufferEnc enc>
  static void write_int32(MutRef<Buffer> buff, int32_t n);
  static void write_int64(MutRef<Buffer> buff, int64_t n);

  static MutString read_string(Ref<Buffer> buff);
  static int8_t    read_int8(Ref<Buffer> buff);
  static int16_t   read_int16(Ref<Buffer> buff);
  static int32_t   read_int32(Ref<Buffer> buff);
  static int64_t   read_int64(Ref<Buffer> buff);

  static MutString to_hex_string(Ref<Buffer> buff);
};
