#pragma once

#include "execs/exec_ctx.hpp"
#include "tuple/tuple.hpp"

class BaseExec {
public:
  explicit BaseExec(ExecCtx& exec_ctx)
    : exec_ctx_(exec_ctx) {}
  virtual ~BaseExec() = default;

  virtual void init() = 0;

  virtual bool has_next() = 0;

  virtual Tuple next() = 0;

  const ExecCtx& exec_ctx() {
    return exec_ctx_;
  }

  Txn& txn() {
    return exec_ctx_.txn();
  }

  const SchemaMgr& schema_mgr() const {
    return exec_ctx_.schema_mgr();
  }

  virtual const string
  message_on_completion(int32_t result_count) const = 0;

protected:
  ExecCtx& exec_ctx_;
};
