#pragma once

#include "vm/vm_type_id.hpp"

class VMValue {
public:
  VMValue(int32_t start, int32_t end, TypeId type_id)
    : start_   (start),
      end_     (end),
      type_id_ (type_id)
  {}

private:
  int32_t start_, end_;
  VMType_id type_id_;
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
  int32_t num_of_bytes_;
  int32_t stack_pointer_ = 0;
  vector<byte_t> data_;
  vector<VMValue> values_;
};
