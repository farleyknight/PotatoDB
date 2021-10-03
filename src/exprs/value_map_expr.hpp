#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/value_map_expr.hpp"
#include "exprs/list_expr.hpp"

class ValueMapExpr : public BaseExpr
{
public:
  ValueMapExpr()
    : BaseExpr (ExprType::VALUE_MAP)
  {}

  ValueMap
  to_value_map() const {
    ValueMap value_map(size());
    for (int32_t i = 0; i < size(); ++i) {
      value_map.emplace(column_oids_[i],
                        move(values_[i]));
    }
    return value_map;
  }

  int32_t
  size() const {
    return column_oids_.size();
  }

private:
  vector<column_oid_t> column_oids_;
  vector<Value> values_;
};
