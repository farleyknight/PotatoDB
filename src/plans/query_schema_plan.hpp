#pragma once

#include "catalog/query_schema.hpp"

class QuerySchemaPlan {
public:
  QuerySchemaPlan(QuerySchema schema)
    : schema_ (schema)
  {
    assert(schema.column_count() > 0);
  }

  const QuerySchema&
  schema() {
    return schema_;
  }

private:
  QuerySchema schema_;
};
