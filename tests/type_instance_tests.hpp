#pragma once

// A single test for each Type instance

#include "type_tests_fixture.hpp"

TEST_F(TypeTests, InvalidTypeTest) {
  TypeId type_id = TypeId::INVALID;
  auto &invalid_type = Type::instance(type_id);

  EXPECT_EQ(type_id, invalid_type->type_id());
  EXPECT_FALSE(invalid_type->is_castable_from(type_id));

  EXPECT_THROW(invalid_type->size(), Exception);
  EXPECT_THROW(invalid_type->min(), Exception);
  EXPECT_THROW(invalid_type->max(), Exception);
}

TEST_F(TypeTests, BooleanType) {
  InstanceTest<bool>(TypeId::BOOLEAN, false, true);
}

TEST_F(TypeTests, TinyIntType) {
  InstanceTest<int8_t>(TypeId::TINYINT);
}

TEST_F(TypeTests, SmallIntType) {
  InstanceTest<int16_t>(TypeId::SMALLINT);
}

TEST_F(TypeTests, IntegerType) {
  InstanceTest<int32_t>(TypeId::INTEGER);
}

TEST_F(TypeTests, BigIntType) {
  InstanceTest<int64_t>(TypeId::BIGINT);
}

TEST_F(TypeTests, DISABLED_DecimalType) {
  // TODO: DecimalType test
}

TEST_F(TypeTests, DISABLED_TimestampType) {
  // TODO: TimestampType test
}

TEST_F(TypeTests, DISABLED_VarCharType) {
  // TODO: VarCharType test
}


TEST_F(TypeTests, DISABLED_SerializeAndDeserializeTest_BOOLEAN) {
  SerializeAndDeserialize<bool>(TypeId::BOOLEAN, false, true);
}

TEST_F(TypeTests, SerializeAndDeserializeTest_TINYINT) {
  SerializeAndDeserialize<int8_t>(TypeId::TINYINT);
}

TEST_F(TypeTests, SerializeAndDeserializeTest_SMALLINT) {
  SerializeAndDeserialize<int16_t>(TypeId::SMALLINT);
}

TEST_F(TypeTests, SerializeAndDeserializeTest_INTEGER) {
  SerializeAndDeserialize<int32_t>(TypeId::INTEGER);
}

TEST_F(TypeTests, SerializeAndDeserializeTest_BIGINT) {
  SerializeAndDeserialize<int64_t>(TypeId::BIGINT);
}

TEST(TypeTest, DISABLED_SerializeAndDeserializeTest_DECIMAL) {

}

TEST(TypeTest, DISABLED_SerializeAndDeserializeTest_TIMESTAMP) {

}

TEST(TypeTest, DISABLED_SerializeAndDeserializeTest_VARCHAR) {

}


