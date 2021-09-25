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

  // Attempting to INSERT or UPDATE a Tuple where the values
  // provided do not match the schema
  TUPLE_SCHEMA_MISMATCH,

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

  const string
  prefix() const {
    return "Txn " + std::to_string(txn_id_) + " Abort Reason :: ";
  }

  const string
  message(const string text) const {
    return prefix() + text + "\n";
  }

  const string
  info() const;
};
