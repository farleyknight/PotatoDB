#pragma once

#include "catalog/table_schema.hpp"

class TableSchemaPlan {
public:
  TableSchemaPlan(TableSchema& schema)
    : schema_ (schema)
  {
    assert(schema.column_count() > 0);
  }

  TableSchema&
  schema() {
    return schema_;
  }

private:
  TableSchema& schema_;
};
