#pragma once

#include "catalog/table_column.hpp"
#include "query/base_query.hpp"

class TableSchema;
class QuerySchema;

class QueryColumn : public BaseQuery {
public:
  QueryColumn(TypeId type_id,
              // table_oid_t table_oid,
              // column_oid_t column_oid,
              string column_name);

  // Allow copy
  QueryColumn(CRef<QueryColumn>) = default;
  // Allow copy assign
  QueryColumn& operator=(CRef<QueryColumn>) = default;
  // Default destructor
  ~QueryColumn() = default;

  Value eval(CRef<Tuple> tuple, CRef<TableSchema> schema) const;

  Value eval_join(CRef<Tuple> lt,
                  CRef<QuerySchema> ls,
                  CRef<Tuple> rt,
                  CRef<QuerySchema> rs) const;

  Value eval_agg(CRef<QuerySchema> schema,
                 CRef<Vec<Value>> group_bys,
                 CRef<Vec<Value>> aggs) const;
  string name() const;

private:
  column_oid_t column_oid_;
  // table_oid_t table_oid_;
  string column_name_;
};
