#pragma once

#include "value/value.hpp"

class SortKey {
public:
  SortKey(Value value)
    : value_ (value)
  {}

  const Value value() const {
    return value_;
  }

  bool operator<(const SortKey& other) const {
    return value_.lt(other.value_);
  }

private:
  Value value_;
};

template <>
struct std::hash<SortKey> {
  hash_t operator()(const SortKey& key) const {
    hash_t curr_hash = 0;
    auto value = key.value();
    if (!value.is_null()) {
      curr_hash = HashUtil::hash_value(value);
    }
    return curr_hash;
  }
};
