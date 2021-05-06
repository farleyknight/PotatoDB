#pragma once

#include "catalog/query_schema.hpp"

class SchemaPlan {
public:
  SchemaPlan(QuerySchema schema)
    : schema_ (schema)
  {}

  const QuerySchema& schema() {
    return schema_;
  }

private:
  QuerySchema schema_;
};
