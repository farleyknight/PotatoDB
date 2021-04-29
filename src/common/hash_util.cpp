
#include "common/hash_util.hpp"
#include "tuple/value.hpp"

hash_t HashUtil::hash_value(Ref<Value> val) {
  switch (val.type_id()) {
  case TypeId::TINYINT: {
    auto raw = static_cast<int64_t>(val.get_as<int8_t>());
    return hash<int64_t>(&raw);
  }
  case TypeId::SMALLINT: {
    auto raw = static_cast<int64_t>(val.get_as<int16_t>());
    return hash<int64_t>(&raw);
  }
  case TypeId::INTEGER: {
    auto raw = static_cast<int64_t>(val.get_as<int32_t>());
    return hash<int64_t>(&raw);
  }
  case TypeId::BIGINT: {
    auto raw = static_cast<int64_t>(val.get_as<int64_t>());
    return hash<int64_t>(&raw);
  }
  case TypeId::BOOLEAN: {
    auto raw = val.get_as<bool>();
    return hash<bool>(&raw);
  }
  case TypeId::DECIMAL: {
    auto raw = val.get_as<double>();
    return hash<double>(&raw);
  }
  case TypeId::VARCHAR: {
    auto raw = val.varlen();
    auto len = val.length();
    return hash_bytes(raw, len);
  }
  case TypeId::TIMESTAMP: {
    auto raw = val.get_as<uint64_t>();
    return hash<uint64_t>(&raw);
  }

  default:
    throw Exception(ExceptionType::UNKNOWN_TYPE, "Unknown type.");
  }
}
