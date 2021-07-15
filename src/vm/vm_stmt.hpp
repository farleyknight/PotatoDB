#pragma once

#include "common/config.hpp"

class VMStmt {
public:
  VMStmt(OpCode code)
    : code_ (code)
  {}

  VMStmt(OpCode code, int32_t arg1)
    : code_ (code),
      arg1_ (arg1)
  {}

  VMStmt(OpCode code, int32_t arg1, int32_t arg2)
    : code_ (code),
      arg1_ (arg1),
      arg2_ (arg2)
  {}

  OpCode code() {
    return code_;
  }


private:
  OpCode code_;
  UNUSED int32_t arg1_, arg2_;
};


class VMValue {
public:
  VMValue(int32_t start, int32_t end, TypeId type_id)
    : start_   (start),
      end_     (end),
      type_id_ (type_id)
  {}

private:
  UNUSED int32_t start_, end_;
  UNUSED TypeId type_id_;
};


class VMStack {
public:
  VMStack(int32_t num_of_bytes)
    : num_of_bytes_ (num_of_bytes)
  {
    data_.resize(num_of_bytes); // How many bytes our data stack holds
  }

  void push() {
    // TODO: Should have multiple versions of `push`, one for each type?
  }

  void pop() {
    // TODO: Zero out previous value
    // Update stack pointer
  }

private:
  UNUSED int32_t num_of_bytes_;
  UNUSED int32_t stack_pointer_ = 0;
  vector<byte_t> data_;
  vector<VMValue> values_;
};
