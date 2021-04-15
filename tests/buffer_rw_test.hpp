#pragma once

#include <limits>
 
#include "common/types.hpp"
#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"
#include "buffer/byte_encoder.hpp"
#include "buffer/cast_encoder.hpp"

template<typename EncT>
class BufferRWTest : public testing::Test {
public:
  BufferRW<EncT> encoder_;
};

using Encodings = testing::Types<CastEncoder, ByteEncoder>;

TYPED_TEST_SUITE(BufferRWTest, Encodings);

TYPED_TEST(BufferRWTest, RWInt8ToBuffer) {
  using IntT = int8_t;

  Buffer buff(sizeof(IntT));

  const IntT max = std::numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = std::numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}

TYPED_TEST(BufferRWTest, RWInt16ToBuffer) {
  using IntT = int16_t;

  Buffer buff(sizeof(IntT));

  const IntT max = std::numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = std::numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}

TYPED_TEST(BufferRWTest, RWInt32ToBuffer) {
  using IntT = int32_t;

  Buffer buff(sizeof(IntT));

  const IntT max = std::numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = std::numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}


TYPED_TEST(BufferRWTest, RWInt64ToBuffer) {
  using IntT = int64_t;

  Buffer buff(sizeof(IntT));

  const IntT max = std::numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = std::numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}


TYPED_TEST(BufferRWTest, BufferToHexString) {
  Buffer buff(4);
  const int32_t val = 103303;
  String hex_string = "87930100";

  this->encoder_.write_int32(buff, val);
  EXPECT_EQ(this->encoder_.to_hex_string(buff), hex_string);
}

TYPED_TEST(BufferRWTest, RWStringsToBuffer) {
  String val = "hello, world!";

  size_t buffer_size = val.size() + sizeof(Buffer::string_size_t);
  Buffer buff(buffer_size);

  this->encoder_.write_string(buff, val);
  EXPECT_EQ(this->encoder_.read_string(buff), val);
}

TEST(BufferRWTest, DISABLED_RWFloatsToBuffer) {
  // TODO
}

TEST(BufferRWTest, DISABLED_RWDoublesToBuffer) {
  // TODO
}
