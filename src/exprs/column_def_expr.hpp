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
  ColumnDefExpr(column_name_t name,
                TypeId type_id,
                length_t type_length)
    : BaseExpr     (ExprType::COLUMN_DEF),
      name_        (name),
      type_id_     (type_id),
      type_length_ (type_length)
  {}

  virtual const string
  to_string() const override {
    return name_ + " " + Type::as_string(type_id_);
  }

  const column_name_t&
  name() const {
    return name_;
  }

  TypeId
  type_id() const {
    return type_id_;
  }

  length_t
  type_length() const {
    return type_length_;
  }

  bool
  is_nullable() const {
    return nullable_;
  }

  bool
  is_autoincrement() const {
    return autoincrement_;
  }

  bool
  is_primary_key() const {
    return primary_key_;
  }

  void
  set_nullable(bool state) {
    nullable_ = state;
  }

  void
  set_primary_key(bool primary_key) {
    primary_key_ = primary_key;
  }

  void
  set_autoincrement(bool value) {
    autoincrement_ = value;
  }

protected:
  column_name_t name_;
  TypeId type_id_       = TypeId::INVALID;
  length_t type_length_ = 0;

  bool nullable_      = true;
  bool primary_key_   = false;
  bool autoincrement_ = false;
};
