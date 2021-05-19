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

// TODO: Lets get rid of ByteEncoder
// CastEncoder does everything we need and is more low-level
using Encodings = testing::Types<CastEncoder, ByteEncoder>;

TYPED_TEST_SUITE(BufferRWTest, Encodings);

TYPED_TEST(BufferRWTest, RWInt8ToBuffer) {
  using IntT = int8_t;

  Buffer buff(sizeof(IntT));

  const IntT max = numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}

TYPED_TEST(BufferRWTest, RWInt16ToBuffer) {
  using IntT = int16_t;

  Buffer buff(sizeof(IntT));

  const IntT max = numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}

TYPED_TEST(BufferRWTest, RWInt32ToBuffer) {
  using IntT = int32_t;

  Buffer buff(sizeof(IntT));

  const IntT max = numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}


TYPED_TEST(BufferRWTest, RWInt64ToBuffer) {
  using IntT = int64_t;

  Buffer buff(sizeof(IntT));

  const IntT max = numeric_limits<IntT>::max();
  this->encoder_.template write_int<IntT>(buff, max);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), max);

  const IntT min = numeric_limits<IntT>::min();
  this->encoder_.template write_int<IntT>(buff, min);
  EXPECT_EQ(this->encoder_.template read_int<IntT>(buff), min);
}

TYPED_TEST(BufferRWTest, RWFloatsToBuffer) {
  Buffer buff(sizeof(float));

  const float max = numeric_limits<float>::max();
  this->encoder_.write_float(buff, max);
  EXPECT_EQ(this->encoder_.read_float(buff), max);

  const float min = numeric_limits<float>::min();
  this->encoder_.write_float(buff, min);
  EXPECT_EQ(this->encoder_.read_float(buff), min);
}

const double margin_of_error = 0.00001;

// TODO: Finish working on doubles.
// We may have to cut this feature out to make good on time.
TYPED_TEST(BufferRWTest, DISABLED_RWDoublesToBuffer) {
  Buffer buff(sizeof(double));

  double d = 1.0;
  while (d < 10000000) {
    this->encoder_.write_double(buff, d);
    EXPECT_NEAR(this->encoder_.read_double(buff), d, margin_of_error);

    this->encoder_.write_double(buff, -d);
    EXPECT_NEAR(this->encoder_.read_double(buff), -d, margin_of_error);

    d *= 10;
  }

  this->encoder_.write_double(buff, numeric_limits<double>::max() - 1);
  EXPECT_EQ(this->encoder_.to_hex_string(buff), "000000000000F07F");

  this->encoder_.write_double(buff, numeric_limits<double>::max());
  EXPECT_EQ(this->encoder_.to_hex_string(buff), "000000000000F07F");

  double double_max = this->encoder_.read_double(buff);
  EXPECT_EQ(double_max, numeric_limits<double>::infinity());
}

TYPED_TEST(BufferRWTest, DRWMoreDoublesToBuffer) {
  Buffer buff(sizeof(double));

  const double val1 = 0.123;
  this->encoder_.write_double(buff, val1);
  EXPECT_NEAR(this->encoder_.read_double(buff), val1, margin_of_error);

  const double val2 = 123.456;
  this->encoder_.write_double(buff, val2);
  EXPECT_NEAR(this->encoder_.read_double(buff), val2, margin_of_error);
}

TYPED_TEST(BufferRWTest, BufferToHexString) {
  Buffer buff(sizeof(int32_t));
  const int32_t val = 103303;
  const string hex_string = "87930100";

  this->encoder_.write_int32(buff, val);
  EXPECT_EQ(this->encoder_.to_hex_string(buff), hex_string);
}

TYPED_TEST(BufferRWTest, RWStringsToBuffer) {
  string val = "hello, world!";

  size_t buffer_size = val.size() + sizeof(string_size_t);
  Buffer buff(buffer_size);

  this->encoder_.write_string(buff, val);
  EXPECT_EQ(this->encoder_.read_string(buff), val);
}
