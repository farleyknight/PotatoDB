#pragma once

#include <thread>

#include "common/config.hpp"
#include "tuple/rid.hpp"

#include "txns/lock_request.hpp"
#include "txns/lock_request_queue.hpp"
#include "txns/txn.hpp"

enum class TwoPLMode {
  REGULAR,
  STRICT
};

enum class DeadlockMode {
  PREVENTION,
  DETECTION
};

class LockMgr {
public:
  /**********************************************
  * Constructors & destructor
  **********************************************/

  explicit LockMgr(TwoPLMode two_pl_mode,
                   DeadlockMode deadlock_mode);
  ~LockMgr();

  // No copy
  LockMgr(Ref<LockMgr>) = delete;
  // No copy assign
  MutRef<LockMgr> operator=(Ref<LockMgr>) = delete;

  /**********************************************
  * Instance methods
  **********************************************/

  bool lock_shared(MutRef<Txn> txn, Ref<RID> rid);
  bool lock_exclusive(MRef<Txn> txn, CRef<RID> rid);
  bool lock_upgrade(MutRef<Txn> txn, Ref<RID> rid);
  bool unlock(MutRef<Txn> txn, Ref<RID> rid);
  void add_edge(txn_id_t t1, txn_id_t t2) const {
    // TODO
  }
  void remove_edge(txn_id_t t1, txn_id_t t2) const {
    // TODO
  }
  bool has_cycle(txn_id_t *txn_id) {
    // TODO
    return false;
  }

  Vec<std::pair<txn_id_t, txn_id_t>> edge_list() {
    return Vec<std::pair<txn_id_t, txn_id_t>>();
  }

  void run_cycle_detection();

private:
  // TODO: I think I might get rid of regular 2PL.
  // Maybe just stick with strict 2PL for now
  bool strict_2pl() const {
    return two_pl_mode_ == TwoPLMode::STRICT;
  }

  bool deadlock_detection() const {
    return deadlock_mode_ == DeadlockMode::DETECTION;
  }

  bool grant_read_request(MRef<LockRequest> request,
                          MRef<LockRequestQueue> queue,
                          MRef<Txn> txn,
                          CRef<RID> rid);

  bool grant_write_request(MRef<LockRequest> request,
                           MRef<Txn> txn,
                           CRef<RID> rid);

  bool grant_upgrade_request(MRef<LockRequest> request,
                             MRef<Txn> txn,
                             CRef<RID> rid);

  bool remove_request(MutList<LockRequest>::iterator it,
                      MRef<LockRequestQueue> queue,
                      MRef<Txn> txn,
                      Ref<RID> rid) const;

  bool can_obtain_lock(MRef<Txn> txn);
  bool can_unlock(MRef<Txn> txn);

  TwoPLMode two_pl_mode_;
  DeadlockMode deadlock_mode_;
  Mutex latch_;
  Atomic<bool> enable_cycle_detection_;
  std::thread *cycle_detection_thread_;
  std::chrono::milliseconds cycle_detection_interval_ =
    std::chrono::milliseconds(50);

  MutMap<RID, LockRequestQueue> lock_table_;
  MutMap<txn_id_t, Vec<txn_id_t>> waits_for_;
};
