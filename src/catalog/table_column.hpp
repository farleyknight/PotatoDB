#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <optional>

#include "common/config.hpp"
#include "types/type.hpp"

#include "exprs/base_expr.hpp"

static constexpr int32_t INVALID_LENGTH = -1;

// TODO: Add `NOT NULL` stuff to this class
// TODO: Add `PRIMARY KEY` stuff to this class
// TODO: Add `AUTOINCREMENT` stuff to this class
class TableColumn {
public:
  TableColumn()
    : fixed_length_(INVALID_LENGTH) {}

  TableColumn(const string name,
              table_oid_t table_oid,
              column_oid_t column_oid,
              TypeId type_id)
    : name_         (name),
      type_id_      (type_id),
      table_oid_    (table_oid),
      column_oid_   (column_oid),
      inlined_      (true),
      fixed_length_ (Type::size_of(type_id))
  {
    // "Wrong constructor for VARCHAR type.";
    assert(type_id != TypeId::VARCHAR);
  }

  explicit TableColumn(const string name,
                       table_oid_t table_oid,
                       column_oid_t column_oid,
                       TypeId type_id,
                       string_size_t length)
    : name_            (name),
      type_id_         (type_id),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      inlined_         (false),
      fixed_length_    (Type::size_of(type_id)),
      variable_length_ (length)
  {
    // "Wrong constructor for VARCHAR type.";
    assert(type_id == TypeId::VARCHAR);
  }

  // Allow copy
  TableColumn(const TableColumn&) = default;
  // Allow copy assign
  TableColumn& operator=(const TableColumn&) = default;
  // Default destructor
  ~TableColumn() = default;

  bool is_inlined()               const { return inlined_; }
  bool primary_key()              const { return primary_key_; }
  bool is_nullable()              const { return nullable_; }
  TypeId type_id()                const { return type_id_; }
  table_oid_t table_oid()         const { return table_oid_; }
  column_oid_t oid()              const { return column_oid_; }
  int32_t fixed_length()          const { return fixed_length_; }
  string_size_t variable_length() const { return variable_length_; }
  const column_name_t& name()     const { return name_; }

  void set_primary_key(bool is_primary_key) {
    primary_key_ = is_primary_key;
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
      name_            == other.name_ &&
      type_id_         == other.type_id_ &&
      table_oid_       == other.table_oid_ &&
      column_oid_      == other.column_oid_ &&
      inlined_         == other.inlined_ &&
      nullable_        == other.nullable_ &&
      primary_key_     == other.primary_key_ &&
      autoincrement_   == other.autoincrement_ &&
      fixed_length_    == other.fixed_length_ &&
      variable_length_ == other.variable_length_;
  }

  bool operator!=(const TableColumn& other) const {
    return
      name_            != other.name_ ||
      type_id_         != other.type_id_ ||
      table_oid_       != other.table_oid_ ||
      column_oid_      != other.column_oid_ ||
      inlined_         != other.inlined_ ||
      nullable_        != other.nullable_ ||
      primary_key_     != other.primary_key_ ||
      autoincrement_   != other.autoincrement_ ||
      fixed_length_    != other.fixed_length_ ||
      variable_length_ != other.variable_length_;
  }

private:
  // Name of the column
  column_name_t name_;
  // value type of column
  TypeId type_id_ = TypeId::INVALID;

  // IDs for table and column
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
  uint32_t fixed_length_ = 0;
  uint32_t variable_length_ = 0;
};
