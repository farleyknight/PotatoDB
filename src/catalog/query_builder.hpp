#pragma once

#include "catalog/query_table.hpp"

#include "catalog/catalog.hpp"

class QueryBuilder {
public:
  QueryBuilder(const Catalog& catalog)
    : catalog_ (catalog) {}

  // No copy
  QueryBuilder(const QueryBuilder&) = delete;
  // No copy assign
  QueryBuilder& operator=(const QueryBuilder&) = delete;
  // Default destructor
  ~QueryBuilder() = default;

  QueryTable table(const table_name_t table_name) const;

private:
  const Catalog& catalog_;
};
