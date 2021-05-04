#pragma once

#include <string>
#include <type_traits>

#include "buffer/buffer.hpp"

#include "types/type_id.hpp"

#include "value/value_base.hpp"

class Type;

class Value : public ValueBase<> {
public:
  using DataStoreT = typename ValueBase<>::DataStoreT;
  using StoreT     = typename ValueBase<>::StoreClass;

  void serialize_to(size_t offset, Buffer& buff) const;
  static Value deserialize_from(size_t offset,
                                const Buffer& buff,
                                TypeId type_id);

  const Ptr<Type>& value_type() const;

  template<typename target_t>
  target_t as() const {
    return StoreT::template cast_as<target_t>(data_);
  }

  size_t size() const;
  size_t length() const {
    return size();
  }

  bool is_null() const;
  const string to_string() const;

  // TODO: Can we refactor this template line?
  template <class T,
            std::enable_if_t<std::is_same<T, bool>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::BOOLEAN, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int8_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::TINYINT, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int16_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::SMALLINT, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int32_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::INTEGER, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, int64_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::BIGINT, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, double>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::DECIMAL, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, uint64_t>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::TIMESTAMP, DataStoreT(data));
  }

  template <class T,
            std::enable_if_t<std::is_same<T, std::string>::value, bool> = false>
  static Value make(T data) {
    return Value(TypeId::VARCHAR, DataStoreT(data));
  }

  bool eq(CRef<Value> other) const;
  bool ne(CRef<Value> other) const;
  bool lt(CRef<Value> other) const;
  bool gt(CRef<Value> other) const;

  bool lte(CRef<Value> other) const;
  bool gte(CRef<Value> other) const;

  Value add(CRef<Value> other) const;
  Value subtract(CRef<Value> other) const;
  Value multiply(CRef<Value> other) const;
  Value divide(CRef<Value> other) const;

  Value min(const Value& other) const;
  Value max(const Value& other) const;

  DataStoreT data() {
    return data_;
  }

  Value(TypeId type_id, DataStoreT data)
    : ValueBase(type_id, data) {}
};

template char* Value::as<char*>() const;
