#pragma once

#include <variant>

struct VariantValue {
  using store_t = std::variant<bool,
                               int8_t,
                               int16_t,
                               int32_t,
                               int64_t,
                               double,
                               uint64_t,
                               char *,
                               std::string
                               >;

  template<typename T>
  static T cast_as(const store_t& data) {
    return std::get<T>(data);
  }
};
