#pragma once

#include "plans/base_plan.hpp"
#include "plans/raw_tuples.hpp"

class RawTuplesPlan : public BasePlan {
public:
  RawTuplesPlan(SchemaRef schema_ref,
                RawTuples raw_tuples)
    : BasePlan    (schema_ref),
      raw_tuples_ (raw_tuples) {}

  CRef<RawTuples> raw_tuples() const {
    return raw_tuples_;
  }

  PlanType type() const {
    return PlanType::RAW_TUPLES;
  }

private:
  RawTuples raw_tuples_;
};
