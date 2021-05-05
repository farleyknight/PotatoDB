#pragma once

#include "common/config.hpp"
#include "common/hash_util.hpp"

#include "query/base_query.hpp"
#include "query/query_const.hpp"
#include "query/query_agg.hpp"
#include "query/query_group_by.hpp"
#include "query/query_having.hpp"

#include "plans/agg_key.hpp"
#include "plans/base_plan.hpp"

class AggPlan : public BasePlan {
public:
  /**********************************************
   * GroupByExpr and HavingExpr are both optional
   **********************************************/

  AggPlan(SchemaRef         schema_ref,
          ptr<BasePlan>&& child,
          MoveVec<QueryAgg> aggs);

  /**********************************************
   * HavingExpr is optional
   **********************************************/

  AggPlan(SchemaRef             schema,
          ptr<BasePlan>&&     child,
          MoveVec<QueryAgg>     aggs,
          MoveVec<QueryGroupBy> group_bys);

  /**********************************************
   * All child exprs required
   **********************************************/

  AggPlan(SchemaRef             schema,
          ptr<BasePlan>&&     child,
          MoveVec<QueryAgg>     aggs,
          MoveVec<QueryGroupBy> group_bys,
          ptr<QueryHaving>&&  having);

  void build_agg_types();

  PlanType type()  const { return PlanType::AGG; }

  ptr<BasePlan>&& child() {
    return move(child_);
  }

  bool has_having() {
    return having_ != nullptr;
  }

  const QueryHaving& having() {
    return *having_;
  }

  const BaseQuery& group_by_at(uint32_t idx) const {
    return group_bys_.at(idx);
  }

  const Vec<QueryGroupBy>& group_bys() const {
    return group_bys_;
  }

  const QueryAgg& agg_at(size_t idx) const {
    return aggs_.at(idx);
  }

  const Vec<QueryAgg>& aggs() const {
    return aggs_;
  }

  const Vec<AggType>& agg_types() const {
    return agg_types_;
  }

private:
  ptr<BasePlan> child_;

  vector<QueryAgg> aggs_;
  vector<AggType> agg_types_;
  vector<QueryGroupBy> group_bys_;

  ptr<QueryHaving> having_;
};
