#pragma once

#include "tuple/tuple.hpp"

class ResultSet {
public:
  ResultSet(const vector<Tuple>&& results,
            QuerySchema schema)
    : schema_  (schema),
      results_ (move(results)) {}

  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet& operator=(const ResultSet&) = delete;
  ~ResultSet() = default;

  template<typename T>
  T value(const string name, const Tuple& tuple) {
    return tuple.value_by_index(schema_, schema_.column_index_for(name)).as<T>();
  }

  template<typename T>
  T value_at(const string name, int32_t index) {
    assert(size() >= index + 1);
    return results_[index].value_by_index(schema_,
                                          schema_.column_index_for(name)).as<T>();
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

  const QuerySchema&
  schema() const {
    return schema_;
  }

  // NOTE: This method is different from ordinary `to_string`
  // In particular, it's formatted to be sent over the network to the client
  // Which means quoting strings, rendering boolean types to 'true'/'false'
  //
  // Likely more to this, but this explains the difference.
  const string to_payload() {
    stringstream os;

    for (index_t i = 0; i < results_.size(); ++i) {
      if (i > 0) {
        os << ",\n";
      }
      os << results_[i].to_payload(schema_);
    }

    return os.str();
  }

private:
  QuerySchema schema_;
  const vector<Tuple> results_;
};
