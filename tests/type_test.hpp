#pragma once

#include "types/type_id.hpp"
#include "types/type.hpp"
#include "value/value.hpp"

#include "type_tests_fixture.hpp"

TEST_F(TypeTests, CompareValueTest) {
  std::string temp = "32";
  Value val1 = Value::make(temp);
  Value val2 = Value::make(32);
  EXPECT_TRUE(val1.eq(val2));
}

TEST_F(TypeTests, TypeSingletonTest) {
  // TODO: Maybe iterate over all TypeIds and check singleton instances are equal?
  auto &bool_type = Type::instance(TypeId::BOOLEAN);
  EXPECT_EQ(bool_type->type_id(), TypeId::BOOLEAN);

  auto &bool_type2 = Type::instance(TypeId::BOOLEAN);

  // Compare addresses.. they should be identical
  EXPECT_EQ(&bool_type, &bool_type2);

  // TODO: Maybe iterate over all TypeIds and check singleton instances are equal?
  auto &tinyint_type = Type::instance(TypeId::TINYINT);
  auto &tinyint_type2 = Type::instance(TypeId::TINYINT);

  // Compare addresses.. they should be identical
  EXPECT_EQ(&tinyint_type, &tinyint_type2);
}

TEST_F(TypeTests, StringValueTest) {
  string test_string = "some text";
  int length = test_string.size();
  Value val = Value::make(test_string);

  // Size should be the actual length of the string + length of string in int8_t
  EXPECT_EQ(val.size(), length + sizeof(int8_t));

  string new_string = val.as<string>();
  EXPECT_EQ(new_string, test_string);
  EXPECT_FALSE(val.is_null());

  // TODO
  // EXPECT_TRUE(val.to_string() == "some text");
}
