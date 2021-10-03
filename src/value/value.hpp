#pragma once

#include <string>
#include <type_traits>

#include <variant>

#include "buffer/buffer.hpp"

#include "types/type_id.hpp"

class Type;

using value_variant_t = std::variant<
  // NOTE: std::monostate is how std::variant can represent
  // un-initialized state. I use it for representing `NULL`
  // in the in-memory parts of the database.
  // TODO: There is still work to be done on correctly representing
  // `NULL` at the filesystem / byte level. We probably want to keep
  // tuple headers that have bit-maps for which fields are `NULL`.
  // TODO: Link the Pavlo video where he covers this.
  std::monostate,

  // BOOLEAN
  bool,

  // INTs of various sizes
  int8_t,
  int16_t,
  int32_t,
  int64_t,

  // TODO: Write end-to-end tests that INSERT random doubles and timestamps
  double,
  timestamp_t,

  // TODO: Write end-to-end tests that INSERT random strings
  char *,
  string
  >;

class Value {
public:
  Value(TypeId type_id,
        value_variant_t data)
    : type_id_ (type_id),
      data_    (data)
  {}

  TypeId type_id() const {
    return type_id_;
  }

  template<typename T>
  T
  as() const {
    return std::get<T>(data_);
  }

  // TODO: Move these methods into `Buffer`
  void serialize_to(buffer_offset_t offset, Buffer& buff) const;
  static Value deserialize_from(buffer_offset_t offset,
                                const Buffer& buff,
                                TypeId type_id);

  Value
  cast_as(TypeId type_id) const;

  int32_t
  size() const;

  int32_t
  length() const {
    return size();
  }

  bool is_varchar() const {
    return type_id_ == TypeId::VARCHAR;
  }

  bool
  is_null() const;

  const string
  to_string() const;

  // NOTE: A `Value` can either be NULL (as per usual SQL) or it can be
  // INVALID.
  //
  // INVALID is kind of like JavaScript's `undefined` or like `NaN` in a
  // lot of numerical computing situations.
  //
  // Receiving an INVALID should be considered an error in the user-land.
  // Unlike JavaScript's `undefined` or `NaN`, it is only used when trying
  // to get the default of a NOT NULL column which has no default.
  //
  // The act of trying to do anything with an INVALID `Value`, even rendering
  // to a string for user display purposes, should throw an error. It is,
  // however, okay to render to a string for developer display (debugging) purposes.

  static Value
  make_null(TypeId type_id) {
    return Value(type_id, std::monostate());
  }

  static Value
  make_invalid() {
    return Value(TypeId::INVALID, std::monostate());
  }

  // TODO: Can we refactor this template line?
  template <class T,
            std::enable_if_t<std::is_same<T, bool>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::BOOLEAN, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int8_t>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::TINYINT, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int16_t>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::SMALLINT, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int32_t>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::INTEGER, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int64_t>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::BIGINT, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, double>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::DECIMAL, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, timestamp_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::TIMESTAMP, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, std::string>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::VARCHAR, data);
  }

  template <class T,
            std::enable_if_t<std::is_same<T, const char*>::value, bool> = false>
  static Value
  make(T data) {
    return Value(TypeId::VARCHAR, std::string(data));
  }

  bool
  eq(const Value& other) const;
  bool
  ne(const Value& other) const;
  bool
  lt(const Value& other) const;
  bool
  gt(const Value& other) const;

  bool
  lte(const Value& other) const;
  bool
  gte(const Value& other) const;

  Value
  add(const Value& other) const;
  Value
  subtract(const Value& other) const;
  Value
  multiply(const Value& other) const;
  Value
  divide(const Value& other) const;

  Value
  min(const Value& other) const;
  Value
  max(const Value& other) const;

private:
  TypeId type_id_;
  value_variant_t data_;
};
