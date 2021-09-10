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

  // TODO: Rename type_length to variable_length, which is the same
  // variable on the TableColumn class
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

  bool is_nullable() const {
    return nullable_;
  }

  void is_nullable(bool state) {
    nullable_ = state;
  }

  bool is_primary_key() const {
    return primary_key_;
  }

  void is_primary_key(bool primary_key) {
    primary_key_ = primary_key;
  }

  bool auto_increment() const {
    return auto_increment_;
  }

  void is_auto_increment(bool value) {
    auto_increment_ = value;
  }

protected:
  column_name_t name_;
  TypeId type_id_;
  length_t type_length_ = 0;

  bool nullable_       = true;
  bool primary_key_    = false;
  bool auto_increment_ = false;
};
