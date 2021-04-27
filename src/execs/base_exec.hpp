#pragma once

#include "execs/exec_ctx.hpp"
#include "catalog/schema_ref.hpp"
#include "tuple/tuple.hpp"

/**
 * BaseExec implements the Volcano tuple-at-a-time iterator model.
 */
class BaseExec {
public:
  explicit BaseExec(MRef<ExecCtx> exec_ctx)
    : exec_ctx_(exec_ctx) {}
  virtual ~BaseExec() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  virtual SchemaRef schema_ref() {
    throw NotImplementedException("schema_ref() not implemented");
  }

  virtual void init() {
    throw NotImplementedException("init() not implemented");
  };

  virtual bool has_next() {
    throw NotImplementedException("has_next() not implemented");
  }

  virtual Tuple next() {
    throw NotImplementedException("next() not implemented");
  }

  Ref<ExecCtx> exec_ctx() {
    return exec_ctx_;
  }

  MRef<Txn> txn() {
    return exec_ctx_.txn();
  }

  Ref<Catalog> catalog() const {
    return exec_ctx_.catalog();
  }

  Ref<QuerySchema> find_schema(SchemaRef schema_ref) const {
    return catalog().find_query_schema(schema_ref);
  }

protected:
  MRef<ExecCtx> exec_ctx_;
};
