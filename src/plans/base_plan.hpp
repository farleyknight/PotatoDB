#pragma once

#include <utility>
#include <vector>

#include "catalog/query_schema.hpp"
#include "catalog/schema_ref.hpp"

enum class PlanType {
  INVALID    = 0,
  TABLE_SCAN = 1,
  INDEX_SCAN = 2,
  INSERT     = 3,
  RAW_TUPLES = 4,
  UPDATE     = 5,
  DELETE     = 6,
  AGG        = 7,
  LIMIT      = 8,
  LOOP_JOIN  = 9,
  INDEX_JOIN = 10,
  HASH_JOIN  = 11,
  SORT       = 12
};

class BasePlan {
public:
  BasePlan(SchemaRef schema_ref)
    : schema_ref_ (schema_ref)
  {}

  BasePlan(const BasePlan& plan);
  BasePlan& operator=(const BasePlan& plan);

  SchemaRef schema_ref() const { return schema_ref_; }
  PlanType type()        const { return PlanType::INVALID; }
private:
  SchemaRef schema_ref_;
};
