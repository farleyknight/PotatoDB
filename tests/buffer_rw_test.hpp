#pragma once

#include <limits>

#include "common/types.hpp"
#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"

TEST(BufferRWTest, RWInt8ToBuffer) {
  Buffer buff(1);
  const int8_t val = 24;

  BufferRW::write_int8(buff, val);
  EXPECT_EQ(BufferRW::read_int8(buff), val);
}

TEST(BufferRWTest, RWInt16ToBuffer) {
  Buffer buff(2);
  const int16_t val = std::numeric_limits<int16_t>::max();

  BufferRW::write_int16(buff, val);
  EXPECT_EQ(BufferRW::read_int16(buff), val);
}

TEST(BufferRWTest, RWInt32ToBufferByteEnc) {
  Buffer buff(4);
  const int32_t val = 24 * 1000 * 1000;

  BufferRW::write_int32<BufferEnc::BYTE>(buff, val);
  EXPECT_EQ(BufferRW::read_int32(buff), val);
}

TEST(BufferRWTest, RWInt32ToBufferCastEnc) {
  Buffer buff(4);
  const int32_t val = 24 * 1000 * 1000;

  BufferRW::write_int32<BufferEnc::CAST>(buff, val);
  EXPECT_EQ(BufferRW::read_int32(buff), val);
}

TEST(BufferRWTest, RWInt64ToBuffer) {
  Buffer buff(8);
  int64_t val = 24 * 1000 * 1000;
  val = val * 1000;

  BufferRW::write_int64(buff, val);
  EXPECT_EQ(BufferRW::read_int64(buff), val);
}

TEST(BufferRWTest, BufferToHexString) {
  Buffer buff(4);
  const int32_t val = 103303;

  BufferRW::write_int32<BufferEnc::BYTE>(buff, val);
  EXPECT_EQ(BufferRW::to_hex_string(buff), "87930100");
}

TEST(BufferRWTest, DISABLED_RWFloatsToBuffer) {
  // TODO
}

TEST(BufferRWTest, DISABLED_RWDoublesToBuffer) {
  // TODO
}

TEST(BufferRWTest, DISABLED_RWStringsToBuffer) {
  // TODO
}
