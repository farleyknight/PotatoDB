#pragma once

#include "value/any_value.hpp"

template<typename StoreT = AnyValue>
class ValueBase {
public:
  using StoreClass = StoreT;
  using DataStoreT = typename StoreT::store_t;

  TypeId type_id() {
    return type_id_;
  }
protected:
  ValueBase(TypeId type_id, DataStoreT data)
    : type_id_ (type_id),
      data_    (data) {}


  TypeId type_id_;
  DataStoreT data_;

  // TODO: If we want to be REALLY convervative w/ memory,
  // we could possibly combine this flag with the TypeId
  // using some kind of bit masking.
  // Not sure if it's necessary at the moment, but just
  // wanted to make note of that here.
  bool is_null_ = false;
};
