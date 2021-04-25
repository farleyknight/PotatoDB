#pragma once

/**
 * Txn states for 2PL:
 *
 *     _________________________
 *    |                         v
 * GROWING -> SHRINKING -> COMMITTED   ABORTED
 *    |__________|________________________^
 *
 * Txn states for Non-2PL:
 *     __________
 *    |          v
 * GROWING  -> COMMITTED     ABORTED
 *    |_________________________^
 *
 **/

enum class TxnState {
  GROWING = 0,
  SHRINKING = 1,
  // NOTE: Not originally part of the state diagram, but I would like to use
  // the term "finished" to mean that a txn is either COMMITTED or
  // ABORTED.
  // In the case that a txn tries to obtain a lock after it is COMMITTED
  // I actually transition it to aborted, just to be thorough.
  COMMITTED = 2,
  ABORTED = 3
};
