#include "gtest/gtest.h"
#include "vm/virt_mach.hpp"

TEST(VMTest, ReturnTest) {
  VirtMach vm;

  vector<VMStmt> stmts = {
    {OpCode::RETURN}
  };

  vm.load(move(stmts));
  vm.execute();

  auto result = vm.disassemble();

  vector<string> expected {"0000 RETURN\n"};

  EXPECT_EQ(result, expected);
}

TEST(VMTest, ConstantsTest) {
  // TODO!
}

// TODO: Add support for constants:
// https://craftinginterpreters.com/chunks-of-bytecode.html#constants

// TODO: Add support for line numbers:
// https://craftinginterpreters.com/chunks-of-bytecode.html#line-information

TEST(VMTest, AddIntsTest) {
  VirtMach vm;

  vector<VMStmt> stmts = {
    {OpCode::LOAD_INT32, 4},
    {OpCode::LOAD_INT32, 1},
    {OpCode::ADD_INT32},
    {OpCode::RETURN}
  };

  vm.load(move(stmts));
  vm.execute();

  auto result = vm.result<int32_t>();

  EXPECT_EQ(result, 5);
}

