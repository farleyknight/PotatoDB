#pragma once

enum class PlanType {
  INVALID      =  0,
  TABLE_SCAN   =  1,
  INDEX_SCAN   =  2,
  INSERT       =  3,
  RAW_TUPLES   =  4,
  UPDATE       =  5,
  DELETE       =  6,
  AGG          =  7,
  LIMIT        =  8,
  PROJECT      =  9,
  PREDICATE    = 10,
  LOOP_JOIN    = 11,
  INDEX_JOIN   = 12,
  HASH_JOIN    = 13,
  SORT         = 14,
  CREATE_TABLE = 15,
  RESULTS      = 16,
  COMBINE      = 17
};
