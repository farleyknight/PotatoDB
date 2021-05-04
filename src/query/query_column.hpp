#pragma once

#include "catalog/table_column.hpp"
#include "query/base_query.hpp"

class TableSchema;
class QuerySchema;

class QueryColumn : public BaseQuery {
public:

  // TODO: We should be able to create a QueryColumn via a TableColumn
  // Can we inherit both from BaseQuery and BaseColumn?
  QueryColumn(TypeId type_id,
              string name)
    : BaseQuery (type_id),
      name_     (name)
  {}

  // Allow copy
  QueryColumn(CRef<QueryColumn>) = default;
  // Allow copy assign
  QueryColumn& operator=(CRef<QueryColumn>) = default;
  // Default destructor
  ~QueryColumn() = default;

  Value eval(UNUSED CRef<Tuple> tuple,
             UNUSED CRef<QuerySchema> schema) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

  Value eval_join(UNUSED CRef<Tuple> lt,
                  UNUSED CRef<QuerySchema> ls,
                  UNUSED CRef<Tuple> rt,
                  UNUSED CRef<QuerySchema> rs) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

  Value eval_agg(UNUSED CRef<QuerySchema> schema,
                 UNUSED CRef<Vec<Value>> group_bys,
                 UNUSED CRef<Vec<Value>> aggs) const {
    throw NotImplementedException("eval_agg not implemented!");
  }

  string name() const {
    return name_;
  }

  bool is_inlined() const {
    return false; // TODO!
  }

  bool fixed_length() {
    return 0; // TODO!
  }

  size_t variable_length() const {
    return 0; // TODO!
  }

private:
  string name_;
};
