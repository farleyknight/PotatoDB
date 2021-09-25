#include "txns/txn_abort_exception.hpp"

const string
TxnAbortException::info() const {
  switch (abort_reason_) {
  case AbortReason::LOCK_ON_SHRINKING:
    return message("Cannot take locks in the shrinking state.");

  case AbortReason::UNLOCK_ON_SHRINKING:
    return message("Cannot excute unlock in the shrinking state.\n");

  case AbortReason::UPGRADE_CONFLICT:
    return message("Another txn is already waiting to upgrade its lock.");

  case AbortReason::DEADLOCK:
    return message("Deadlock was detected.");

  case AbortReason::LOCKSHARED_ON_READ_UNCOMMITTED:
    return message("Lock Shared attempted on READ_UNCOMMITTED mode.");

  case AbortReason::TUPLE_TOO_BIG:
    return message("Tuple does not fit into a page.");

  case AbortReason::TUPLE_SCHEMA_MISMATCH:
    return message("Tuple does not match schema.");

  case AbortReason::PAGE_NOT_AVAILABLE:
    return message("The page is not available from the buffer pool.");

  case AbortReason::WAIT_OR_DIE:
    return message("Txn tried to obtain a lock while an older txn held it.");

  case AbortReason::LOCK_AFTER_FINISHED:
    return message("Attempted to unlock after it was already COMMITTED or ABORTED.");

  case AbortReason::STRICT_2PL_VIOLATION:
    return message("Txn tried to obtain a lock during its SHRINKING phase.");
  }

  // TODO: Should fail with unreachable.
  return ""; 
}
