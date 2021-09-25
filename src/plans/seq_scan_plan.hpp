#pragma once

#include "common/config.hpp"
#include "plans/base_plan.hpp"
#include "plans/table_plan.hpp"
#include "plans/query_schema_plan.hpp"
#include "plans/maybe_pred_plan.hpp"

class SeqScanPlan : public BasePlan,
                    public TablePlan,
                    public QuerySchemaPlan,
                    // TODO: If we need a custom schema,
                    // use the Projection plan to emit
                    // only those columns the query is
                    // asking for.
                    public MaybePredPlan
{
public:
  SeqScanPlan(QuerySchema schema,
              table_oid_t table_oid,
              ptr<QueryWhere>&& pred)
    : BasePlan        (PlanType::TABLE_SCAN),
      TablePlan       (table_oid),
      QuerySchemaPlan (schema),
      MaybePredPlan   (move(pred))
  {}

  bool is_query() const {
    return true;
  }
};
