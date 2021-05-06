#pragma once

#include "execs/exec_ctx.hpp"
#include "catalog/schema_ref.hpp"
#include "tuple/tuple.hpp"

/**
 * BaseExec implements the Volcano tuple-at-a-time iterator model.
 */
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

  const Catalog& catalog() const {
    return exec_ctx_.catalog();
  }

protected:
  ExecCtx& exec_ctx_;
};
