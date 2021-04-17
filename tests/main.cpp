#include "gtest/gtest.h"

#include "buffer_rw_test.hpp"
#include "value_test.hpp"
#include "type_test.hpp"
#include "type_instance_tests.hpp"
#include "tuple_test.hpp"
#include "schema_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
