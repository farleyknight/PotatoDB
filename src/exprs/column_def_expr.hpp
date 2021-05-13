#pragma once

#include "exprs/base_expr.hpp"
#include "types/type.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  ColumnDefExpr(column_name_t name, TypeId type_id)
    : BaseExpr   (ExprType::COLUMN_DEF),
      name_      (name),
      type_id_   (type_id)
  {}

  ColumnDefExpr(column_name_t name, TypeId type_id, length_t type_length)
    : BaseExpr     (ExprType::COLUMN_DEF),
      name_        (name),
      type_id_     (type_id),
      type_length_ (type_length)
  {}

 virtual const string to_string() const override {
   return name_ + " " + Type::as_string(type_id_);
  }

  const column_name_t& name() const {
    return name_;
  }

  TypeId type_id() const {
    return type_id_;
  }

  length_t type_length() const {
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

  bool auto_increment() {
    return auto_increment_;
  }

  void is_auto_increment(bool value) {
    auto_increment_ = value;
  }

protected:
  column_name_t name_;
  TypeId type_id_;
  length_t type_length_ = 0;
  bool not_null_ = false,
    primary_key_ = false,
    auto_increment_ = false;
};
