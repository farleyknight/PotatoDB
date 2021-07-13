#pragma once

#include "common/config.hpp"
#include "vm/op_code.hpp"
#include "vm/vm_stmt.hpp"

class VirtMach {
public:
  VirtMach() {}

  void load(vector<VMStmt> stmts) {
    stmts_ = move(stmts);
  }

  void execute() {
    // TODO!
  }

  vector<string> disassemble() {
    return disassemble(0);
  }

  template<typename ReturnType>
  ReturnType result() {
    return 5;
  }

  vector<string> disassemble(int offset) {
    vector<string> result;
    auto instruction = stmts_.at(offset).code();
    switch (static_cast<OpCode>(instruction)) {
    case OpCode::RETURN:
      return simple(move(result), "RETURN", offset);
    default:
      fmt::print("Unknown opcode {}\n", instruction);
      return result;
    }
  }

  vector<string> simple(vector<string>&& opcodes, string name, int offset) {
    opcodes.push_back(fmt::format("{:04} {}\n", offset, name));
    return opcodes;
  }

  int print_disassemble(int offset) {
    auto instruction = stmts_.at(offset).code();
    switch (static_cast<OpCode>(instruction)) {
    case OpCode::RETURN:
      return print_simple("RETURN", offset);
    default:
      fmt::print("Unknown opcode {}\n", instruction);
      return offset + 1;
    }
  }

  int print_simple(string name, int offset) {
    fmt::print("{:04} {}\n", name);
    return offset + 1;
  }

private:
  vector<VMStmt> stmts_ {};
};
