#pragma once

#include "plans/plan_type.hpp"
#include "execs/exec_ctx.hpp"
#include "tuple/tuple.hpp"

class BaseOper {
public:
  explicit BaseOper(OperType type,
                    ExecCtx& exec_ctx)
    : type_     (type),
      exec_ctx_ (exec_ctx)
  {}

  virtual ~BaseOper() = default;

  virtual void init() = 0;

  virtual bool has_next() = 0;

  virtual Tuple next() = 0;

  const ExecCtx& exec_ctx() {
    return exec_ctx_;
  }

  Txn& txn() {
    return exec_ctx_.txn();
  }

  OperType type() const { return type_; }

  const Catalog& catalog() const {
    return exec_ctx_.catalog();
  }

  virtual const string
  message_on_completion(size_t result_count) const = 0;

  virtual bool is_query() const = 0;

protected:
  OperType type_ = OperType::INVALID;
  ExecCtx& exec_ctx_;
};
