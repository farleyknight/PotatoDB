#pragma once

#include "buffer/buff_mgr.hpp"
#include "txns/txn_mgr.hpp"
#include "recovery/log_mgr.hpp"

/**
 * CheckpointManager creates consistent checkpoints by blocking all other txns temporarily.
 */
class CheckPMgr {
public:
  CheckPMgr(Ref<TxnMgr> txn_mgr,
            Ref<LogMgr> log_mgr,
            Ref<BuffMgr> buff_mgr)
    : txn_mgr_  (txn_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr) {}

  ~CheckPMgr() = default;

  static Ptr<CheckPMgr> make(Ref<TxnMgr> txn_mgr,
                             Ref<LogMgr> log_mgr,
                             Ref<BuffMgr> buff_mgr)
  {
    return make_unique<CheckPMgr>(txn_mgr,
                                  log_mgr,
                                  buff_mgr);
  }

  void begin();
  void end();

private:
  Ref<TxnMgr> txn_mgr_;
  Ref<LogMgr> log_mgr_;
  Ref<BuffMgr> buff_mgr_;
};
