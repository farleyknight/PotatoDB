#pragma once

#include "exprs/base_expr.hpp"
#include "types/type.hpp"

class ColumnDefExpr : public BaseExpr {
public:
  explicit
  ColumnDefExpr(column_name_t name,
                TypeId type_id)
    : BaseExpr       (ExprType::COLUMN_DEF),
      name_          (name),
      type_id_       (type_id),
      default_value_ (Value::make_null(type_id))
  {}

  // TODO: Rename type_length to variable_length, which is the same
  // variable on the TableColumn class
  explicit
  ColumnDefExpr(column_name_t name,
                TypeId type_id,
                int32_t length)
    : BaseExpr         (ExprType::COLUMN_DEF),
      name_            (name),
      type_id_         (type_id),
      variable_length_ (length),
      default_value_   (Value::make_null(type_id))
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

  bool
  is_inlined() const {
    return type_id_ == TypeId::VARCHAR;
  }

  int32_t
  variable_length() const {
    return variable_length_;
  }

  int32_t
  fixed_length() const {
    return Type::size_of(type_id_);
  }

  bool
  has_default() const {
    if (nullable_) {
      return true;
    }
    return has_default_;
  }

  Value
  default_value() const {
    if (!nullable_ && default_value_.is_null()) {
      throw Exception("Tried get default when there is none! Need to debug here.");
    }
    return default_value_;
  }

protected:
  column_name_t name_;
  TypeId type_id_      = TypeId::INVALID;
  int32_t variable_length_ = INVALID_VARIABLE_LENGTH;

  bool nullable_      = true;
  bool primary_key_   = false;
  bool autoincrement_ = false;
  bool has_default_   = false;

  Value default_value_;
};
