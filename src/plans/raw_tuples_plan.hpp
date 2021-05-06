#pragma once

#include "plans/base_plan.hpp"
#include "plans/raw_tuples.hpp"

class RawTuplesPlan : public BasePlan, public SchemaPlan {
public:
  RawTuplesPlan(QuerySchema schema, RawTuples raw_tuples)
    : BasePlan    (PlanType::RAW_TUPLES),
      SchemaPlan  (schema),
      raw_tuples_ (raw_tuples) {}

  const RawTuples& raw_tuples() const {
    return raw_tuples_;
  }

private:
  RawTuples raw_tuples_;
};
