
#include "common/exceptions.hpp"
#include "common/hash_util.hpp"
#include "value/value.hpp"

hash_t HashUtil::hash_value(const Value& val) {
  switch (val.type_id()) {
  case TypeId::TINYINT: {
    auto raw = static_cast<int8_t>(val.as<int8_t>());
    return hash<int8_t>(&raw);
  }
  case TypeId::SMALLINT: {
    auto raw = static_cast<int16_t>(val.as<int16_t>());
    return hash<int16_t>(&raw);
  }
  case TypeId::INTEGER: {
    auto raw = static_cast<int32_t>(val.as<int32_t>());
    return hash<int32_t>(&raw);
  }
  case TypeId::BIGINT: {
    auto raw = static_cast<int64_t>(val.as<int64_t>());
    return hash<int64_t>(&raw);
  }
  case TypeId::BOOLEAN: {
    auto raw = val.as<bool>();
    return hash<bool>(&raw);
  }
  case TypeId::DECIMAL: {
    auto raw = val.as<double>();
    return hash<double>(&raw);
  }
  case TypeId::VARCHAR: {
    auto raw = val.as<string>();
    return hash_bytes(raw.c_str(), raw.size());
  }
  case TypeId::TIMESTAMP: {
    auto raw = val.as<uint64_t>();
    return hash<uint64_t>(&raw);
  }

  default:
    throw Exception(ExceptionType::UNKNOWN_TYPE, "Unknown type.");
  }
}
