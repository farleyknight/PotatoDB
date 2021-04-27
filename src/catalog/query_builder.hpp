#pragma once

#include "exprs/table_expr.hpp"
#include "exprs/column_expr.hpp"

#include "catalog/catalog.hpp"

/*************************************
 * QueryBuilder
 *************************************/

class QueryBuilder {
public:
  QueryBuilder(Ref<Catalog> catalog);

  // No copy
  QueryBuilder(Ref<QueryBuilder>) = delete;
  // No copy assign
  MRef<QueryBuilder> operator=(Ref<QueryBuilder>) = delete;
  // Default destructor
  ~QueryBuilder() = default;

  TableExpr table(String table_name) const;

private:
  Ref<Catalog> catalog_;
};
