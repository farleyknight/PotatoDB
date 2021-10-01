#pragma once

#include "execs/exec_ctx.hpp"
#include "tuple/tuple.hpp"

class BaseExec {
public:
  explicit BaseExec(ExecCtx& exec_ctx)
    : exec_ctx_(exec_ctx) {}
  virtual ~BaseExec() = default;

  virtual void init() = 0;

  virtual bool
  has_next() = 0;

  virtual Tuple
  next_tuple() = 0;

  // NOTE: Value maps might be slightly less efficient than using Tuple
  // but they are better for debugging, and also easier to do defaults.
  //
  // In the future, we may find a better way to do this...
  virtual map<column_oid_t, Value>
  next_value_map() = 0;

  virtual const string
  message_on_completion(int32_t result_count) const = 0;

  const ExecCtx&
  exec_ctx() {
    return exec_ctx_;
  }

  Txn&
  txn() {
    return exec_ctx_.txn();
  }

  const SchemaMgr&
  schema_mgr() const {
    return exec_ctx_.schema_mgr();
  }

protected:
  ExecCtx& exec_ctx_;
};
