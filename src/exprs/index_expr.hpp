#pragma once

#include "exprs/base_expr.hpp"

class IndexExpr : public BaseExpr {
public:

  IndexExpr()
    : BaseExpr (ExprType::INDEX)
  {}

  IndexExpr(index_name_t name)
    : BaseExpr (ExprType::INDEX),
      name_    (name)
  {}

  IndexExpr(index_name_t name, index_oid_t index_oid)
    : BaseExpr   (ExprType::INDEX),
      name_      (name),
      index_oid_ (index_oid)
  {}

  index_name_t name() const {
    return name_;
  }

  index_oid_t index_oid() const {
    return index_oid_;
  }

  virtual const string to_string() const override {
    return name_;
  }

private:
  index_name_t name_;
  index_oid_t index_oid_ = INVALID_INDEX_OID;
};
