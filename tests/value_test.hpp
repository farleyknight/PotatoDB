#pragma once

#include "value/value.hpp"
#include "buffer/buffer.hpp"

// TODO: Test serialize and deserialize for all value types.
//
// This includes integers of all sizes, plus decimal, timestamp, and varchar

class ValueTest : public ::testing::Test {
public:
  template<typename value_t>
  void SerializeAndDeserializeTest(TypeId type_id) {
    // TODO!
  }
};

