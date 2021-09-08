#pragma once

#include "index/index_key.hpp"
#include "index/comp.hpp"
#include "catalog/index_schema.hpp"

class IndexComp : public Comp<IndexKey> {
public:
  // NOTE: Keeping this fixed on purpose for now.
  // Read the same comment for GenericKey.
  static constexpr int KEY_SIZE = 8;

  explicit IndexComp(const IndexSchema& index_schema,
                     const TableSchema& table_schema)
    : index_schema_ (index_schema),
      table_schema_ (table_schema)
  {}

  int operator()(IndexKey lhs, IndexKey rhs) const override {
    for (auto column_oid : index_schema_.column_oids()) {
      Value lhs_value = lhs.to_value(table_schema_, column_oid);
      Value rhs_value = rhs.to_value(table_schema_, column_oid);

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
  const IndexSchema& index_schema_;
  const TableSchema& table_schema_;
};
