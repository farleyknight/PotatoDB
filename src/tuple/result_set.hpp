#pragma once

#include "tuple/tuple.hpp"

class ResultSet {
public:
  ResultSet(TupleLayout layout)
    : layout_  (layout) {}

  ~ResultSet() = default;
  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet&
  operator=(const ResultSet&) = delete;

  void
  emplace_back(Tuple&& tuple) {
    results_.emplace_back(move(tuple));
  }

  // NOTE: If you catch a part of the unit tests using column_name_t for this method
  // try using the method on the main PotatoDB object:
  //
  // column_oid_t PotatoDB::column_oid_for(column_name_t name)
  template<typename T>
  T
  value(column_oid_t oid,
        const Tuple& tuple)
  {
    return layout_.value_by_oid(tuple, oid).as<T>();
  }

  // NOTE: If you catch a part of the unit tests using column_name_t for this method
  // try using the method on the main PotatoDB object:
  //
  // column_oid_t PotatoDB::column_oid_for(column_name_t name)
  template<typename T>
  T
  value_at(column_oid_t oid,
           int32_t tuple_index)
  {
    assert(size() >= tuple_index + 1);
    const auto &tuple = results_[tuple_index];
    return layout_.value_by_oid(tuple, oid).as<T>();
  }

  const vector<Tuple>&
  results() {
    return results_;
  }

  int32_t
  size() {
    return results_.size();
  }

  const Tuple&
  operator[](int32_t i) const {
    return results_[i];
  }

  // NOTE: This method is different from ordinary `to_string`
  // In particular, it's formatted to be sent over the network to the client
  // Which means quoting strings, rendering boolean types to 'true'/'false'
  //
  // Likely more to this, but this explains the difference.
  const string
  to_payload() {
    stringstream os;

    for (index_t i = 0; i < results_.size(); ++i) {
      if (i > 0) {
        os << ",\n";
      }
      os << layout_.to_payload(results_[i]);
    }

    return os.str();
  }

private:
  TupleLayout layout_;
  vector<Tuple> results_;
};
