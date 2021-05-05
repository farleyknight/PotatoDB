#pragma once

#include "exprs/table_expr.hpp"
#include "exprs/column_expr.hpp"

#include "catalog/catalog.hpp"

/*************************************
 * QueryBuilder
 *************************************/

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

  TableExpr table(const string table_name) const;

private:
  const Catalog& catalog_;
};
