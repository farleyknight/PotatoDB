#pragma once

#include <list>

#include "common/config.hpp"

class LockRequestQueue {
public:
  // First element of the queue
  LockRequest &first() {
    return requests.front();
  }

  // Last element of the queue
  LockRequest &last() {
    return requests.back();
  }

  list<LockRequest>::iterator begin() {
    return requests.begin();
  }

  list<LockRequest>::iterator end() {
    return requests.end();
  }

  // Add new element to the queue
  void append(LockRequest &request) {
    requests.push_back(request);
  }

  list<LockRequest> requests;
  cond_var cond;  // for notifying blocked txns on this rid

  // NOTE: This `upgrading` flag is something that bugged me for several
  // hours one day.
  //
  // I'm not sure if it's name is the best. It indicates if the request
  // queue has or is transitioning from a shared lock to an exclusive lock.
  // Previous implementations of LockMgr used a different way to keep
  // track of this information, via a counter of exclusive locks. In a
  // sense, the variable `upgrading` can act like the counter
  // `exclusive_cnt`, except just turn it on/off depending on the context.
  //
  // In the name of trying to stay true to the original assignment,
  // I will stick to this variable name. But I may decide to nix it
  // entirely and replace it
  // with another way to track this information.
  bool upgrading = false;

  // NOTE: Given what I mentioned about the variable `upgrading`, I
  // still believe that keeping track of the oldest txn id is the best
  // approach for the wait-die scenarios.
  txn_id_t oldest_id;
};
