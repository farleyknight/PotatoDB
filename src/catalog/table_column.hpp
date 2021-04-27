#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <optional>

#include "common/config.hpp"
#include "types/type.hpp"

#include "exprs/base_expr.hpp"

static constexpr int32_t INVALID_LENGTH = -1;

// TODO: Rename Column to TableColumn elsewhere in the system
// TODO: Add `NOT NULL` stuff to this class
// TODO: Add `PRIMARY KEY` stuff to this class
// TODO: Add `AUTOINCREMENT` stuff to this class
class TableColumn {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  TableColumn() : fixed_length_(INVALID_LENGTH) {}

  TableColumn(String name,
              table_oid_t table_oid,
              column_oid_t column_oid,
              TypeId type_id)
    : name_         (name),
      table_oid_    (table_oid),
      column_oid_   (column_oid),
      type_id_      (type_id),
      inlined_      (true),
      fixed_length_ (Type::size(type_id))
  {
    assert(type_id != TypeId::VARCHAR); // "Wrong constructor for VARCHAR type.";
  }

  explicit TableColumn(String name,
                       table_oid_t table_oid,
                       column_oid_t column_oid,
                       TypeId type_id,
                       uint32_t length)
    : name_            (name),
      table_oid_       (table_oid),
      column_oid_      (column_oid),
      type_id_         (type_id),
      inlined_         (false),
      fixed_length_    (Type::size(type_id)),
      variable_length_ (length)
  {
    assert(type_id == TypeId::VARCHAR); // "Wrong constructor for VARCHAR type.";
  }

  // Allow copy
  TableColumn(Ref<TableColumn>) = default;
  // Allow copy assign
  MRef<TableColumn> operator=(Ref<TableColumn>) = default;
  // Default destructor
  ~TableColumn() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  const bool is_inlined() const {
    return inlined_;
  }

  const bool primary_key() const {
    return primary_key_;
  }

  const bool is_nullable() const {
    return nullable_;
  }

  const TypeId type_id() const {
    return type_id_;
  }

  const table_oid_t table_oid() const {
    return table_oid_;
  }

  const column_oid_t oid() const {
    return column_oid_;
  }

  const int32_t fixed_length() const {
    return fixed_length_;
  }

  const int32_t variable_length() const {
    return variable_length_;
  }

  Ref<String> name() const {
    return name_;
  }

  /**********************************************
   * Debug methods
   **********************************************/

  String to_string() const {
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

private:
  // Name of the column
  MutString name_;
  // value type of column
  TypeId type_id_ = TypeId::INVALID;
  // IDs for table and column
  table_oid_t table_oid_;
  column_oid_t column_oid_;
  // is the column inlined ?
  bool inlined_ = true;
  // is the column nullable?
  bool nullable_ = false;
  // is the column a primary key?
  bool primary_key_ = false;
  uint32_t fixed_length_ = 0;
  uint32_t variable_length_ = 0;
};
