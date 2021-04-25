#include "txns/lock_mgr.hpp"

LockMgr::LockMgr(TwoPLMode two_pl_mode = TwoPLMode::STRICT,
                 DeadlockMode deadlock_mode = DeadlockMode::PREVENTION)
  : two_pl_mode_   (two_pl_mode),
    deadlock_mode_ (deadlock_mode)
{
  // NOTE: Our lock manager must implement 2PL.
  // The flag is to determine if we are using strict 2PL or just
  // ordinary 2PL.
  //
  // Regular 2PL:
  // * First phase: acquire all locks.
  // * Second phase: release locks as they are no longer needed.
  //
  // Strict 2PL: -
  // * First phase: acquire all locks.
  // * Second phase: hold locks until commit or abort.
  //
  // NOTE: In practice, most DBMSs use strict 2PL, and don't even bother
  // with regular. This is because locking/unlocking is something that
  // the DBMS implements. The application developer isn't worried about
  // locking or unlocking only about txns. Since regular 2PL is
  // susceptable to cascading aborts, almost everyone just uses strict 2PL.
  if (deadlock_detection()) {
    enable_cycle_detection_ = true;
    cycle_detection_thread_ =
      new std::thread(&LockMgr::run_cycle_detection, this);
  }
}

~LockMgr::LockMgr() {
  if (deadlock_detection()) {
    enable_cycle_detection_ = false;
    cycle_detection_thread_->join();
    delete cycle_detection_thread_;
  }
}

bool LockMgr::lock_shared(MRef<Txn> txn, CRef<RID> rid) {
  // Latch the LockMgr. Only one RID can be locked at a time.
  std::unique_lock<std::mutex> guard(latch_);

  // If the txn is invalid, return false.
  if (!can_obtain_lock(txn)) {
    return false;
  }

  // Make the request for a shared lock
  LockRequest request(txn.id(), LockMode::SHARED);

  // To request a shared lock
  // 1) If the request queue is empty, we can grant it straight away
  // 2) If the queue is not empty, then:
  // 2a) If the queue has an exclusive lock, we have to do a
  //     wait-die check
  // 2b) TODO TODO TODO complete this!

  // If we have not seen this RID before, we can add it to the queue
  // and immediately approve the request.
  if (lock_table_.count(rid) == 0) {
    MRef<LockRequestQueue> queue = lock_table_[rid];
    // If we have not seen this RID before, then the lock is
    // automatically granted.
    queue.oldest_id = txn.id();
    queue.upgrading = false;
    queue.requests.push_back(request);

    return grant_read_request(request, queue, txn, rid);
  }

  // SHARED LOCK
  // If the queue has been updated to be in EXCLUSIVE LOCK mode,
  // and the new SHARED LOCK request is from a txn that is older, then
  // we must above the txn. In other words, as per the wait-die
  // protocol, we decide to die here.
  MRef<LockRequestQueue> queue = lock_table_[rid];
  if (queue.upgrading && txn.younger_than(queue.oldest_id)) {
    txn.abort_with_reason(AbortReason::WAIT_OR_DIE);
    txn.~Txn();
    return false;
  }

  // TODO: Use `younger_than` here
  if (queue.oldest_id > txn.id()) {
    queue.oldest_id = txn.id();
  }
  queue.requests.push_back(request);

  // If we've gotten to this point, then we have to wait until the lock
  // table will grant us a new lock. We set up a new request pointer,
  // and update it when we have found a shared lock.
  //
  // The condition variable `cond` will wait until `guard` is unlocked.
  // When it is unlocked, it will call the given lambda. If the lambda
  // returns false, it releases the latch on `guard`, and attempt
  // the lambda again when it is unlocked again.
  // If the lambda returns true, we can exit the `wait` loop.
  LockRequest* curr_request = nullptr;
  queue.cond.wait(guard, [&]() -> bool {
    for (auto &curr : queue.requests) {
      if (curr.txn_id == txn.id()) {
        curr_request = &curr;
        return true;
      } else if (curr.is_exclusive() || !curr.granted) {
        return false;
      }
    }
    return false;
  });

  // At this point, we should have a lock request that matches the
  // current txn. That means we can mark it as granted,
  assert(curr_request != nullptr && curr_request->txn_id == txn.id());
  return grant_read_request(*curr_request, queue, txn, rid);
}


bool LockMgr::lock_exclusive(MRef<Txn> txn, CRef<RID> rid) {
  std::unique_lock<Mutex> guard(latch_);

  if (!can_obtain_lock(txn)) {
    return false;
  }

  LockRequest request {txn.id(), LockMode::EXCLUSIVE};
  if (lock_table_.count(rid) == 0) {
    MutRef<LockRequestQueue> queue = lock_table_[rid];

    queue.oldest_id = txn.id();
    queue.upgrading = true;
    queue.append(request);

    return grant_write_request(request, txn, rid);
  }

  // EXCLUSIVE LOCK wait-die
  // If the requested txn is older than the oldest one in the
  // waiting list, die (per wait-die protocol)
  MRef<LockRequestQueue> queue = lock_table_[rid];
  if (txn.younger_than(queue.oldest_id)) {
    txn.abort_with_reason(AbortReason::WAIT_OR_DIE);
    txn.allow_restart();
    return false;
  }

  // EXCLUSIVE LOCK oldest txn ID
  // Because we are now in "upgrading" mode, and only one exclusive lock
  // can be held at once, `txn` is the only txn allowed. Hence it
  // is the oldest txn we allow in the queue. If anything older shows
  // up, it will either be a SHARED lock, in which case, we already abort
  // as specified by wait-die. Or, it is another EXCLUSIVE lock, in which
  // case we abort, as shown in the `if` stmt above.
  queue.oldest_id = txn.id();
  queue.upgrading = true;
  queue.append(request);

  // Exclusive lock can only obtain the lock when the first one in the
  // waiting queue
  queue.cond.wait(guard, [&]() -> bool {
    return queue.first().txn_id == txn.id();
  });

  assert(queue.first().txn_id == txn.id());
  return grant_write_request(request, txn, rid);
}


bool LockMgr:lock_upgrade(MRef<Txn> txn, CRef<RID> rid) {
  std::unique_lock<Mutex> guard(latch_);

  if (!can_obtain_lock(txn)) {
    return false;
  }

  // During a lock upgrade, we perform the
  // 1) Look for the original shared lock request (one to upgrade)
  // 2) Look for the first exclusive lock request (if it exists),
  //    otherwise default to the end of the queue
  // 3) Check for wait-die criteria
  // 4) Change the shared lock request to an exclusive one
  // 5) Place the upgraded lock request to just before the first exclusive
  //    lock request (if it exists), otherwise place it at the end
  //
  // Everything else is identical to granting an exclusive lock.

  MRef<LockRequestQueue> queue = lock_table_[rid];
  auto original                  = queue.begin();
  auto first_exclusive           = queue.end();

  for (auto it = queue.begin(); it != queue.end(); ++it) {
    // Part (1) - Look for original
    if (it->txn_id == txn.id()) {
      original = it;
    }
    // Part (2) - First exclusive
    if (original != queue.end() && it->is_exclusive()) {
      first_exclusive = it;
      break;
    }
  }
  // At this point we MUST have a pointer to the original request.
  // Not having it is a fatal error.
  assert(original != queue.end());

  // Part (3) - wait-die
  // If the current txn is younger than any request txn (that comes before
  // the first exclusive request), we die, but allow restart in the future.
  for (auto it = queue.begin(); it != first_exclusive; ++it) {
    if (txn.younger_than(it->txn_id)) {
      txn.abort_with_reason(AbortReason::WAIT_OR_DIE);
      txn.allow_restart();
      return false;
    }
  }

  // Part (4) - Copy old request to new one
  // NOTE: original here is an iterator, so we deref to get the
  // current object of the iterator.
  MRef<LockRequest> request = *original;
  request.granted = true;
  request.set_mode(LockMode::EXCLUSIVE);

  // Part (5)
  // Insert new request just before first exclusive lock
  // (or end if not available)
  queue.requests.insert(first_exclusive, request);
  // Delete the original
  queue.requests.erase(original);

  // The rest is (almost) the same as exclusive lock
  // Exclusive lock request can only obtain the RID lock when it is
  // the first one in the waiting queue
  queue.cond.wait(guard, [&]() -> bool {
    return queue.first().txn_id == txn.id();
  });

  assert(queue.first().txn_id == txn.id());
  return grant_upgrade_request(request, txn, rid);
}

bool LockMgr::unlock(MRef<Txn> txn, CRef<RID> rid) {
  std::unique_lock<std::mutex> guard(latch_);
  if (!can_unlock(txn)) {
    return false;
  }
  // Verify we have have a lock on the RID
  assert(lock_table_.count(rid) > 0);

  // ind the matching txn
  MutRef<LockRequestQueue> queue = lock_table_[rid];
  for (auto it = queue.begin(); it != queue.end(); ++it) {
    if (it->txn_id == txn.id()) {
      return remove_request(it, queue, txn, rid);
    }
  }

  // If we got to this point, then we somehow could not find the lock
  // request that we wanted to delete!
  // TODO: Figure out what to do here. Maybe just raise an exception
  // that it should not be reachable?
  return false;
}


bool LockMgr::grant_read_request(MRef<LockRequest> request,
                                 MRef<LockRequestQueue> queue,
                                 MRef<Txn> txn,
                                 CRef<RID> rid)
{
  request.granted = true;
  // NOTE: We call notify all so other SHARED lock requests
  // can wake up and be granted.
  queue.cond.notify_all();
  txn.shared_lock_set().insert(rid);
  return true;
}


bool LockMgr::grant_write_request(MRef<LockRequest> request,
                                  MRef<Txn> txn,
                                  CRef<RID> rid)
{
  request.granted = true;
  // NOTE: We DO NOT call notify all because EXCLUSIVE lock requests
  // can only be granted after unlocks
  txn.exclusive_lock_set().insert(rid);
  return true;
}


bool LockMgr::grant_upgrade_request(MRef<LockRequest> request,
                                    MRef<Txn> txn,
                                    CRef<RID> rid)
{
  request.granted = true;
  txn.shared_lock_set().erase(rid);
  txn.exclusive_lock_set().insert(rid);
  return true;
}


void LockMgr::run_cycle_detection() {
  while (enable_cycle_detection_) {
    std::this_thread::sleep_for(cycle_detection_interval_);
    {
      std::unique_lock<std::mutex> l(latch_);
      // TODO(student): remove the continue and add your cycle
      // detection and abort code here
      continue;
    }
  }
}

bool LockMgr::remove_request(MutList<LockRequest>::iterator it,
                             MRef<LockRequestQueue> queue,
                             MRef<Txn> txn,
                             Ref<RID> rid) const
{
  if (it->is_exclusive()) {
    txn.exclusive_lock_set().erase(rid);
    queue.upgrading = false;
  } else {
    txn.shared_lock_set().erase(rid);
  }

  if (it->is_exclusive() || it == queue.begin()) {
    queue.cond.notify_all();
  }
  queue.requests.erase(it);
  return true;
}

// A txn can obtain a lock if it is not finished and it is not
// shrinking. Basically it can only attempt if it is growing. But we
// should keep track of finished vs shrinking as separate abort reasons.
bool LockMgr::can_obtain_lock(MRef<Txn> txn) {
  if (txn.is_finished()) {
    txn.abort_with_reason(AbortReason::LOCK_AFTER_FINISHED);
    return false;
  }

  if (txn.is_shrinking()) {
    txn.abort_with_reason(AbortReason::STRICT_2PL_VIOLATION);
    return false;
  }
  return true;
}

bool LockMgr::can_unlock(MRef<Txn> txn) {
  // if strict 2pl, when unlock txn must be in committed or abort state
  if (strict_2pl()) {
    // A txn is finished if it is committed or aborted
    // In strict 2PL, we can only unlock we the txn is finished.
    if (!txn.is_finished()) {
      txn.abort_with_reason(AbortReason::STRICT_2PL_VIOLATION);
      return false;
    }
  } else {
    // In regular 2PL, we allow a txn to unlock at any time, but that
    // does mean they are now in a shrinking phase.
    if (txn.is_growing()) {
      txn.begin_shrinking();
    }
  }
  return true;
}
