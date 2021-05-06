#pragma once

enum class PlanType {
  INVALID      = 0,
  TABLE_SCAN   = 1,
  INDEX_SCAN   = 2,
  INSERT       = 3,
  RAW_TUPLES   = 4,
  UPDATE       = 5,
  DELETE       = 6,
  AGG          = 7,
  LIMIT        = 8,
  LOOP_JOIN    = 9,
  INDEX_JOIN   = 10,
  HASH_JOIN    = 11,
  SORT         = 12,
  CREATE_TABLE = 13
};
