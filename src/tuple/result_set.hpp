#pragma once

#include "tuple/tuple.hpp"

class ResultSet {
public:
  ResultSet(QuerySchema query_schema)
    : query_schema_  (query_schema) {}

  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet& operator=(const ResultSet&) = delete;
  ~ResultSet() = default;

  void
  emplace_back(Tuple&& tuple) {
    tuple_results_.emplace_back(move(tuple));
  }

  // TODO: Let's start moving away from using strings and instead use column OIDs
  template<typename T>
  T value(const column_name_t name, const Tuple& tuple) {
    auto column_index = query_schema_.column_index_for(name);
    auto value = query_schema_.layout().value_by_column_index(tuple, column_index);
    return value.as<T>();
  }

  template<typename T>
  T value_at(const column_name_t name, int32_t tuple_index) {
    assert(size() >= tuple_index + 1);
    auto column_index = query_schema_.column_index_for(name);
    auto value = query_schema_.layout().value_by_column_index(tuple_results_[tuple_index],
                                                        column_index);
    return value.as<T>();
  }

  const vector<Tuple>&
  results() {
    return tuple_results_;
  }

  int32_t
  size() {
    return tuple_results_.size();
  }

  const Tuple&
  operator[](int32_t i) const {
    return tuple_results_[i];
  }

  const QuerySchema&
  schema() const {
    return query_schema_;
  }

  // NOTE: This method is different from ordinary `to_string`
  // In particular, it's formatted to be sent over the network to the client
  // Which means quoting strings, rendering boolean types to 'true'/'false'
  //
  // Likely more to this, but this explains the difference.
  const string to_payload() const {
    stringstream os;

    for (index_t i = 0; i < tuple_results_.size(); ++i) {
      if (i > 0) {
        os << ",\n";
      }
      os << query_schema_.layout().to_payload(tuple_results_[i]);
    }

    return os.str();
  }

private:
  QuerySchema query_schema_;
  vector<Tuple> tuple_results_;
};
