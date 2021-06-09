#pragma once

#include "buffer/buff_mgr.hpp"
#include "txns/txn_mgr.hpp"
#include "recovery/log_mgr.hpp"

class CheckpointMgr {
public:
  CheckpointMgr(const TxnMgr& txn_mgr,
                const LogMgr& log_mgr,
                const BuffMgr& buff_mgr)
    : txn_mgr_  (txn_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr) {}

  ~CheckpointMgr() = default;

  void begin();
  void end();

private:
  UNUSED const TxnMgr& txn_mgr_;
  UNUSED const LogMgr& log_mgr_;
  UNUSED const BuffMgr& buff_mgr_;
};
