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
  PROJECT      = 9,
  LOOP_JOIN    = 10,
  INDEX_JOIN   = 11,
  HASH_JOIN    = 12,
  SORT         = 13,
  CREATE_TABLE = 14
};
