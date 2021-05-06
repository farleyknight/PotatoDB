#pragma once

#include "exprs/base_expr.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  ColumnDefExpr(string name, string type_name)
    : BaseExpr   (ExprType::COLUMN_DEF),
      name_      (name),
      type_name_ (type_name)
  {}

  ColumnDefExpr(string name, string type_name, uint32_t type_length)
    : BaseExpr     (ExprType::COLUMN_DEF),
      name_        (name),
      type_name_   (type_name),
      type_length_ (type_length)
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

  bool is_not_null() const {
    return not_null_;
  }

  void is_not_null(bool state) {
    not_null_ = state;
  }

  bool is_primary_key() const {
    return primary_key_;
  }

  void is_primary_key(bool state) {
    primary_key_ = state;
  }

protected:
  string name_, type_name_;
  uint32_t type_length_ = 0;
  bool not_null_ = false, primary_key_ = false;
};
