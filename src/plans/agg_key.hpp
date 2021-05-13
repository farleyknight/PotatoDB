#pragma once

#include "common/config.hpp"
#include "common/hash_util.hpp"

#include "value/value.hpp"

class AggKey {
public:
  AggKey(vector<Value> group_bys)
    : group_bys_ (group_bys) {}

  const Vec<Value>& group_bys() const {
    return group_bys_;
  }

  bool operator==(const AggKey& other) const {
    for (uint32_t i = 0; i < other.group_bys_.size(); i++) {
      if (!group_bys_[i].eq(other.group_bys_[i])) {
        return false;
      }
    }
    return true;
  }

  vector<Value> group_bys_;
};

class AggValue {
public:
  AggValue(vector<Value> aggs)
    : aggs_ (aggs) {}

  const Vec<Value>& aggs() {
    return aggs_;
  }

  vector<Value> aggs_;
};


template <>
struct std::hash<AggKey> {
  std::size_t operator()(const AggKey& key) const {
    size_t curr_hash = 0;
    for (const auto &key : key.group_bys()) {
      if (!key.is_null()) {
        curr_hash = HashUtil::combine_hashes(curr_hash,
                                             HashUtil::hash_value(key));
      }
    }
    return curr_hash;
  }
};
