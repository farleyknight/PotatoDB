#pragma once

#include "query/base_query.hpp"
#include "catalog/query_schema.hpp"

enum class AggType {
  // INVALID = 0, TODO: Do I need this?
  COUNT = 1,
  SUM = 2,
  MIN = 3,
  MAX = 4
};

class QueryAgg : public BaseQuery {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  QueryAgg(BaseQuery node,
           AggType agg_type);

  // Allow copy
  QueryAgg(CRef<QueryAgg>) = default;
  // Allow copy assign
  QueryAgg& operator=(CRef<QueryAgg>) = default;
  // Default destructor
  ~QueryAgg() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  Value eval(CRef<Tuple> tuple, CRef<QuerySchema> schema) const;

  Value eval_join(CRef<Tuple> lt,
                  CRef<QuerySchema> ls,
                  CRef<Tuple> rt,
                  CRef<QuerySchema> rs) const;

  // TODO: Why is it that eval_agg was (from BusTub) the only one w/o a schema param?
  // Not sure if it was the right call. The other two evals have schemas. I think its
  // best to assume it must be passed in. Any other places where this is not already
  // changed should include the schema.
  Value eval_agg(CRef<QuerySchema> schema,
                 CRef<Vec<Value>> group_bys,
                 CRef<Vec<Value>> aggregates) const;

  AggType agg_type() const {
    return agg_type_;
  }

  TypeId type_id() const {
    return node_.type_id();
  }

  String to_string() const;

private:
  BaseQuery node_;
  AggType agg_type_;
};
