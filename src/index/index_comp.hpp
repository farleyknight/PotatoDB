#pragma once

#include "index/index_key.hpp"
#include "index/comp.hpp"
#include "catalog/index_schema.hpp"

class IndexComp : public Comp<IndexKey> {
public:
  // NOTE: Keeping this fixed on purpose for now.
  // Read the same comment for GenericKey.
  static constexpr int KEY_SIZE = 8;

  explicit IndexComp(const IndexSchema& key_schema)
    : key_schema_ (key_schema)
  {}

  IndexComp(const IndexComp& other)
    : key_schema_ (other.key_schema_)
  {}

  int operator()(IndexKey lhs, IndexKey rhs) const override {
    uint32_t column_count = key_schema_.column_count();

    for (uint32_t i = 0; i < column_count; i++) {
      Value lhs_value = lhs.to_value(key_schema_, i);
      Value rhs_value = rhs.to_value(key_schema_, i);

      if (lhs_value.lt(rhs_value)) {
        return -1;
      }

      if (lhs_value.gt(rhs_value)) {
        return 1;
      }
    }
    return 0;
  }

private:
  const IndexSchema& key_schema_;
};
