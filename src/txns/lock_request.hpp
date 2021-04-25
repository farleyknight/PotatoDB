#pragma once

#include "common/config.hpp"

enum class LockMode { SHARED, EXCLUSIVE };

class LockRequest {
public:
  // NOTE: I don't think LockRequest has an appropriate use case
  // for a pointer?
  // If this is not true, update this note.

  /**********************************************
  * Constructors & destructor
  **********************************************/

  LockRequest(txn_id_t id, LockMode mode)
    : txn_id    (id),
      granted   (false),
      lock_mode (mode) {}

  // Allow copy
  LockRequest(CRef<LockRequest>) = default;
  // Allow copy assign
  MRef<LockRequest> operator=(CRef<LockRequest>) = default;

  /**********************************************
  * Instance methods
  **********************************************/

  bool is_exclusive() {
    return lock_mode == LockMode::EXCLUSIVE;
  }

  bool is_shared() {
    return lock_mode == LockMode::SHARED;
  }

  void set_mode(LockMode mode) {
    lock_mode = mode;
  }

  bool operator==(Ref<LockRequest> other) {
    return (
      txn_id == other.txn_id &&
      granted == other.granted &&
      lock_mode == other.lock_mode
    );
  }

  bool operator!=(Ref<LockRequest> other) {
    return (
      txn_id != other.txn_id ||
      granted != other.granted ||
      lock_mode != other.lock_mode
    );
  }

  txn_id_t txn_id;
  bool granted;
  LockMode lock_mode;
};
