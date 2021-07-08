#include "gtest/gtest.h"

#include "buffer_rw_test.hpp"

#include "executor_test.hpp"

#include "parser_test.hpp"
#include "potatodb_test.hpp"
#include "potatodb_todos_test.hpp"

#include "recovery_redo_test.hpp"
#include "recovery_undo_test.hpp"
#include "recovery_checkpoint_test.hpp"

#include "schema_test.hpp"

#include "tuple_test.hpp"

#include "type_test.hpp"
#include "type_instance_tests.hpp"

#include "value_test.hpp"


/*
 *
 TEST(MainTest, HelloWorldTest) {
 std::cout << "Hello, world!" << std::endl;
 ASSERT_TRUE(true);
 }

 
 */

int main(int argc, char **argv) {
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
