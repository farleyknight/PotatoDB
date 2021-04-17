#pragma once

struct UnionValue {
  using store_t = union UnionValueType {
    int8_t boolean_;
    int8_t tinyint_;
    int16_t smallint_;
    int32_t integer_;
    int64_t bigint_;
    double decimal_;
    uint64_t timestamp_;
    char *varlen_;
  };

  template<typename T>
  static T cast_as(Ref<store_t> data) {
    return *reinterpret_cast<T*>(data);
  }
};

