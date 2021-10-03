#pragma once

#include "index/index_key.hpp"
#include "index/comp.hpp"
#include "catalog/index_schema.hpp"

class IndexComp : public Comp<IndexKey> {
public:
  // NOTE: Keeping this fixed on purpose for now.
  // Read the same comment for GenericKey.
  static constexpr int KEY_SIZE = 8;

  explicit
  IndexComp(const TupleLayout& layout)
    : layout_ (layout)
  {}

  int operator()(IndexKey lhs, IndexKey rhs) const override {
    for (const auto &[oid, val] : layout_.value_layouts()) {
      Value lhs_value = lhs.to_value(layout_, oid);
      Value rhs_value = rhs.to_value(layout_, oid);

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
  const TupleLayout& layout_;
};
