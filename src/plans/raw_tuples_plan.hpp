#pragma once

#include "plans/base_plan.hpp"
#include "plans/raw_tuples.hpp"
#include "plans/schema_plan.hpp"

class RawTuplesPlan : public BasePlan,
                      public QuerySchemaPlan
{
public:
  RawTuplesPlan(QuerySchema schema,
                RawTuples raw_tuples)
    : BasePlan        (PlanType::RAW_TUPLES),
      QuerySchemaPlan (schema),
      raw_tuples_     (raw_tuples)
  {
    // std::cout << "Raw Tuples " << raw_tuples.to_string() << std::endl;
  }

  const RawTuples& raw_tuples() const {
    return raw_tuples_;
  }

  bool is_query() const {
    return false;
  }

private:
  RawTuples raw_tuples_;
};
