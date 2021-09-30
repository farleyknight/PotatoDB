#pragma once

#include "tuple/tuple.hpp"

class ResultSet {
public:
  ResultSet(QuerySchema query_schema)
    : query_schema_  (query_schema) {}

  ~ResultSet() = default;
  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet&
  operator=(const ResultSet&) = delete;

  void
  emplace_back(Tuple&& tuple) {
    tuple_results_.emplace_back(move(tuple));
  }

  // TODO: Let's start moving away from using strings and instead use column OIDs
  template<typename T>
  T
  value(const column_name_t name,
        const Tuple& tuple)
  {
    auto column_index = schema_.column_index_for(name);
    auto value        = schema_.layout().value_by_index(tuple, column_index);
    return value.as<T>();
  }

  template<typename T>
  T value_at(const column_name_t name,
             int32_t tuple_index)
  {
    assert(size() >= tuple_index + 1);
    auto column_index = schema_.column_index_for(name);
    const auto &tuple = results_[tuple_index];
    const auto value  = schema_.layout().value_by_index(tuple, column_index);
    return value.as<T>();
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
    return tuple_results_[i];
  }

  const QuerySchema&
  schema() const {
    return schema_;
  }

  // NOTE: This method is different from ordinary `to_string`
  // In particular, it's formatted to be sent over the network to the client
  // Which means quoting strings, rendering boolean types to 'true'/'false'
  //
  // Likely more to this, but this explains the difference.
  const string
  to_payload() {
    stringstream os;

    for (index_t i = 0; i < tuple_results_.size(); ++i) {
      if (i > 0) {
        os << ",\n";
      }
      os << schema_.layout().to_payload(results_[i]);
    }

    return os.str();
  }

private:
  const QuerySchema schema_;
  const vector<Tuple> results_;
};
