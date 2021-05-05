#pragma once

#include "exprs/base_expr.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  ColumnDefExpr(string name, string type_name)
    : BaseExpr   (ExprType::COLUMN_DEF),
      name_      (name),
      type_name_ (type_name)
  {}

  virtual string to_string() const override {
    return name_ + " " + type_name_;
  }

  const string& name() const {
    return name_;
  }

  const string& type_name() const {
    return type_name_;
  }

  uint32_t type_length() const {
    return type_length_;
  }

  bool not_null() const {
    return not_null_;
  }

  bool is_primary_key() const {
    return primary_key_;
  }

protected:
  string name_, type_name_;
  uint32_t type_length_;
  bool not_null_, primary_key_;
};
