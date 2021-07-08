#pragma once

enum class OperType {
  INVALID      = 0, // SINK
  TABLE_SCAN   = 1, // SOURCE
  INDEX_SCAN   = 2, // SOURCE
  INSERT       = 3, // SINK
  RAW_TUPLES   = 4, // SOURCE
  UPDATE       = 5, // SINK
  DELETE       = 6, // SINK
  AGG          = 7, // PIPE
  LIMIT        = 8, // PIPE or SINK
  PROJECT      = 9, // PIPE
  PREDICATE    = 10, // PIPE or SINK
  LOOP_JOIN    = 11, // 2->1 PIPE
  INDEX_JOIN   = 12, // 2->1 PIPE
  HASH_JOIN    = 13, // 2->1 PIPE
  SORT         = 14, // PIPE
  CREATE_TABLE = 15, // SINK
  RESULTS      = 16, // SINK
  COMBINE      = 17  // SOURCE
};

/*
 *

How to deal with init()?
* Keep track of all SOURCE operators
* We keep track of our SOURCE operators separately from
  others. We set some flag for each SOURCE operator,
  indicating that it has been initialized.


Keep track of: curr_tuple



 */
