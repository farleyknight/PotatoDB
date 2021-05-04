#pragma once

#include "query/base_query.hpp"
#include "catalog/query_schema.hpp"

class QueryHaving : public BaseQuery {
public:
  QueryHaving(TypeId type_id,
              BaseQuery having_clause);

  Value eval_agg(CRef<QuerySchema> schema,
                 CRef<Vec<Value>> group_bys,
                 CRef<Vec<Value>> aggs) const;

private:
  // NOTE: A HavingExpr could contain more than just comparisons.
  // It might even be a ColumnExpr
  // Consider the case:
  // SELECT COUNT(a), MIN(b), MAX(c)
  // FROM table_1
  // GROUP BY name
  // HAVING MIN(b)
  //
  // Now technically, you really should be doing something like:
  // HAVING MIN(b) > 0
  //
  // But realize that we are grouping by name. And then we are
  // checking of MIN(b) is "truthy". This can occur when we
  // have to cast MIN(b) to true/false and since 0 is, byte-wise,
  // a "false" value'.
  //
  // This whole entire situation now has me realizing that the
  // way that types can be cast and converted to one another is
  // a really big issue for our database!
  BaseQuery having_clause_;
};
