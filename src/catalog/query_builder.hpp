#pragma once

#include "exprs/table_expr.hpp"
#include "exprs/column_expr.hpp"

#include "catalog/catalog.hpp"

/*************************************
 * QueryBuilder
 *************************************/

class QueryBuilder {
public:
  QueryBuilder(CRef<Catalog> catalog)
    : catalog_ (catalog) {}
  
  // No copy
  QueryBuilder(CRef<QueryBuilder>) = delete;
  // No copy assign
  QueryBuilder& operator=(CRef<QueryBuilder>) = delete;
  // Default destructor
  ~QueryBuilder() = default;

  TableExpr table(String table_name) const;

private:
  CRef<Catalog> catalog_;
};
