#pragma once

#include "catalog/schema_ref.hpp"

class ResultSet {
public:
  ResultSet()
    : schema_ (QuerySchema::empty())
  {}

  ResultSet(MoveVec<Tuple> results, QuerySchema schema)
    : schema_  (schema),
      results_ (move(results)) {}

  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet& operator=(const ResultSet&) = delete;
  ~ResultSet() = default;

  static ptr<ResultSet> empty() {
    return make_unique<ResultSet>();
  }

  /**********************************************
   * Instance methods
   **********************************************/

  template<typename T>
  T value(const string name, const Tuple& tuple) {
    return tuple.value(schema_, schema_.index_for(name)).as<T>();
  }

  template<typename T>
  T value_at(const string name, size_t index) {
    assert(results_.size() >= index + 1);
    return results_[index].value(schema_, schema_.index_for(name)).as<T>();
  }

  const vector<Tuple>& results() {
    return results_;
  }

  size_t size() {
    return results_.size();
  }

  string to_string() {
    // TODO: Send this back to the client in a structured way
    return "<a result set should appear here>";
  }

private:
  QuerySchema schema_;
  vector<Tuple> results_;
};
