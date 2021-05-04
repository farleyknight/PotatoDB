#pragma once

#include "common/config.hpp"

enum class AbortReason {
  LOCK_ON_SHRINKING,
  UNLOCK_ON_SHRINKING,
  UPGRADE_CONFLICT,
  DEADLOCK,
  LOCKSHARED_ON_READ_UNCOMMITTED,

  // Tuple given was bigger than page.
  TUPLE_TOO_BIG,

  // Couldn't find the page or it's not available.
  PAGE_NOT_AVAILABLE,

  // Failed because we decided to die instead of wait for a lock.
  WAIT_OR_DIE,

  // Txn attempt to acquire lock but was already finished.
  LOCK_AFTER_FINISHED,

  // In Strict 2PL, we do not allow unlocks unless the txn is finished
  STRICT_2PL_VIOLATION
};

class TxnAbortException : public std::exception {
  txn_id_t txn_id_;
  AbortReason abort_reason_;

public:
  explicit TxnAbortException(txn_id_t txn_id, AbortReason abort_reason)
  : txn_id_(txn_id), abort_reason_(abort_reason) {}

  txn_id_t id() { return txn_id_; }

  AbortReason abort_reason() { return abort_reason_; }

  std::string prefix() {
    return "Txn " + std::to_string(txn_id_) + " Abort Reason :: ";
  }

  std::string message(std::string text) {
    return prefix() + text + "\n";
  }

  std::string info() {
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
};
