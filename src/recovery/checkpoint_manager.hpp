#pragma once

#include "buffer/buff_mgr.hpp"
#include "txns/txn_mgr.hpp"
#include "recovery/log_mgr.hpp"

class CheckPMgr {
public:
  CheckPMgr(CRef<TxnMgr> txn_mgr,
            CRef<LogMgr> log_mgr,
            CRef<BuffMgr> buff_mgr)
    : txn_mgr_  (txn_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr) {}

  ~CheckPMgr() = default;

  void begin();
  void end();

private:
  UNUSED CRef<TxnMgr> txn_mgr_;
  UNUSED CRef<LogMgr> log_mgr_;
  UNUSED CRef<BuffMgr> buff_mgr_;
};
