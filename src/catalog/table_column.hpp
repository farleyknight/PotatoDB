#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <optional>

#include "common/config.hpp"
#include "types/type.hpp"

#include "exprs/base_expr.hpp"
#include "exprs/column_def_expr.hpp"

static constexpr int32_t INVALID_FIXED_LENGTH    = -1;
static constexpr int32_t INVALID_VARIABLE_LENGTH = -1;

class TableColumn {
public:
  explicit TableColumn(table_oid_t table_oid,
                       column_oid_t column_oid,
                       const column_name_t column_name,
                       TypeId type_id,
                       bool nullable,
                       bool primary_key,
                       bool autoincrement)
    : name_            (column_name),
      type_id_         (type_id),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      inlined_         (true),
      nullable_        (nullable),
      primary_key_     (primary_key),
      autoincrement_   (autoincrement),
      fixed_length_    (Type::size_of(type_id_)),
      variable_length_ (INVALID_VARIABLE_LENGTH)
  {
    assert(type_id_ != TypeId::VARCHAR);
  }

  explicit TableColumn(table_oid_t table_oid,
                       column_oid_t column_oid,
                       const column_name_t column_name,
                       length_t length,
                       TypeId type_id,
                       bool nullable,
                       bool primary_key,
                       bool autoincrement)
    : name_            (column_name),
      type_id_         (type_id),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      inlined_         (false),
      nullable_        (nullable),
      primary_key_     (primary_key),
      autoincrement_   (autoincrement),
      fixed_length_    (INVALID_FIXED_LENGTH),
      variable_length_ (length)
  {
    assert(type_id_ == TypeId::VARCHAR);
  }

  explicit TableColumn(table_oid_t table_oid,
                       column_oid_t column_oid,
                       length_t length,
                       const ColumnDefExpr& expr)
    : name_            (expr.name()),
      type_id_         (expr.type_id()),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      inlined_         (false),
      nullable_        (expr.is_nullable()),
      primary_key_     (expr.is_primary_key()),
      autoincrement_   (expr.is_autoincrement()),
      fixed_length_    (INVALID_FIXED_LENGTH),
      variable_length_ (length)
  {
    assert(type_id_ == TypeId::VARCHAR);
  }

  explicit TableColumn(table_oid_t table_oid,
                       column_oid_t column_oid,
                       const ColumnDefExpr& expr)
    : name_            (expr.name()),
      type_id_         (expr.type_id()),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      inlined_         (true),
      nullable_        (expr.is_nullable()),
      primary_key_     (expr.is_primary_key()),
      autoincrement_   (expr.is_autoincrement()),
      fixed_length_    (Type::size_of(type_id_)),
      variable_length_ (INVALID_VARIABLE_LENGTH)
  {
    assert(type_id_ != TypeId::VARCHAR);
  }

  // Allow copy
  TableColumn(const TableColumn&) = default;
  // Allow copy assign
  TableColumn& operator=(const TableColumn&) = default;
  // Default destructor
  ~TableColumn() = default;

  const column_name_t& name()     const { return name_; }

  TypeId type_id()                const { return type_id_; }
  table_oid_t table_oid()         const { return table_oid_; }
  column_oid_t column_oid()       const { return column_oid_; }
  length_t fixed_length()         const { return fixed_length_; }
  string_size_t variable_length() const { return variable_length_; }

  bool is_inlined()               const { return inlined_; }
  bool is_primary_key()           const { return primary_key_; }
  bool is_autoincrement()         const { return autoincrement_; }
  bool is_nullable()              const { return nullable_; }

  void set_nullable(bool nullable) {
    nullable_ = nullable;
  }

  void set_primary_key(bool primary_key) {
    primary_key_ = primary_key;
  }

  void set_autoincrement(bool autoincrement) {
    autoincrement_ = autoincrement;
  }

  bool is_splat() const {
    return false;
  }

  bool is_count_splat() const {
    return false;
  }

  const string to_string() const {
    std::ostringstream os;

    os << "TableColumn[" << std::endl <<
       "  Name: " << name_ << std::endl <<
       "  TypeId: " << Type::as_string(type_id_) << std::endl <<
       "  Nullable: " << (nullable_ ? "true" : "false");

    if (inlined_) {
      os << "  FixedLength:" << fixed_length_;
    } else {
      os << "  VarLength:" << variable_length_;
    }
    os << "]";
    return os.str();
  }

  bool operator==(const TableColumn& other) const {
    return
      name_            == other.name_            &&
      type_id_         == other.type_id_         &&
      table_oid_       == other.table_oid_       &&
      column_oid_      == other.column_oid_      &&
      inlined_         == other.inlined_         &&
      nullable_        == other.nullable_        &&
      primary_key_     == other.primary_key_     &&
      autoincrement_   == other.autoincrement_   &&
      fixed_length_    == other.fixed_length_    &&
      variable_length_ == other.variable_length_;
  }

  bool operator!=(const TableColumn& other) const {
    return
      name_            != other.name_            ||
      type_id_         != other.type_id_         ||
      table_oid_       != other.table_oid_       ||
      column_oid_      != other.column_oid_      ||
      inlined_         != other.inlined_         ||
      nullable_        != other.nullable_        ||
      primary_key_     != other.primary_key_     ||
      autoincrement_   != other.autoincrement_   ||
      fixed_length_    != other.fixed_length_    ||
      variable_length_ != other.variable_length_;
  }

private:
  column_name_t name_;
  TypeId type_id_ = TypeId::INVALID;

  table_oid_t table_oid_;
  column_oid_t column_oid_;

  // is the column inlined ?
  bool inlined_ = true;
  // is the column nullable?
  bool nullable_ = false; // TODO: Default should be true!
  // is the column a primary key?
  bool primary_key_ = false;
  // is the column an autoincrement?
  bool autoincrement_ = false;
  int32_t fixed_length_    = -1;
  int32_t variable_length_ = -1;
};
