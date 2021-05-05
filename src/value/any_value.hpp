#pragma once

#include <any>

#include "common/types.hpp"

struct AnyValue {
  using store_t = std::any;

  template<typename T>
  static T cast_as(const store_t& data) {
    return std::any_cast<T>(data);
  }
};
